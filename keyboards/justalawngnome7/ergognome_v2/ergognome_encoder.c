// Copyright 2024 Miles Ramage
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ergognome_v2.h"
#include "debug.h"

#define ENCODER_PINS                (ENCODER_PIN_A | ENCODER_PIN_B)
#define ENCODER_RESOLUTION          4
#define ENCODER_CLOCKWISE           true
#define ENCODER_COUNTER_CLOCKWISE   false

static int8_t encoder_LUT[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
static uint8_t encoder_state  = 0;
static int8_t  encoder_pulses = 0;

static uint8_t mcp23018_errors = 0;

static bool encoder_read_state(uint8_t *state) {
    uint8_t ret = 0xFF; // sets all to 1
    mcp23018_errors += !mcp23018_readPins(MCP23018_2_ADDR, mcp23018_PORTA, &ret);

    if (mcp23018_errors) {
        return false;
    }

    *state = ((~ret) & ENCODER_PINS) >> 6;
    return true;
}

static bool encoder_update(int8_t index, uint8_t state) {
    // Return false if no encoder pulse change was detected.
    int8_t encoder_pulse_change = encoder_LUT[state & 0xF];
    if (encoder_pulse_change == 0) {
        return false;
    }

    //// Check for encoder direction changes to avoid an encoder "deadzone" (e.g., turning the
    //// encoder 1 detent CCW with a "pulses" value of 3 causes the firmware to miss the change,
    //// because 3 minus 4 equals -1, which doesn't fall outside of -4 and 4.)
    //bool encoder_changed_direction = ((encoder_pulses > 0) != (encoder_pulse_change > 0));
    //if (encoder_changed_direction)  {
    //    // Reset encoder pulses if they changed direction...
    //    encoder_pulses = encoder_pulse_change;
    //} else {
    //    // ...otherwise, add the pulse change to the encoder pulses.
    //    encoder_pulses += encoder_pulse_change;
    //}

    // Determine if the encoder has moved sufficiently to update the encoder.
    encoder_pulses += encoder_pulse_change;
    if (encoder_pulses >= ENCODER_RESOLUTION) {
        encoder_update_kb(index, ENCODER_CLOCKWISE);
    }
    if (encoder_pulses <= -ENCODER_RESOLUTION) {  // direction is arbitrary here, but this clockwise
        encoder_update_kb(index, ENCODER_COUNTER_CLOCKWISE);
    }
    encoder_pulses %= ENCODER_RESOLUTION;

    // Notify the caller of the pulse change.
    return true;
}

// Read the encoder over i2c
bool encoder_read_MCP23018(void) {
    uint8_t state;
    if (!encoder_read_state(&state)) {
        return false;
    }

    encoder_state <<= 2;
    encoder_state |= state;
    bool changed = encoder_update(1, encoder_state);
    return changed;
}

// Initialize the encoder over i2c
void encoder_init_MCP23018(void) {
    encoder_read_state(&encoder_state);
}
