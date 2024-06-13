// Copyright 2024 Miles Ramage
// SPDX-License-Identifier: GPL-2.0-or-later
//
#pragma once

#include "quantum.h"
#include "mcp23018.h"

// Public Functions
void mcp23018_encoder_read(void);
void mcp23018_encoder_init(void);

// Preprocessor Directives
#define MCP23018_1_ADDR 0x20 // LEFT-HAND
#define MCP23018_2_ADDR 0x27 // RIGHT-HAND

#define MCP23018_1_A0 0b00000001
#define MCP23018_1_A1 0b00000010
#define MCP23018_1_A2 0b00000100
#define MCP23018_1_A3 0b00001000
#define MCP23018_1_A4 0b00010000
#define MCP23018_1_A5 0b00100000
#define MCP23018_1_A6 0b01000000
#define MCP23018_1_A7 0b10000000

#define MCP23018_1_B0 0b00000001
#define MCP23018_1_B1 0b00000010
#define MCP23018_1_B2 0b00000100
#define MCP23018_1_B3 0b00001000
#define MCP23018_1_B4 0b00010000
#define MCP23018_1_B5 0b00100000
#define MCP23018_1_B6 0b01000000
#define MCP23018_1_B7 0b10000000

#define MCP23018_2_A0 0b00000001
#define MCP23018_2_A1 0b00000010
#define MCP23018_2_A2 0b00000100
#define MCP23018_2_A3 0b00001000
#define MCP23018_2_A4 0b00010000
#define MCP23018_2_A5 0b00100000
#define MCP23018_2_A6 0b01000000
#define MCP23018_2_A7 0b10000000

#define MCP23018_2_B0 0b00000001
#define MCP23018_2_B1 0b00000010
#define MCP23018_2_B2 0b00000100
#define MCP23018_2_B3 0b00001000
#define MCP23018_2_B4 0b00010000
#define MCP23018_2_B5 0b00100000
#define MCP23018_2_B6 0b01000000
#define MCP23018_2_B7 0b10000000

// LEFT-HAND SIDE
#define ROW_0_PIN       MCP23018_1_A3
#define ROW_1_PIN       MCP23018_1_A2
#define ROW_2_PIN       MCP23018_1_A1
#define ROW_3_PIN       MCP23018_1_A0
#define ROW_PINS_LEFT   (ROW_0_PIN | ROW_1_PIN | ROW_2_PIN | ROW_3_PIN)

#define COL_0L_PIN      MCP23018_1_B0
#define COL_1L_PIN      MCP23018_1_B1
#define COL_2L_PIN      MCP23018_1_B2
#define COL_3L_PIN      MCP23018_1_B3
#define COL_PINS_LEFT   (COL_0L_PIN | COL_1L_PIN | COL_2L_PIN | COL_3L_PIN)

// RIGHT-HAND SIDE
#define ROW_4_PIN       MCP23018_2_A3
#define ROW_5_PIN       MCP23018_2_A2
#define ROW_6_PIN       MCP23018_2_A1
#define ROW_7_PIN       MCP23018_2_A0
#define ROW_PINS_RIGHT  (ROW_4_PIN | ROW_5_PIN | ROW_6_PIN | ROW_7_PIN)

#define COL_0R_PIN       MCP23018_2_B0
#define COL_1R_PIN       MCP23018_2_B1
#define COL_2R_PIN       MCP23018_2_B2
#define COL_3R_PIN       MCP23018_2_B3
#define COL_PINS_RIGHT  (COL_0R_PIN | COL_1R_PIN | COL_2R_PIN | COL_3R_PIN)

#define ENCODER_CW  MCP23018_2_A6
#define ENCODER_CCW MCP23018_2_A7

// --- Define rows -------------------------------------
typedef struct {
    uint8_t i2c_addr;
    mcp23018_port_t port;
    uint8_t row_pos;
    uint8_t col_pins;
} matrix_row_pos_t;

// C4 C3 C2 C1 R1 R2 R3 R4 (indicated on board)
// R4 R3 R2 R1 C4 C3 C2 C1 (looking sideways)
// input: 1 / output: 0
static const matrix_row_pos_t ergognome_matrix_rows[MATRIX_ROWS] = {
    { MCP23018_1_ADDR, mcp23018_PORTA, ROW_0_PIN, COL_PINS_LEFT },  // row 0
    { MCP23018_1_ADDR, mcp23018_PORTA, ROW_1_PIN, COL_PINS_LEFT },  // row 1
    { MCP23018_1_ADDR, mcp23018_PORTA, ROW_2_PIN, COL_PINS_LEFT },  // row 2
    { MCP23018_1_ADDR, mcp23018_PORTA, ROW_3_PIN, COL_PINS_LEFT },  // row 3
    { MCP23018_2_ADDR, mcp23018_PORTA, ROW_4_PIN, COL_PINS_RIGHT }, // row 4
    { MCP23018_2_ADDR, mcp23018_PORTA, ROW_5_PIN, COL_PINS_RIGHT }, // row 5
    { MCP23018_2_ADDR, mcp23018_PORTA, ROW_6_PIN, COL_PINS_RIGHT }, // row 6
    { MCP23018_2_ADDR, mcp23018_PORTA, ROW_7_PIN, COL_PINS_RIGHT }  // row 7
};


// --- Define columns ----------------------------------
//typedef struct {
//    uint8_t i2c_addr;
//    mcp23018_port_t port;
//    uint8_t col_pins;
//} matrix_col_t;

//static const uint8_t ergognome_matrix_col_pins[MATRIX_COLS] = {
//    0b00000001,
//    0b00000010,
//    0b00000100,
//    0b00001000,
//};

//static const matrix_col_t ergognome_matrix_cols[MATRIX_ROWS] = {
//    { MCP23018_ADDR_1, mcp23018_PORTB, 0b00001111 }, // row 0
//    { MCP23018_ADDR_1, mcp23018_PORTB, 0b00001111 }, // row 1
//    { MCP23018_ADDR_1, mcp23018_PORTB, 0b00001111 }, // row 2
//    { MCP23018_ADDR_1, mcp23018_PORTB, 0b00001111 }, // row 3
//    //{ MCP23018_ADDR_2, mcp23018_PORTB, 0b00001111 }, // row 4
//    //{ MCP23018_ADDR_2, mcp23018_PORTB, 0b00001111 }, // row 5
//    //{ MCP23018_ADDR_2, mcp23018_PORTB, 0b00001111 }, // row 6
//    //{ MCP23018_ADDR_2, mcp23018_PORTB, 0b00001111 }  // row 7
//};
