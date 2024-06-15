// Copyright 2024 Miles Ramage
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ergognome_v0_2.h"

// Optimize scanning code for speed as a slight mitigation for the port expander
#pragma GCC push_options
#pragma GCC optimize("-O3")

static uint16_t mcp23018_reset_loop = 0;
static uint8_t  mcp23018_errors     = 0;

static void init_pins_MCP23018(void) { // 0: output (row), 1: input (col)
    mcp23018_errors += !mcp23018_set_config(MCP23018_1_ADDR, mcp23018_PORTA, 0b11110000);
    mcp23018_errors += !mcp23018_set_config(MCP23018_1_ADDR, mcp23018_PORTB, 0b11111111);
    mcp23018_errors += !mcp23018_set_config(MCP23018_2_ADDR, mcp23018_PORTA, 0b11110000);
    mcp23018_errors += !mcp23018_set_config(MCP23018_2_ADDR, mcp23018_PORTB, 0b11111111);
}

static uint8_t read_cols_MCP23018(uint8_t current_row) {
    matrix_row_config_t row = matrix_row_configs[current_row];
    uint8_t tmp = 0xFF;
    mcp23018_errors += !mcp23018_readPins(row.i2c_addr, mcp23018_PORTB, &tmp);

    return (~tmp) & row.col_pins; // col_pins: 0b00001111
}

static bool read_cols_on_row_MCP23018(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Select the matrix row...
    matrix_row_config_t row = matrix_row_configs[current_row];
    mcp23018_errors += !mcp23018_set_output(row.i2c_addr, row.port, ~(row.pin)); // port: mcp23018_PORTA

    // ...and read its column data.
    matrix_row_t current_row_value = read_cols_MCP23018(current_row);

    if (last_row_value == current_row_value) {
        return false;
    }

    current_matrix[current_row] = current_row_value;
    return true;
}

//____CUSTOM MATRIX___________________________________________________________________

void matrix_init_custom(void) {
    mcp23018_init(MCP23018_1_ADDR);
    mcp23018_init(MCP23018_2_ADDR);
    init_pins_MCP23018();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    if (mcp23018_errors) {
        if (++mcp23018_reset_loop > 0x7FFF) {
            // tuned to about 5s given the current scan rate
            print("trying to reset mcp23018\n");
            mcp23018_reset_loop = 0;
            mcp23018_errors     = 0;
            init_pins_MCP23018();

            #ifdef ENCODER_ENABLE
            mcp23018_encoder_init();
            #endif
        }
        return changed;
    }

    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        changed |= read_cols_on_row_MCP23018(current_matrix, current_row);
    }

    #ifdef ENCODER_ENABLE
    mcp23018_encoder_read();
    #endif

    return changed;
}
#pragma GCC pop_options
