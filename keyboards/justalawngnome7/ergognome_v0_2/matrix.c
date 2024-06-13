// Copyright 2024 Miles Ramage
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ergognome_v0_2.h"
//#include "mcp23018.h"
//#include "matrix.h"
//#include "wait.h"
//#include "debug.h"

static uint8_t mcp23018_errors = 0;

static void mcp23018_init_cols(void) {
    mcp23018_errors += !mcp23018_set_config(MCP23018_1_ADDR, mcp23018_PORTA, ALL_INPUT);
    mcp23018_errors += !mcp23018_set_config(MCP23018_1_ADDR, mcp23018_PORTB, ALL_INPUT);
    mcp23018_errors += !mcp23018_set_config(MCP23018_2_ADDR, mcp23018_PORTA, ALL_INPUT);
    mcp23018_errors += !mcp23018_set_config(MCP23018_2_ADDR, mcp23018_PORTB, ALL_INPUT);

    //mcp23018_errors += !mcp23018_set_config(I2C_ADDR, mcp23018_PORTB, 0b01100000);

    //mcp23018_errors += !mcp23018_set_config(MCP23018_1_ADDR, mcp23018_PORTA, 0b11111111);
    //mcp23018_errors += !mcp23018_set_config(MCP23018_1_ADDR, mcp23018_PORTB, 0b11110000);
    //mcp23018_errors += !mcp23018_set_config(MCP23018_2_ADDR, mcp23018_PORTA, 0b11111111);
    //mcp23018_errors += !mcp23018_set_config(MCP23018_2_ADDR, mcp23018_PORTB, 0b11110000);
}

static void mcp23018_scan(void) {
    if (!mcp23018_errors) {
        return;
    }

    static uint16_t mcp23018_reset_loop = 0;
    if (++mcp23018_reset_loop > 0x1FFF) {
        // tuned to about 5s given the current scan rate
        dprintf("trying to reset mcp23018\n");
        mcp23018_reset_loop = 0;
        mcp23018_errors     = 0;
        mcp23018_init_cols();

#ifdef ENCODER_ENABLE
        mcp23018_encoder_init();
#endif
    }
}

static matrix_row_t read_cols(uint8_t current_row) {
    if (mcp23018_errors) {
        return 0;
    }

    uint8_t ret = 0xFF; // sets all to 1
    matrix_row_pos_t row_pos = ergognome_matrix_rows[current_row];

    // ret = 0b11111110
    // col_pins = 0b00001111
    mcp23018_errors += !mcp23018_readPins(row_pos.i2c_addr, mcp23018_PORTB, &ret);

    return (~ret) & row_pos.col_pins;
}

static void select_row(uint8_t row) {
    if (mcp23018_errors) {
        // wait to mimic i2c interactions
        //wait_us(100);
        return;
    }

    matrix_row_pos_t row_pos = ergognome_matrix_rows[row];
    mcp23018_set_config(row_pos.i2c_addr, row_pos.port, ~(row_pos.row_pos));

    //matrix_row_pos_t row_pos = ergognome_matrix_rows[row];
    //mcp23018_errors += !mcp23018_set_output(row_pos.i2c_addr, row_pos.port, ~(row_pos.row_pos) & 0b00001111);
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selection to stabilize
    select_row(current_row);
    // Skip the wait_us(30); as i2c is slow enough to debounce the io changes

    current_matrix[current_row] = read_cols(current_row);

    return (last_row_value != current_matrix[current_row]);
}

void matrix_init_custom(void) {
    mcp23018_init(MCP23018_1_ADDR);
    mcp23018_init(MCP23018_2_ADDR);
    mcp23018_init_cols();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    mcp23018_scan();

    bool changed = false;
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        changed |= read_cols_on_row(current_matrix, current_row);
    }

#ifdef ENCODER_ENABLE
    mcp23018_encoder_read();
#endif

    return changed;
}
