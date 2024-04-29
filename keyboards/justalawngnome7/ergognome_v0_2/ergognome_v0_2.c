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
    // LEFT SIDE
    // First row                        // Num / Key
    {0,  CS3_SW1,  CS2_SW1, CS1_SW1  }, //   0   ESC
    {0,  CS5_SW1,  CS4_SW1, CS6_SW1  }, //   1   F1
    {0,  CS9_SW1,  CS8_SW1, CS7_SW1  }, //   2   F2
    {0, CS11_SW1, CS10_SW1, CS12_SW1 }, //   3   F3
    {0, CS15_SW1, CS14_SW1, CS13_SW1 }, //   4   F4
    {0, CS17_SW1, CS16_SW1, CS18_SW1 }, //   5   F5
    {0, CS21_SW1, CS20_SW1, CS19_SW1 }, //   6   F6
    {0, CS23_SW1, CS22_SW1, CS24_SW1 }, //   7   F7
    {0, CS27_SW1, CS26_SW1, CS25_SW1 }, //   8   F8
    {0, CS29_SW1, CS28_SW1, CS30_SW1 }, //   9   F9
    {0, CS33_SW1, CS32_SW1, CS31_SW1 }, //  10   F10
    {0, CS35_SW1, CS34_SW1, CS36_SW1 }, //  11   F11
    {0, CS38_SW1, CS37_SW1, CS39_SW1 }, //  12   F12
    // Second row
    {0,  CS3_SW6,  CS2_SW6, CS1_SW6  }, //  13   `
    {0,  CS5_SW6,  CS4_SW6, CS6_SW6  }, //  14   1
    {0,  CS9_SW6,  CS8_SW6, CS7_SW6  }, //  15   2
    {0, CS11_SW6, CS10_SW6, CS12_SW6 }, //  16   3
    {0, CS15_SW6, CS14_SW6, CS13_SW6 }, //  17   4
    {0, CS17_SW6, CS16_SW6, CS18_SW6 }, //  18   5
    {0, CS21_SW6, CS20_SW6, CS19_SW6 }, //  19   6
    {0, CS23_SW6, CS22_SW6, CS24_SW6 }, //  20   7
    {0, CS27_SW6, CS26_SW6, CS25_SW6 }, //  21   8
    {0, CS29_SW6, CS28_SW6, CS30_SW6 }, //  22   9
    {0, CS33_SW6, CS32_SW6, CS31_SW6 }, //  23   0
    {0, CS35_SW6, CS34_SW6, CS36_SW6 }, //  24   -
    {0, CS38_SW6, CS37_SW6, CS39_SW6 }, //  25   =
    // Third row
    {0,  CS3_SW5,  CS2_SW5, CS1_SW5  }, //  26
    {0,  CS5_SW5,  CS4_SW5, CS6_SW5  }, //  27
    {0,  CS9_SW5,  CS8_SW5, CS7_SW5  }, //  28
    {0, CS11_SW5, CS10_SW5, CS12_SW5 }, //  29
    {0, CS15_SW5, CS14_SW5, CS13_SW5 }, //  30
    {0, CS17_SW5, CS16_SW5, CS18_SW5 }, //  31
    {0, CS21_SW5, CS20_SW5, CS19_SW5 }, //  32
    {0, CS23_SW5, CS22_SW5, CS24_SW5 }, //  33
    {0, CS27_SW5, CS26_SW5, CS25_SW5 }, //  34
    {0, CS29_SW5, CS28_SW5, CS30_SW5 }, //  35
    {0, CS33_SW5, CS32_SW5, CS31_SW5 }, //  36
    {0, CS35_SW5, CS34_SW5, CS36_SW5 }, //  37
    {0, CS38_SW5, CS37_SW5, CS39_SW5 }, //  38
    // Fourth row
    {0,  CS3_SW4,  CS2_SW4, CS1_SW4  }, //  39
    {0,  CS5_SW4,  CS4_SW4, CS6_SW4  }, //  40
    {0,  CS9_SW4,  CS8_SW4, CS7_SW4  }, //  41
    {0, CS11_SW4, CS10_SW4, CS12_SW4 }, //  42
    {0, CS15_SW4, CS14_SW4, CS13_SW4 }, //  43
    {0, CS17_SW4, CS16_SW4, CS18_SW4 }, //  44
    {0, CS21_SW4, CS20_SW4, CS19_SW4 }, //  45
    {0, CS23_SW4, CS22_SW4, CS24_SW4 }, //  46
    {0, CS27_SW4, CS26_SW4, CS25_SW4 }, //  47
    {0, CS29_SW4, CS28_SW4, CS30_SW4 }, //  48
    {0, CS33_SW4, CS32_SW4, CS31_SW4 }, //  49
    {0, CS35_SW4, CS34_SW4, CS36_SW4 }, //  50
    {0, CS38_SW4, CS37_SW4, CS39_SW4 }, //  51
    // Fifth row
    {0,  CS3_SW3,  CS2_SW3, CS1_SW3  }, //  52
    {0,  CS5_SW3,  CS4_SW3, CS6_SW3  }, //  53
    {0,  CS9_SW3,  CS8_SW3, CS7_SW3  }, //  54
    {0, CS11_SW3, CS10_SW3, CS12_SW3 }, //  55
    {0, CS15_SW3, CS14_SW3, CS13_SW3 }, //  56
    {0, CS17_SW3, CS16_SW3, CS18_SW3 }, //  57
    {0, CS21_SW3, CS20_SW3, CS19_SW3 }, //  58
    {0, CS23_SW3, CS22_SW3, CS24_SW3 }, //  59
    {0, CS27_SW3, CS26_SW3, CS25_SW3 }, //  60
    {0, CS29_SW3, CS28_SW3, CS30_SW3 }, //  61
    {0, CS33_SW3, CS32_SW3, CS31_SW3 }, //  62
    {0, CS35_SW3, CS34_SW3, CS36_SW3 }, //  63
    {0, CS38_SW3, CS37_SW3, CS39_SW3 }, //  64
    // Sixth row
    {0,  CS3_SW2,  CS2_SW2, CS1_SW2  }, //  65
    {0,  CS5_SW2,  CS4_SW2, CS6_SW2  }, //  66
    {0,  CS9_SW2,  CS8_SW2, CS7_SW2  }, //  67
    {0, CS11_SW2, CS10_SW2, CS12_SW2 }, //  68
    {0, CS15_SW2, CS14_SW2, CS13_SW2 }, //  69
    {0, CS17_SW2, CS16_SW2, CS18_SW2 }, //  70
    {0, CS21_SW2, CS20_SW2, CS19_SW2 }, //  71
    {0, CS23_SW2, CS22_SW2, CS24_SW2 }, //  72
    {0, CS27_SW2, CS26_SW2, CS25_SW2 }, //  73
    {0, CS29_SW2, CS28_SW2, CS30_SW2 }, //  74
    {0, CS33_SW2, CS32_SW2, CS31_SW2 }, //  75
    {0, CS35_SW2, CS34_SW2, CS36_SW2 }, //  76
    {0, CS38_SW2, CS37_SW2, CS39_SW2 }, //  77
    // Seventh row
    {0,  CS3_SW1,  CS2_SW1, CS1_SW1  }, //  78
    {0,  CS5_SW1,  CS4_SW1, CS6_SW1  }, //  79
    {0,  CS9_SW1,  CS8_SW1, CS7_SW1  }, //  80
    {0, CS11_SW1, CS10_SW1, CS12_SW1 }, //  81
    {0, CS15_SW1, CS14_SW1, CS13_SW1 }, //  82
    {0, CS17_SW1, CS16_SW1, CS18_SW1 }, //  83
    {0, CS21_SW1, CS20_SW1, CS19_SW1 }, //  84
    {0, CS23_SW1, CS22_SW1, CS24_SW1 }, //  85
    {0, CS27_SW1, CS26_SW1, CS25_SW1 }, //  86
    {0, CS29_SW1, CS28_SW1, CS30_SW1 }, //  87
    {0, CS33_SW1, CS32_SW1, CS31_SW1 }, //  88
    {0, CS35_SW1, CS34_SW1, CS36_SW1 }, //  89
    {0, CS38_SW1, CS37_SW1, CS39_SW1 }, //  90
    // Eighth row
    {0,  CS3_SW8,  CS2_SW8, CS1_SW8  }, //  91
    {0,  CS5_SW8,  CS4_SW8, CS6_SW8  }, //  92
    {0,  CS9_SW8,  CS8_SW8, CS7_SW8  }, //  93
    {0, CS11_SW8, CS10_SW8, CS12_SW8 }, //  94
    {0, CS15_SW8, CS14_SW8, CS13_SW8 }, //  95
    {0, CS17_SW8, CS16_SW8, CS18_SW8 }, //  96
    {0, CS21_SW8, CS20_SW8, CS19_SW8 }, //  97
    {0, CS23_SW8, CS22_SW8, CS24_SW8 }, //  98
    {0, CS27_SW8, CS26_SW8, CS25_SW8 }, //  99
    {0, CS29_SW8, CS28_SW8, CS30_SW8 }, // 100
    {0, CS33_SW8, CS32_SW8, CS31_SW8 }, // 101
    {0, CS35_SW8, CS34_SW8, CS36_SW8 }, // 102
    {0, CS38_SW8, CS37_SW8, CS39_SW8 }, // 103
    // Ninth row
    {0,  CS3_SW7,  CS2_SW7, CS1_SW7  }, // 104
    {0,  CS5_SW7,  CS4_SW7, CS6_SW7  }, // 105
    {0,  CS9_SW7,  CS8_SW7, CS7_SW7  }, // 106
    {0, CS11_SW7, CS10_SW7, CS12_SW7 }, // 107
    {0, CS15_SW7, CS14_SW7, CS13_SW7 }, // 108
    {0, CS17_SW7, CS16_SW7, CS18_SW7 }, // 109
    {0, CS21_SW7, CS20_SW7, CS19_SW7 }, // 110
    {0, CS23_SW7, CS22_SW7, CS24_SW7 }, // 111
    {0, CS27_SW7, CS26_SW7, CS25_SW7 }, // 112
    {0, CS29_SW7, CS28_SW7, CS30_SW7 }, // 113
    {0, CS33_SW7, CS32_SW7, CS31_SW7 }, // 114
    {0, CS35_SW7, CS34_SW7, CS36_SW7 }, // 115
    {0, CS38_SW7, CS37_SW7, CS39_SW7 }, // 116
    // RIGHT SIDE
    //// First row                        // Num / Key
    //{1,  CS3_SW1,  CS2_SW1, CS1_SW1  }, // 117
    //{1,  CS5_SW1,  CS4_SW1, CS6_SW1  }, // 118
    //{1,  CS9_SW1,  CS8_SW1, CS7_SW1  }, // 119
    //{1, CS11_SW1, CS10_SW1, CS12_SW1 }, // 120
    //{1, CS15_SW1, CS14_SW1, CS13_SW1 }, // 121
    //{1, CS17_SW1, CS16_SW1, CS18_SW1 }, // 122
    //{1, CS21_SW1, CS20_SW1, CS19_SW1 }, // 123
    //{1, CS23_SW1, CS22_SW1, CS24_SW1 }, // 124
    //{1, CS27_SW1, CS26_SW1, CS25_SW1 }, // 125
    //{1, CS29_SW1, CS28_SW1, CS30_SW1 }, // 126
    //{1, CS33_SW1, CS32_SW1, CS31_SW1 }, // 127
    //{1, CS35_SW1, CS34_SW1, CS36_SW1 }, // 128
    //{1, CS38_SW1, CS37_SW1, CS39_SW1 }, // 129
    //{1,  CS3_SW6,  CS2_SW6, CS1_SW6  }, // 130
    //{1,  CS5_SW6,  CS4_SW6, CS6_SW6  }, // 131
    //{1,  CS9_SW6,  CS8_SW6, CS7_SW6  }, // 132
    //{1, CS11_SW6, CS10_SW6, CS12_SW6 }, // 133
    //{1, CS15_SW6, CS14_SW6, CS13_SW6 }, // 134
    //{1, CS17_SW6, CS16_SW6, CS18_SW6 }, // 135
    //{1, CS21_SW6, CS20_SW6, CS19_SW6 }, // 136
    //{1, CS23_SW6, CS22_SW6, CS24_SW6 }, // 137
    //{1, CS27_SW6, CS26_SW6, CS25_SW6 }, // 138
    //{1, CS29_SW6, CS28_SW6, CS30_SW6 }, // 139
    //{1, CS33_SW6, CS32_SW6, CS31_SW6 }, // 140
    //{1, CS35_SW6, CS34_SW6, CS36_SW6 }, // 141
    //{1, CS38_SW6, CS37_SW6, CS39_SW6 }, // 142
    //{1,  CS3_SW5,  CS2_SW5, CS1_SW5  }, // 143
    //{1,  CS5_SW5,  CS4_SW5, CS6_SW5  }, // 144
    //{1,  CS9_SW5,  CS8_SW5, CS7_SW5  }, // 145
    //{1, CS11_SW5, CS10_SW5, CS12_SW5 }, // 146
    //{1, CS15_SW5, CS14_SW5, CS13_SW5 }, // 147
    //{1, CS17_SW5, CS16_SW5, CS18_SW5 }, // 148
    //{1, CS21_SW5, CS20_SW5, CS19_SW5 }, // 149
    //{1, CS23_SW5, CS22_SW5, CS24_SW5 }, // 150
    //{1, CS27_SW5, CS26_SW5, CS25_SW5 }, // 151
    //{1, CS29_SW5, CS28_SW5, CS30_SW5 }, // 152
    //{1, CS33_SW5, CS32_SW5, CS31_SW5 }, // 153
    //{1, CS35_SW5, CS34_SW5, CS36_SW5 }, // 154
    //{1, CS38_SW5, CS37_SW5, CS39_SW5 }, // 155
    //{1,  CS3_SW4,  CS2_SW4, CS1_SW4  }, // 156
    //{1,  CS5_SW4,  CS4_SW4, CS6_SW4  }, // 157
    //{1,  CS9_SW4,  CS8_SW4, CS7_SW4  }, // 158
    //{1, CS11_SW4, CS10_SW4, CS12_SW4 }, // 159
    //{1, CS15_SW4, CS14_SW4, CS13_SW4 }, // 160
    //{1, CS17_SW4, CS16_SW4, CS18_SW4 }, // 161
    //{1, CS21_SW4, CS20_SW4, CS19_SW4 }, // 162
    //{1, CS23_SW4, CS22_SW4, CS24_SW4 }, // 163
    //{1, CS27_SW4, CS26_SW4, CS25_SW4 }, // 164
    //{1, CS29_SW4, CS28_SW4, CS30_SW4 }, // 165
    //{1, CS33_SW4, CS32_SW4, CS31_SW4 }, // 166
    //{1, CS35_SW4, CS34_SW4, CS36_SW4 }, // 167
    //{1, CS38_SW4, CS37_SW4, CS39_SW4 }, // 168
    //{1,  CS3_SW3,  CS2_SW3, CS1_SW3  }, // 169
    //{1,  CS5_SW3,  CS4_SW3, CS6_SW3  }, // 170
    //{1,  CS9_SW3,  CS8_SW3, CS7_SW3  }, // 171
    //{1, CS11_SW3, CS10_SW3, CS12_SW3 }, // 172
    //{1, CS15_SW3, CS14_SW3, CS13_SW3 }, // 173
    //{1, CS17_SW3, CS16_SW3, CS18_SW3 }, // 174
    //{1, CS21_SW3, CS20_SW3, CS19_SW3 }, // 175
    //{1, CS23_SW3, CS22_SW3, CS24_SW3 }, // 176
    //{1, CS27_SW3, CS26_SW3, CS25_SW3 }, // 177
    //{1, CS29_SW3, CS28_SW3, CS30_SW3 }, // 178
    //{1, CS33_SW3, CS32_SW3, CS31_SW3 }, // 179
    //{1, CS35_SW3, CS34_SW3, CS36_SW3 }, // 180
    //{1, CS38_SW3, CS37_SW3, CS39_SW3 }, // 181
    //{1,  CS3_SW2,  CS2_SW2, CS1_SW2  }, // 182
    //{1,  CS5_SW2,  CS4_SW2, CS6_SW2  }, // 183
    //{1,  CS9_SW2,  CS8_SW2, CS7_SW2  }, // 184
    //{1, CS11_SW2, CS10_SW2, CS12_SW2 }, // 185
    //{1, CS15_SW2, CS14_SW2, CS13_SW2 }, // 186
    //{1, CS17_SW2, CS16_SW2, CS18_SW2 }, // 187
    //{1, CS21_SW2, CS20_SW2, CS19_SW2 }, // 188
    //{1, CS23_SW2, CS22_SW2, CS24_SW2 }, // 189
    //{1, CS27_SW2, CS26_SW2, CS25_SW2 }, // 190
    //{1, CS29_SW2, CS28_SW2, CS30_SW2 }, // 191
    //{1, CS33_SW2, CS32_SW2, CS31_SW2 }, // 192
    //{1, CS35_SW2, CS34_SW2, CS36_SW2 }, // 193
    //{1, CS38_SW2, CS37_SW2, CS39_SW2 }, // 194
    //{1,  CS3_SW1,  CS2_SW1, CS1_SW1  }, // 195
    //{1,  CS5_SW1,  CS4_SW1, CS6_SW1  }, // 196
    //{1,  CS9_SW1,  CS8_SW1, CS7_SW1  }, // 197
    //{1, CS11_SW1, CS10_SW1, CS12_SW1 }, // 198
    //{1, CS15_SW1, CS14_SW1, CS13_SW1 }, // 199
    //{1, CS17_SW1, CS16_SW1, CS18_SW1 }, // 200
    //{1, CS21_SW1, CS20_SW1, CS19_SW1 }, // 201
    //{1, CS23_SW1, CS22_SW1, CS24_SW1 }, // 202
    //{1, CS27_SW1, CS26_SW1, CS25_SW1 }, // 203
    //{1, CS29_SW1, CS28_SW1, CS30_SW1 }, // 204
    //{1, CS33_SW1, CS32_SW1, CS31_SW1 }, // 205
    //{1, CS35_SW1, CS34_SW1, CS36_SW1 }, // 206
    //{1, CS38_SW1, CS37_SW1, CS39_SW1 }, // 207
    //{1,  CS3_SW8,  CS2_SW8, CS1_SW8  }, // 208
    //{1,  CS5_SW8,  CS4_SW8, CS6_SW8  }, // 209
    //{1,  CS9_SW8,  CS8_SW8, CS7_SW8  }, // 210
    //{1, CS11_SW8, CS10_SW8, CS12_SW8 }, // 211
    //{1, CS15_SW8, CS14_SW8, CS13_SW8 }, // 212
    //{1, CS17_SW8, CS16_SW8, CS18_SW8 }, // 213
    //{1, CS21_SW8, CS20_SW8, CS19_SW8 }, // 214
    //{1, CS23_SW8, CS22_SW8, CS24_SW8 }, // 215
    //{1, CS27_SW8, CS26_SW8, CS25_SW8 }, // 216
    //{1, CS29_SW8, CS28_SW8, CS30_SW8 }, // 217
    //{1, CS33_SW8, CS32_SW8, CS31_SW8 }, // 218
    //{1, CS35_SW8, CS34_SW8, CS36_SW8 }, // 219
    //{1, CS38_SW8, CS37_SW8, CS39_SW8 }, // 220
    //{1,  CS3_SW7,  CS2_SW7, CS1_SW7  }, // 221
    //{1,  CS5_SW7,  CS4_SW7, CS6_SW7  }, // 222
    //{1,  CS9_SW7,  CS8_SW7, CS7_SW7  }, // 223
    //{1, CS11_SW7, CS10_SW7, CS12_SW7 }, // 224
    //{1, CS15_SW7, CS14_SW7, CS13_SW7 }, // 225
    //{1, CS17_SW7, CS16_SW7, CS18_SW7 }, // 226
    //{1, CS21_SW7, CS20_SW7, CS19_SW7 }, // 227
    //{1, CS23_SW7, CS22_SW7, CS24_SW7 }, // 228
    //{1, CS27_SW7, CS26_SW7, CS25_SW7 }, // 229
    //{1, CS29_SW7, CS28_SW7, CS30_SW7 }, // 230
    //{1, CS33_SW7, CS32_SW7, CS31_SW7 }, // 231
    //{1, CS35_SW7, CS34_SW7, CS36_SW7 }, // 232
    //{1, CS38_SW7, CS37_SW7, CS39_SW7 }, // 233
};
#endif
