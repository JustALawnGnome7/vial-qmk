// Copyright 2023 Kyle McCreery
// SPDX-License-Identifier: GPL-2.0-or-later

#include "matrix.h"
#include "mcp23018.h"
#include "wait.h"
#include "debug.h"
#include "encoder.h"

#define I2C_ADDR_1 0x20 // LEFT-HAND
#define I2C_ADDR_2 0x27 // RIGHT-HAND

// C4 C3 C2 C1 R1 R2 R3 R4 (indicated on board)
// R4 R3 R2 R1 C4 C3 C2 C1 (looking sideways)
// input: 1 / output: 0
//              | ----------------- LEFT-HAND ----------------- | ----------------- RIGHT-HAND ----------------- |
#define ROW_POS { 0b00010000, 0b00100000, 0b01000000, 0b10000000, 0b00010000, 0b00100000, 0b01000000, 0b10000000 }

static uint8_t mcp23018_errors = 0;

static void mcp23018_init_cols(void) {
    mcp23018_errors += !mcp23018_set_config(I2C_ADDR_1, mcp23018_PORTA, ALL_INPUT);
    mcp23018_errors += !mcp23018_set_config(I2C_ADDR_1, mcp23018_PORTB, ALL_INPUT);
    mcp23018_errors += !mcp23018_set_config(I2C_ADDR_2, mcp23018_PORTA, ALL_INPUT);
    mcp23018_errors += !mcp23018_set_config(I2C_ADDR_2, mcp23018_PORTB, ALL_INPUT);
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
    }
}

//static matrix_row_t read_cols(void) {
static matrix_row_t read_cols(uint8_t current_row) {
    if (mcp23018_errors) {
        return 0;
    }

    uint8_t ret = 0xFF; // sets all to 1
    if (current_row < 4) {
        mcp23018_errors += !mcp23018_readPins(I2C_ADDR_1, mcp23018_PORTB, &ret); // will update with values 0 = pulled down by connection, 1 = pulled up by pullup resistors
    } else {
        mcp23018_errors += !mcp23018_readPins(I2C_ADDR_2, mcp23018_PORTB, &ret);
    }

    return (~ret) & 0b00001111; // Clears out the row bits.
}

static void select_row(uint8_t row) {
    uint8_t row_pos[MATRIX_ROWS] = ROW_POS;
    if (mcp23018_errors) {
        // wait to mimic i2c interactions
        //wait_us(100);
        return;
    }

    if (row < 4) {
        mcp23018_set_config(I2C_ADDR_1, mcp23018_PORTB, ~(row_pos[row]));
    } else {
        mcp23018_set_config(I2C_ADDR_2, mcp23018_PORTB, ~(row_pos[row]));
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selection to stabilize
    select_row(current_row);
    // Skip the wait_us(30); as i2c is slow enough to debounce the io changes

    //current_matrix[current_row] = read_cols();
    current_matrix[current_row] = read_cols(current_row);

    return (last_row_value != current_matrix[current_row]);
}

void matrix_init_custom(void) {
    mcp23018_init(I2C_ADDR_1);
    mcp23018_init(I2C_ADDR_2);
    mcp23018_init_cols();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    mcp23018_scan();

    bool changed = false;
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        changed |= read_cols_on_row(current_matrix, current_row);

#ifdef ENCODER_ENABLE
    encoder_read();
#endif
    }
    return changed;
}
