/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/*
    "eeprom": {
        "driver": "i2c"
    },
        "cols": ["B0", "B1", "B2", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B12", "B13", "B14"],
        "rows": ["A0", "A1", "A4", "A6", "A7", "A8", "A9", "A10", "A11"]
*/

// I2C setup
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4
#define I2C1_CLOCK_SPEED 100000

#define IS31FL3741_I2C_ADDRESS_1 IS31FL3741_I2C_ADDRESS_GND
#define IS31FL3741_I2C_ADDRESS_2 IS31FL3741_I2C_ADDRESS_SCL


// From: acheron apollo 87h
// RGB Matrix defines
//#define IS31FL3741_I2C_ADDRESS_1 IS31FL3741_I2C_ADDRESS_GND

//#define DRIVER_1_LED_TOTAL 126

//#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
//#define RGB_MATRIX_KEYPRESSES
//#define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
