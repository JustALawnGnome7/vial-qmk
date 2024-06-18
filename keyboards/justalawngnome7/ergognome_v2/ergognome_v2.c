// Copyright 2024 Miles Ramage <miles.ramage@yahoo.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ergognome_v2.h"

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
    {0,  CS3_SW9,  CS2_SW9, CS1_SW9  }, //   0   ESC
    {0,  CS5_SW9,  CS4_SW9, CS6_SW9  }, //   1   F1
    {0,  CS9_SW9,  CS8_SW9, CS7_SW9  }, //   2   F2
    {0, CS11_SW9, CS10_SW9, CS12_SW9 }, //   3   F3
    {0, CS15_SW9, CS14_SW9, CS13_SW9 }, //   4   F4
    {0, CS17_SW9, CS16_SW9, CS18_SW9 }, //   5   F5
    {0, CS21_SW9, CS20_SW9, CS19_SW9 }, //   6   F6
    {0, CS23_SW9, CS22_SW9, CS24_SW9 }, //   7   F7
    {0, CS27_SW9, CS26_SW9, CS25_SW9 }, //   8   F8
    {0, CS29_SW9, CS28_SW9, CS30_SW9 }, //   9   F9
    {0, CS33_SW9, CS32_SW9, CS31_SW9 }, //  10   F10
    {0, CS35_SW9, CS34_SW9, CS36_SW9 }, //  11   F11
    {0, CS38_SW9, CS37_SW9, CS39_SW9 }, //  12   F12
    {1,  CS3_SW9,  CS2_SW9, CS1_SW9  }, //  13
    {1,  CS5_SW9,  CS4_SW9, CS6_SW9  }, //  14
    {1,  CS9_SW9,  CS8_SW9, CS7_SW9  }, //  15
    {1, CS11_SW9, CS10_SW9, CS12_SW9 }, //  16
    {1, CS15_SW9, CS14_SW9, CS13_SW9 }, //  17
    {1, CS17_SW9, CS16_SW9, CS18_SW9 }, //  18
    {1, CS21_SW9, CS20_SW9, CS19_SW9 }, //  19
    {1, CS23_SW9, CS22_SW9, CS24_SW9 }, //  20
    {1, CS27_SW9, CS26_SW9, CS25_SW9 }, //  21
    {1, CS29_SW9, CS28_SW9, CS30_SW9 }, //  22
    {1, CS33_SW9, CS32_SW9, CS31_SW9 }, //  23
    {1, CS35_SW9, CS34_SW9, CS36_SW9 }, //  24
    {1, CS38_SW9, CS37_SW9, CS39_SW9 }, //  25
    // Second row
    {0,  CS3_SW6,  CS2_SW6, CS1_SW6  }, //  26   `
    {0,  CS5_SW6,  CS4_SW6, CS6_SW6  }, //  27   1
    {0,  CS9_SW6,  CS8_SW6, CS7_SW6  }, //  28   2
    {0, CS11_SW6, CS10_SW6, CS12_SW6 }, //  29   3
    {0, CS15_SW6, CS14_SW6, CS13_SW6 }, //  30   4
    {0, CS17_SW6, CS16_SW6, CS18_SW6 }, //  31   5
    {0, CS21_SW6, CS20_SW6, CS19_SW6 }, //  32   6
    {0, CS23_SW6, CS22_SW6, CS24_SW6 }, //  33   7
    {0, CS27_SW6, CS26_SW6, CS25_SW6 }, //  34   8
    {0, CS29_SW6, CS28_SW6, CS30_SW6 }, //  35   9
    {0, CS33_SW6, CS32_SW6, CS31_SW6 }, //  36   0
    {0, CS35_SW6, CS34_SW6, CS36_SW6 }, //  37   -
    {0, CS38_SW6, CS37_SW6, CS39_SW6 }, //  38   =
    {1,  CS3_SW6,  CS2_SW6, CS1_SW6  }, //  39
    {1,  CS5_SW6,  CS4_SW6, CS6_SW6  }, //  40
    {1,  CS9_SW6,  CS8_SW6, CS7_SW6  }, //  41
    {1, CS11_SW6, CS10_SW6, CS12_SW6 }, //  42
    {1, CS15_SW6, CS14_SW6, CS13_SW6 }, //  43
    {1, CS17_SW6, CS16_SW6, CS18_SW6 }, //  44
    {1, CS21_SW6, CS20_SW6, CS19_SW6 }, //  45
    {1, CS23_SW6, CS22_SW6, CS24_SW6 }, //  46
    {1, CS27_SW6, CS26_SW6, CS25_SW6 }, //  47
    {1, CS29_SW6, CS28_SW6, CS30_SW6 }, //  48
    {1, CS33_SW6, CS32_SW6, CS31_SW6 }, //  49
    {1, CS35_SW6, CS34_SW6, CS36_SW6 }, //  50
    {1, CS38_SW6, CS37_SW6, CS39_SW6 }, //  51
    // Third row
    {0,  CS3_SW5,  CS2_SW5, CS1_SW5  }, //  52
    {0,  CS5_SW5,  CS4_SW5, CS6_SW5  }, //  53
    {0,  CS9_SW5,  CS8_SW5, CS7_SW5  }, //  54
    {0, CS11_SW5, CS10_SW5, CS12_SW5 }, //  55
    {0, CS15_SW5, CS14_SW5, CS13_SW5 }, //  56
    {0, CS17_SW5, CS16_SW5, CS18_SW5 }, //  57
    {0, CS21_SW5, CS20_SW5, CS19_SW5 }, //  58
    {0, CS23_SW5, CS22_SW5, CS24_SW5 }, //  59
    {0, CS27_SW5, CS26_SW5, CS25_SW5 }, //  60
    {0, CS29_SW5, CS28_SW5, CS30_SW5 }, //  61
    {0, CS33_SW5, CS32_SW5, CS31_SW5 }, //  62
    {0, CS35_SW5, CS34_SW5, CS36_SW5 }, //  63
    {0, CS38_SW5, CS37_SW5, CS39_SW5 }, //  64
    {1,  CS3_SW5,  CS2_SW5, CS1_SW5  }, //  65
    {1,  CS5_SW5,  CS4_SW5, CS6_SW5  }, //  66
    {1,  CS9_SW5,  CS8_SW5, CS7_SW5  }, //  67
    {1, CS11_SW5, CS10_SW5, CS12_SW5 }, //  68
    {1, CS15_SW5, CS14_SW5, CS13_SW5 }, //  69
    {1, CS17_SW5, CS16_SW5, CS18_SW5 }, //  70
    {1, CS21_SW5, CS20_SW5, CS19_SW5 }, //  71
    {1, CS23_SW5, CS22_SW5, CS24_SW5 }, //  72
    {1, CS27_SW5, CS26_SW5, CS25_SW5 }, //  73
    {1, CS29_SW5, CS28_SW5, CS30_SW5 }, //  74
    {1, CS33_SW5, CS32_SW5, CS31_SW5 }, //  75
    {1, CS35_SW5, CS34_SW5, CS36_SW5 }, //  76
    {1, CS38_SW5, CS37_SW5, CS39_SW5 }, //  77
    // Fourth row
    {0,  CS3_SW4,  CS2_SW4, CS1_SW4  }, //  78
    {0,  CS5_SW4,  CS4_SW4, CS6_SW4  }, //  79
    {0,  CS9_SW4,  CS8_SW4, CS7_SW4  }, //  80
    {0, CS11_SW4, CS10_SW4, CS12_SW4 }, //  81
    {0, CS15_SW4, CS14_SW4, CS13_SW4 }, //  82
    {0, CS17_SW4, CS16_SW4, CS18_SW4 }, //  83
    {0, CS21_SW4, CS20_SW4, CS19_SW4 }, //  84
    {0, CS23_SW4, CS22_SW4, CS24_SW4 }, //  85
    {0, CS27_SW4, CS26_SW4, CS25_SW4 }, //  86
    {0, CS29_SW4, CS28_SW4, CS30_SW4 }, //  87
    {0, CS33_SW4, CS32_SW4, CS31_SW4 }, //  88
    {0, CS35_SW4, CS34_SW4, CS36_SW4 }, //  89
    {0, CS38_SW4, CS37_SW4, CS39_SW4 }, //  90
    {1,  CS3_SW4,  CS2_SW4, CS1_SW4  }, //  91
    {1,  CS5_SW4,  CS4_SW4, CS6_SW4  }, //  92
    {1,  CS9_SW4,  CS8_SW4, CS7_SW4  }, //  93
    {1, CS11_SW4, CS10_SW4, CS12_SW4 }, //  94
    {1, CS15_SW4, CS14_SW4, CS13_SW4 }, //  95
    {1, CS17_SW4, CS16_SW4, CS18_SW4 }, //  96
    {1, CS21_SW4, CS20_SW4, CS19_SW4 }, //  97
    {1, CS23_SW4, CS22_SW4, CS24_SW4 }, //  98
    {1, CS27_SW4, CS26_SW4, CS25_SW4 }, //  99
    {1, CS29_SW4, CS28_SW4, CS30_SW4 }, // 100
    {1, CS33_SW4, CS32_SW4, CS31_SW4 }, // 101
    {1, CS35_SW4, CS34_SW4, CS36_SW4 }, // 102
    {1, CS38_SW4, CS37_SW4, CS39_SW4 }, // 103
    // Fifth row
    {0,  CS3_SW3,  CS2_SW3, CS1_SW3  }, // 104
    {0,  CS5_SW3,  CS4_SW3, CS6_SW3  }, // 105
    {0,  CS9_SW3,  CS8_SW3, CS7_SW3  }, // 106
    {0, CS11_SW3, CS10_SW3, CS12_SW3 }, // 107
    {0, CS15_SW3, CS14_SW3, CS13_SW3 }, // 108
    {0, CS17_SW3, CS16_SW3, CS18_SW3 }, // 109
    {0, CS21_SW3, CS20_SW3, CS19_SW3 }, // 110
    {0, CS23_SW3, CS22_SW3, CS24_SW3 }, // 111
    {0, CS27_SW3, CS26_SW3, CS25_SW3 }, // 112
    {0, CS29_SW3, CS28_SW3, CS30_SW3 }, // 113
    {0, CS33_SW3, CS32_SW3, CS31_SW3 }, // 114
    {0, CS35_SW3, CS34_SW3, CS36_SW3 }, // 115
    {0, CS38_SW3, CS37_SW3, CS39_SW3 }, // 116
    {1,  CS3_SW3,  CS2_SW3, CS1_SW3  }, // 117
    {1,  CS5_SW3,  CS4_SW3, CS6_SW3  }, // 118
    {1,  CS9_SW3,  CS8_SW3, CS7_SW3  }, // 119
    {1, CS11_SW3, CS10_SW3, CS12_SW3 }, // 120
    {1, CS15_SW3, CS14_SW3, CS13_SW3 }, // 121
    {1, CS17_SW3, CS16_SW3, CS18_SW3 }, // 122
    {1, CS21_SW3, CS20_SW3, CS19_SW3 }, // 123
    {1, CS23_SW3, CS22_SW3, CS24_SW3 }, // 124
    {1, CS27_SW3, CS26_SW3, CS25_SW3 }, // 125
    {1, CS29_SW3, CS28_SW3, CS30_SW3 }, // 126
    {1, CS33_SW3, CS32_SW3, CS31_SW3 }, // 127
    {1, CS35_SW3, CS34_SW3, CS36_SW3 }, // 128
    {1, CS38_SW3, CS37_SW3, CS39_SW3 }, // 129
    // Sixth row
    {0,  CS3_SW2,  CS2_SW2, CS1_SW2  }, // 130
    {0,  CS5_SW2,  CS4_SW2, CS6_SW2  }, // 131
    {0,  CS9_SW2,  CS8_SW2, CS7_SW2  }, // 132
    {0, CS11_SW2, CS10_SW2, CS12_SW2 }, // 133
    {0, CS15_SW2, CS14_SW2, CS13_SW2 }, // 134
    {0, CS17_SW2, CS16_SW2, CS18_SW2 }, // 135
    {0, CS21_SW2, CS20_SW2, CS19_SW2 }, // 136
    {0, CS23_SW2, CS22_SW2, CS24_SW2 }, // 137
    {0, CS27_SW2, CS26_SW2, CS25_SW2 }, // 138
    {0, CS29_SW2, CS28_SW2, CS30_SW2 }, // 139
    {0, CS33_SW2, CS32_SW2, CS31_SW2 }, // 140
    {0, CS35_SW2, CS34_SW2, CS36_SW2 }, // 141
    {0, CS38_SW2, CS37_SW2, CS39_SW2 }, // 142
    {1,  CS3_SW2,  CS2_SW2, CS1_SW2  }, // 143
    {1,  CS5_SW2,  CS4_SW2, CS6_SW2  }, // 144
    {1,  CS9_SW2,  CS8_SW2, CS7_SW2  }, // 145
    {1, CS11_SW2, CS10_SW2, CS12_SW2 }, // 146
    {1, CS15_SW2, CS14_SW2, CS13_SW2 }, // 147
    {1, CS17_SW2, CS16_SW2, CS18_SW2 }, // 148
    {1, CS21_SW2, CS20_SW2, CS19_SW2 }, // 149
    {1, CS23_SW2, CS22_SW2, CS24_SW2 }, // 150
    {1, CS27_SW2, CS26_SW2, CS25_SW2 }, // 151
    {1, CS29_SW2, CS28_SW2, CS30_SW2 }, // 152
    {1, CS33_SW2, CS32_SW2, CS31_SW2 }, // 153
    {1, CS35_SW2, CS34_SW2, CS36_SW2 }, // 154
    {1, CS38_SW2, CS37_SW2, CS39_SW2 }, // 155
    // Seventh row
    {0,  CS3_SW1,  CS2_SW1, CS1_SW1  }, // 156
    {0,  CS5_SW1,  CS4_SW1, CS6_SW1  }, // 157
    {0,  CS9_SW1,  CS8_SW1, CS7_SW1  }, // 158
    {0, CS11_SW1, CS10_SW1, CS12_SW1 }, // 159
    {0, CS15_SW1, CS14_SW1, CS13_SW1 }, // 160
    {0, CS17_SW1, CS16_SW1, CS18_SW1 }, // 161
    {0, CS21_SW1, CS20_SW1, CS19_SW1 }, // 162
    {0, CS23_SW1, CS22_SW1, CS24_SW1 }, // 163
    {0, CS27_SW1, CS26_SW1, CS25_SW1 }, // 164
    {0, CS29_SW1, CS28_SW1, CS30_SW1 }, // 165
    {0, CS33_SW1, CS32_SW1, CS31_SW1 }, // 166
    {0, CS35_SW1, CS34_SW1, CS36_SW1 }, // 167
    {0, CS38_SW1, CS37_SW1, CS39_SW1 }, // 168
    {1,  CS3_SW1,  CS2_SW1, CS1_SW1  }, // 169
    {1,  CS5_SW1,  CS4_SW1, CS6_SW1  }, // 170
    {1,  CS9_SW1,  CS8_SW1, CS7_SW1  }, // 171
    {1, CS11_SW1, CS10_SW1, CS12_SW1 }, // 172
    {1, CS15_SW1, CS14_SW1, CS13_SW1 }, // 173
    {1, CS17_SW1, CS16_SW1, CS18_SW1 }, // 174
    {1, CS21_SW1, CS20_SW1, CS19_SW1 }, // 175
    {1, CS23_SW1, CS22_SW1, CS24_SW1 }, // 176
    {1, CS27_SW1, CS26_SW1, CS25_SW1 }, // 177
    {1, CS29_SW1, CS28_SW1, CS30_SW1 }, // 178
    {1, CS33_SW1, CS32_SW1, CS31_SW1 }, // 179
    {1, CS35_SW1, CS34_SW1, CS36_SW1 }, // 180
    {1, CS38_SW1, CS37_SW1, CS39_SW1 }, // 181
    // Eighth row
    {0,  CS3_SW8,  CS2_SW8, CS1_SW8  }, // 182
    {0,  CS5_SW8,  CS4_SW8, CS6_SW8  }, // 183
    {0,  CS9_SW8,  CS8_SW8, CS7_SW8  }, // 184
    {0, CS11_SW8, CS10_SW8, CS12_SW8 }, // 185
    {0, CS15_SW8, CS14_SW8, CS13_SW8 }, // 186
    {0, CS17_SW8, CS16_SW8, CS18_SW8 }, // 187
    {0, CS21_SW8, CS20_SW8, CS19_SW8 }, // 188
    {0, CS23_SW8, CS22_SW8, CS24_SW8 }, // 189
    {0, CS27_SW8, CS26_SW8, CS25_SW8 }, // 190
    {0, CS29_SW8, CS28_SW8, CS30_SW8 }, // 191
    {0, CS33_SW8, CS32_SW8, CS31_SW8 }, // 192
    {0, CS35_SW8, CS34_SW8, CS36_SW8 }, // 193
    {0, CS38_SW8, CS37_SW8, CS39_SW8 }, // 194
    {1,  CS3_SW8,  CS2_SW8, CS1_SW8  }, // 195
    {1,  CS5_SW8,  CS4_SW8, CS6_SW8  }, // 196
    {1,  CS9_SW8,  CS8_SW8, CS7_SW8  }, // 197
    {1, CS11_SW8, CS10_SW8, CS12_SW8 }, // 198
    {1, CS15_SW8, CS14_SW8, CS13_SW8 }, // 199
    {1, CS17_SW8, CS16_SW8, CS18_SW8 }, // 200
    {1, CS21_SW8, CS20_SW8, CS19_SW8 }, // 201
    {1, CS23_SW8, CS22_SW8, CS24_SW8 }, // 202
    {1, CS27_SW8, CS26_SW8, CS25_SW8 }, // 203
    {1, CS29_SW8, CS28_SW8, CS30_SW8 }, // 204
    {1, CS33_SW8, CS32_SW8, CS31_SW8 }, // 205
    {1, CS35_SW8, CS34_SW8, CS36_SW8 }, // 206
    {1, CS38_SW8, CS37_SW8, CS39_SW8 }, // 207
    // Ninth row
    {0,  CS3_SW7,  CS2_SW7, CS1_SW7  }, // 208
    {0,  CS5_SW7,  CS4_SW7, CS6_SW7  }, // 209
    {0,  CS9_SW7,  CS8_SW7, CS7_SW7  }, // 210
    {0, CS11_SW7, CS10_SW7, CS12_SW7 }, // 211
    {0, CS15_SW7, CS14_SW7, CS13_SW7 }, // 212
    {0, CS17_SW7, CS16_SW7, CS18_SW7 }, // 213
    {0, CS21_SW7, CS20_SW7, CS19_SW7 }, // 214
    {0, CS23_SW7, CS22_SW7, CS24_SW7 }, // 215
    {0, CS27_SW7, CS26_SW7, CS25_SW7 }, // 216
    {0, CS29_SW7, CS28_SW7, CS30_SW7 }, // 217
    {0, CS33_SW7, CS32_SW7, CS31_SW7 }, // 218
    {0, CS35_SW7, CS34_SW7, CS36_SW7 }, // 219
    {0, CS38_SW7, CS37_SW7, CS39_SW7 }, // 220
    {1,  CS3_SW7,  CS2_SW7, CS1_SW7  }, // 221
    {1,  CS5_SW7,  CS4_SW7, CS6_SW7  }, // 222
    {1,  CS9_SW7,  CS8_SW7, CS7_SW7  }, // 223
    {1, CS11_SW7, CS10_SW7, CS12_SW7 }, // 224
    {1, CS15_SW7, CS14_SW7, CS13_SW7 }, // 225
    {1, CS17_SW7, CS16_SW7, CS18_SW7 }, // 226
    {1, CS21_SW7, CS20_SW7, CS19_SW7 }, // 227
    {1, CS23_SW7, CS22_SW7, CS24_SW7 }, // 228
    {1, CS27_SW7, CS26_SW7, CS25_SW7 }, // 229
    {1, CS29_SW7, CS28_SW7, CS30_SW7 }, // 230
    {1, CS33_SW7, CS32_SW7, CS31_SW7 }, // 231
    {1, CS35_SW7, CS34_SW7, CS36_SW7 }, // 232
    {1, CS38_SW7, CS37_SW7, CS39_SW7 }, // 233
};
#endif

