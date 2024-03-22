/*
Copyright 2024 JustALawnGnome7

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { E6, B7, D0, D1, D2, D3 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, D5, C7, C6, B6, B5, B4, D7, D6, D4 }
#define DIODE_DIRECTION COL2ROW

#define WS2812_DI_PIN B0

/* RGB Matrix settings (preferred over "RGB Lighting" if possible) */
#if defined(RGB_MATRIX_ENABLE)
  #define RGB_MATRIX_LED_COUNT 84
  #define RGB_MATRIX_SLEEP // turn off effects when suspended
  #define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
  #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 175

  #define RGB_MATRIX_DEFAULT_ON true
  #define RGB_MATRIX_DEFAULT_HUE 43
  #define RGB_MATRIX_DEFAULT_SAT 0
  #define RGB_MATRIX_DEFAULT_SPD 64

  /* Enable RGB Matrix effects */
  //#define ENABLE_RGB_MATRIX_ALPHAS_MODS
  //#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  //#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_BREATHING
  //#define ENABLE_RGB_MATRIX_BAND_SAT
  //#define ENABLE_RGB_MATRIX_BAND_VAL
  //#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  //#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  //#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  //#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  //#define ENABLE_RGB_MATRIX_CYCLE_ALL
  //#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  //#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
  //#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  //#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
  //#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  //#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
  //#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
  //#define ENABLE_RGB_MATRIX_DUAL_BEACON
  //#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
  #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  //#define ENABLE_RGB_MATRIX_FLOWER_BLOOMING
  //#define ENABLE_RGB_MATRIX_RAINDROPS
  //#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
  //#define ENABLE_RGB_MATRIX_HUE_BREATHING
  //#define ENABLE_RGB_MATRIX_HUE_PENDULUM
  //#define ENABLE_RGB_MATRIX_HUE_WAVE
  //#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
  //#define ENABLE_RGB_MATRIX_PIXEL_FLOW
  //#define ENABLE_RGB_MATRIX_PIXEL_RAIN
  //#define ENABLE_RGB_MATRIX_STARLIGHT
  //#define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
  //#define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
  //#define ENABLE_RGB_MATRIX_RIVERFLOW

/* RGB Lighting settings */
#elif defined(RGBLIGHT_ENABLE)
  #define RGBLED_NUM 84
  #define RGBLIGHT_LED_MAP { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83 }
  #define RGBLIGHT_SLEEP /* RGB lighting will be switched off when the host goes to sleep */
  #define RGBLIGHT_LIMIT_VAL 175 // OK: 183, ERROR: 185 (crashes the keyboard on Asus laptop)

  /* Default to use upon clearing the EEPROM */
  #define RGBLIGHT_DEFAULT_ON true
  #define RGBLIGHT_DEFAULT_HUE 43
  #define RGBLIGHT_DEFAULT_SAT 0
  #define RGBLIGHT_DEFAULT_SPD 64

  /* Step values for moving up/down */
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8

  /* choose RGB animations */
  #define RGBLIGHT_EFFECT_ALTERNATING
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_RGB_TEST
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_TWINKLE
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is userful for the Windows task manager shortcut (ctrl+shift+esc).
 */
// #define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Magic Key Options
 *
 * Magic keys are hotkey commands that allow control over firmware functions of
 * the keyboard. They are best used in combination with the HID Listen program,
 * found here: https://www.pjrc.com/teensy/hid_listen.html
 *
 * The options below allow the magic key functionality to be changed. This is
 * useful if your keyboard/keypad is missing keys and you want magic key support.
 *
 */

/* key combination for magic key command */
/* defined by default; to change, uncomment and set to the combination you want */
// #define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))

/* control how magic key switches layers */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM false

/* override magic key keymap */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM
//#define MAGIC_KEY_HELP           H
//#define MAGIC_KEY_HELP_ALT       SLASH
//#define MAGIC_KEY_DEBUG          D
//#define MAGIC_KEY_DEBUG_MATRIX   X
//#define MAGIC_KEY_DEBUG_KBD      K
//#define MAGIC_KEY_DEBUG_MOUSE    M
//#define MAGIC_KEY_VERSION        V
//#define MAGIC_KEY_STATUS         S
//#define MAGIC_KEY_CONSOLE        C
//#define MAGIC_KEY_LAYER0         0
//#define MAGIC_KEY_LAYER0_ALT     GRAVE
//#define MAGIC_KEY_LAYER1         1
//#define MAGIC_KEY_LAYER2         2
//#define MAGIC_KEY_LAYER3         3
//#define MAGIC_KEY_LAYER4         4
//#define MAGIC_KEY_LAYER5         5
//#define MAGIC_KEY_LAYER6         6
//#define MAGIC_KEY_LAYER7         7
//#define MAGIC_KEY_LAYER8         8
//#define MAGIC_KEY_LAYER9         9
//#define MAGIC_KEY_BOOTLOADER     B
//#define MAGIC_KEY_BOOTLOADER_ALT ESC
//#define MAGIC_KEY_LOCK           CAPS
//#define MAGIC_KEY_EEPROM         E
//#define MAGIC_KEY_EEPROM_CLEAR   BSPACE
//#define MAGIC_KEY_NKRO           N
//#define MAGIC_KEY_SLEEP_LED      Z

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/
//#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 1
