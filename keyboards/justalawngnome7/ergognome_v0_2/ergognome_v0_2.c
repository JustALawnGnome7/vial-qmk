/* Copyright 2024 JustALawnGnome7 <miles.ramage@yahoo.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
const is31fl3741_led_t PROGMEM g_is31fl3741_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |         G location
 *   |  |         |         B location
 *   |  |         |         | */
// First row
    {0, CS3_SW1 , CS2_SW1 , CS1_SW1  }, //ESC    0
    {0, CS6_SW1 , CS5_SW1 , CS4_SW1  }, //F1     1
    {0, CS9_SW1 , CS8_SW1 , CS7_SW1  }, //F2     2
    {0, CS12_SW1, CS11_SW1, CS10_SW1 }, //F3     3
    {0, CS15_SW1, CS14_SW1, CS13_SW1 }, //F4     4
    {0, CS18_SW1, CS17_SW1, CS16_SW1 }, //F5     5
    {0, CS21_SW1, CS20_SW1, CS19_SW1 }, //F6     6
    {0, CS24_SW1, CS23_SW1, CS22_SW1 }, //F7     7
    {0, CS27_SW1, CS26_SW1, CS25_SW1 }, //F8     8
    {0, CS30_SW1, CS29_SW1, CS28_SW1 }, //F9     9
    {0, CS33_SW1, CS32_SW1, CS31_SW1 }, //F10    10
    {0, CS36_SW1, CS35_SW1, CS34_SW1 }, //F11    11
    {0, CS39_SW1, CS38_SW1, CS37_SW1 }, //F12    12
//Second row
    {0, CS3_SW2 , CS2_SW2 , CS1_SW2  }, // 13
    {0, CS6_SW2 , CS5_SW2 , CS4_SW2  }, // 14
    {0, CS9_SW2 , CS8_SW2 , CS7_SW2  }, // 15
    {0, CS12_SW2, CS11_SW2, CS10_SW2 }, // 16
    {0, CS15_SW2, CS14_SW2, CS13_SW2 }, // 17
    {0, CS18_SW2, CS17_SW2, CS16_SW2 }, // 18
    {0, CS21_SW2, CS20_SW2, CS19_SW2 }, // 19
    {0, CS24_SW2, CS23_SW2, CS22_SW2 }, // 20
    {0, CS27_SW2, CS26_SW2, CS25_SW2 }, // 21
    {0, CS30_SW2, CS29_SW2, CS28_SW2 }, // 22
    {0, CS33_SW2, CS32_SW2, CS31_SW2 }, // 23
    {0, CS36_SW2, CS35_SW2, CS34_SW2 }, // 24
    {0, CS39_SW2, CS38_SW2, CS37_SW2 }, // 25
//Third row
    {0, CS3_SW3 , CS2_SW3 , CS1_SW3  }, // 26
    {0, CS6_SW3 , CS5_SW3 , CS4_SW3  }, // 27
    {0, CS9_SW3 , CS8_SW3 , CS7_SW3  }, // 28
    {0, CS12_SW3, CS11_SW3, CS10_SW3 }, // 29
    {0, CS15_SW3, CS14_SW3, CS13_SW3 }, // 30
    {0, CS18_SW3, CS17_SW3, CS16_SW3 }, // 31
    {0, CS21_SW3, CS20_SW3, CS19_SW3 }, // 32
    {0, CS24_SW3, CS23_SW3, CS22_SW3 }, // 33
    {0, CS27_SW3, CS26_SW3, CS25_SW3 }, // 34
    {0, CS30_SW3, CS29_SW3, CS28_SW3 }, // 35
    {0, CS33_SW3, CS32_SW3, CS31_SW3 }, // 36
    {0, CS36_SW3, CS35_SW3, CS34_SW3 }, // 37
    {0, CS39_SW3, CS38_SW3, CS37_SW3 }, // 38
//Fourth row
    {0, CS3_SW4 , CS2_SW4 , CS1_SW4  }, // 39
    {0, CS6_SW4 , CS5_SW4 , CS4_SW4  }, // 40
    {0, CS9_SW4 , CS8_SW4 , CS7_SW4  }, // 41
    {0, CS12_SW4, CS11_SW4, CS10_SW4 }, // 42
    {0, CS15_SW4, CS14_SW4, CS13_SW4 }, // 43
    {0, CS18_SW4, CS17_SW4, CS16_SW4 }, // 44
    {0, CS21_SW4, CS20_SW4, CS19_SW4 }, // 45
    {0, CS24_SW4, CS23_SW4, CS22_SW4 }, // 46
    {0, CS27_SW4, CS26_SW4, CS25_SW4 }, // 47
    {0, CS30_SW4, CS29_SW4, CS28_SW4 }, // 48
    {0, CS33_SW4, CS32_SW4, CS31_SW4 }, // 49
    {0, CS36_SW4, CS35_SW4, CS34_SW4 }, // 50
    {0, CS39_SW4, CS38_SW4, CS37_SW4 }, // 51
