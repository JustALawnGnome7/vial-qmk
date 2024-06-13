// Copyright 2024 Miles Ramage
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ergognome_v0_2.h"
//#include "mcp23018.h"
//#include "encoder.h"
#include "debug.h"

#define MCP23018_2_ADDR 0x27 // RIGHT-HAND
#define MCP23018_2_A6 0b01000000
#define MCP23018_2_A7 0b10000000

#define ENCODER_CW  MCP23018_2_A6
#define ENCODER_CCW MCP23018_2_A7
#define ENCODER_PINS (ENCODER_CW | ENCODER_CCW)

#ifndef ENCODER_RESOLUTION
#    define ENCODER_RESOLUTION 4
#endif

static uint8_t mcp23018_errors = 0;

#define ENCODER_CLOCKWISE true
#define ENCODER_COUNTER_CLOCKWISE false

static int8_t encoder_LUT[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

static uint8_t encoder_state  = 0;
static int8_t  encoder_pulses = 0;

//const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)           },
//    [1] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
//    [2] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)           },
//    [3] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)           },
//};

__attribute__((weak)) extern const uint16_t PROGMEM encoder_keymaps[][2][2];

const uint16_t encoder_default[NUM_ENCODERS][2] =  { { KC_VOLD, KC_VOLU } };

// Tap on encoder updates using the encoder keymap
bool encoder_update_kb(uint8_t index, bool clockwise) {
    // if (!encoder_update_user(index, clockwise)) return false;

    uint16_t code;

    if (encoder_keymaps) {
      uint8_t layer = get_highest_layer(layer_state);
      do {
          code = pgm_read_word(&encoder_keymaps[layer--][index][clockwise]);
      } while (code == KC_TRNS);
    } else {
      code = encoder_default[index][clockwise];
    }

    tap_code16(code);
    return true;
}

static bool encoder_read_state(uint8_t *state) {
    //uint8_t mcp23018_pin_state;
    //mcp23018_status_t status = mcp23018_readReg(GPIOB, &mcp23018_pin_state, 1);
    //if (status == 0) {
    //    *state = (mcp23018_pin_state & 0b110000) >> 4;
    //    return true;
    //}
    //return false;

    uint8_t ret = 0xFF; // sets all to 1
    mcp23018_errors += !mcp23018_readPins(MCP23018_2_ADDR, mcp23018_PORTA, &ret);

    if (mcp23018_errors) {
        return false;
    }

    *state = ((~ret) & ENCODER_PINS) >> 6;
    return true;
}

static void encoder_update(int8_t index, uint8_t state) {
    encoder_pulses += encoder_LUT[state & 0xF];
    if (encoder_pulses >= ENCODER_RESOLUTION) {
        encoder_update_kb(index, ENCODER_CLOCKWISE);
    }
    if (encoder_pulses <= -ENCODER_RESOLUTION) {  // direction is arbitrary here, but this clockwise
        encoder_update_kb(index, ENCODER_COUNTER_CLOCKWISE);
    }
    encoder_pulses %= ENCODER_RESOLUTION;
}

// Read the encoder over i2c
void mcp23018_encoder_read(void) {
    uint8_t state;
    if (encoder_read_state(&state)) {
        encoder_state <<= 2;
        encoder_state |= state;
        encoder_update(1, encoder_state);
    }
}

// Initialize the encoder over i2c
void mcp23018_encoder_init(void) {
    encoder_read_state(&encoder_state);
}
