/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS_LEFT 4
#define MATRIX_COLS_RIGHT 4
#define MATRIX_COLS 4

// I2C setup
#define I2C_DRIVER          I2CD1
#define I2C1_SCL_PIN        B6
#define I2C1_SDA_PIN        B7
#define I2C1_SCL_PAL_MODE   4
#define I2C1_SDA_PAL_MODE   4
#define I2C1_CLOCK_SPEED    400000
#define I2C1_DUTY_CYCLE     FAST_DUTY_CYCLE_2

#define IS31FL3741_I2C_ADDRESS_1 IS31FL3741_I2C_ADDRESS_GND
#define IS31FL3741_I2C_ADDRESS_2 IS31FL3741_I2C_ADDRESS_SCL

#define EEPROM_I2C_24LC256
#define EXTERNAL_EEPROM_WP_PIN B5