//Fifth row
    {0, CS3_SW5 , CS2_SW5 , CS1_SW5  }, // 52
    {0, CS6_SW5 , CS5_SW5 , CS4_SW5  }, // 53
    {0, CS9_SW5 , CS8_SW5 , CS7_SW5  }, // 54
    {0, CS12_SW5, CS11_SW5, CS10_SW5 }, // 55
    {0, CS15_SW5, CS14_SW5, CS13_SW5 }, // 56
    {0, CS18_SW5, CS17_SW5, CS16_SW5 }, // 57
    {0, CS21_SW5, CS20_SW5, CS19_SW5 }, // 58
    {0, CS24_SW5, CS23_SW5, CS22_SW5 }, // 59
    {0, CS27_SW5, CS26_SW5, CS25_SW5 }, // 60
    {0, CS30_SW5, CS29_SW5, CS28_SW5 }, // 61
    {0, CS33_SW5, CS32_SW5, CS31_SW5 }, // 62
    {0, CS36_SW5, CS35_SW5, CS34_SW5 }, // 63
    {0, CS39_SW5, CS38_SW5, CS37_SW5 }, // 64
//Sixth row
    {0, CS3_SW6 , CS2_SW6 , CS1_SW6  }, // 65
    {0, CS6_SW6 , CS5_SW6 , CS4_SW6  }, // 66
    {0, CS9_SW6 , CS8_SW6 , CS7_SW6  }, // 67
    {0, CS12_SW6, CS11_SW6, CS10_SW6 }, // 68
    {0, CS15_SW6, CS14_SW6, CS13_SW6 }, // 69
    {0, CS18_SW6, CS17_SW6, CS16_SW6 }, // 70
    {0, CS21_SW6, CS20_SW6, CS19_SW6 }, // 71
    {0, CS24_SW6, CS23_SW6, CS22_SW6 }, // 72
    {0, CS27_SW6, CS26_SW6, CS25_SW6 }, // 73
    {0, CS30_SW6, CS29_SW6, CS28_SW6 }, // 74
    {0, CS33_SW6, CS32_SW6, CS31_SW6 }, // 75
    {0, CS36_SW6, CS35_SW6, CS34_SW6 }, // 76
    {0, CS39_SW6, CS38_SW6, CS37_SW6 }, // 77
//Seventh row
    {0, CS3_SW7 , CS2_SW7 , CS1_SW7  }, // 78
    {0, CS6_SW7 , CS5_SW7 , CS4_SW7  }, // 79
    {0, CS9_SW7 , CS8_SW7 , CS7_SW7  }, // 80
    {0, CS12_SW7, CS11_SW7, CS10_SW7 }, // 81
    {0, CS15_SW7, CS14_SW7, CS13_SW7 }, // 82
    {0, CS18_SW7, CS17_SW7, CS16_SW7 }, // 83
    {0, CS21_SW7, CS20_SW7, CS19_SW7 }, // 84
    {0, CS24_SW7, CS23_SW7, CS22_SW7 }, // 85
    {0, CS27_SW7, CS26_SW7, CS25_SW7 }, // 86
    {0, CS30_SW7, CS29_SW7, CS28_SW7 }, // 87
    {0, CS33_SW7, CS32_SW7, CS31_SW7 }, // 88
    {0, CS36_SW7, CS35_SW7, CS34_SW7 }, // 89
    {0, CS39_SW7, CS38_SW7, CS37_SW7 }, // 90
//Eighth row
    {0, CS3_SW8 , CS2_SW8 , CS1_SW8  }, // 91
    {0, CS6_SW8 , CS5_SW8 , CS4_SW8  }, // 92
    {0, CS9_SW8 , CS8_SW8 , CS7_SW8  }, // 93
    {0, CS12_SW8, CS11_SW8, CS10_SW8 }, // 94
    {0, CS15_SW8, CS14_SW8, CS13_SW8 }, // 95
    {0, CS18_SW8, CS17_SW8, CS16_SW8 }, // 96
    {0, CS21_SW8, CS20_SW8, CS19_SW8 }, // 97
    {0, CS24_SW8, CS23_SW8, CS22_SW8 }, // 98
    {0, CS27_SW8, CS26_SW8, CS25_SW8 }, // 99
    {0, CS30_SW8, CS29_SW8, CS28_SW8 }, // 100
    {0, CS33_SW8, CS32_SW8, CS31_SW8 }, // 101
    {0, CS36_SW8, CS35_SW8, CS34_SW8 }, // 102
    {0, CS39_SW8, CS38_SW8, CS37_SW8 }, // 103
//Ninth row
    {0, CS3_SW9 , CS2_SW9 , CS1_SW9  }, // 104
    {0, CS6_SW9 , CS5_SW9 , CS4_SW9  }, // 105
    {0, CS9_SW9 , CS8_SW9 , CS7_SW9  }, // 106
    {0, CS12_SW9, CS11_SW9, CS10_SW9 }, // 107
    {0, CS15_SW9, CS14_SW9, CS13_SW9 }, // 108
    {0, CS18_SW9, CS17_SW9, CS16_SW9 }, // 109
    {0, CS21_SW9, CS20_SW9, CS19_SW9 }, // 110
    {0, CS24_SW9, CS23_SW9, CS22_SW9 }, // 111
    {0, CS27_SW9, CS26_SW9, CS25_SW9 }, // 112
    {0, CS30_SW9, CS29_SW9, CS28_SW9 }, // 113
    {0, CS33_SW9, CS32_SW9, CS31_SW9 }, // 114
    {0, CS36_SW9, CS35_SW9, CS34_SW9 }, // 115
    {0, CS39_SW9, CS38_SW9, CS37_SW9 }, // 116
};

led_config_t g_led_config = { {
    {   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12 },
    {  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25 },
    {  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38 },
    {  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51 },
    {  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,  64 },
    {  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77 },
    {  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,  88,  89,  90 },
    {  91,  92,  93,  94,  95,  96,  97,  98,  99, 100, 101, 102, 103 },
    { 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116 }
},{
    {  0,  0}, { 19,  0}, { 38,  0}, { 56,  0}, { 75,  0}, { 94,  0}, {113,  0}, {131,  0}, {150,  0}, {169,  0}, {188,  0}, {206,  0}, {225,  0},
    {  0,  8}, { 19,  8}, { 38,  8}, { 56,  8}, { 75,  8}, { 94,  8}, {113,  8}, {131,  8}, {150,  8}, {169,  8}, {188,  8}, {206,  8}, {225,  8},
    {  0, 16}, { 19, 16}, { 38, 16}, { 56, 16}, { 75, 16}, { 94, 16}, {113, 16}, {131, 16}, {150, 16}, {169, 16}, {188, 16}, {206, 16}, {225, 16},
    {  0, 24}, { 19, 24}, { 38, 24}, { 56, 24}, { 75, 24}, { 94, 24}, {113, 24}, {131, 24}, {150, 24}, {169, 24}, {188, 24}, {206, 24}, {225, 24},
    {  0, 32}, { 19, 32}, { 38, 32}, { 56, 32}, { 75, 32}, { 94, 32}, {113, 32}, {131, 32}, {150, 32}, {169, 32}, {188, 32}, {206, 32}, {225, 32},
    {  0, 40}, { 19, 40}, { 38, 40}, { 56, 40}, { 75, 40}, { 94, 40}, {113, 40}, {131, 40}, {150, 40}, {169, 40}, {188, 40}, {206, 40}, {225, 40},
    {  0, 48}, { 19, 48}, { 38, 48}, { 56, 48}, { 75, 48}, { 94, 48}, {113, 48}, {131, 48}, {150, 48}, {169, 48}, {188, 48}, {206, 48}, {225, 48},
    {  0, 56}, { 19, 56}, { 38, 56}, { 56, 56}, { 75, 56}, { 94, 56}, {113, 56}, {131, 56}, {150, 56}, {169, 56}, {188, 56}, {206, 56}, {225, 56},
    {  0, 64}, { 19, 64}, { 38, 64}, { 56, 64}, { 75, 64}, { 94, 64}, {113, 64}, {131, 64}, {150, 64}, {169, 64}, {188, 64}, {206, 64}, {225, 64}
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };
#endif
