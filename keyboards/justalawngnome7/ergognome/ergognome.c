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

#include "ergognome.h"

#if defined(RGB_MATRIX_ENABLE)

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    { 13, 12, 11, 10,      9,  8,  7,      6,  5,      4,  3,  2,  1,      0,     NO_LED },
    { 14, 15, 16, 17,     18, 19, 20,     21, 22,     23, 24, 25, 26,     27,     28     },
    { 43, 42, 41, 40,     39, 38, 37,     36, 35,     34, 33, 32, 31,     30,     29     },
    { 44, 45, 46, 47,     48, 49, 50,     51, 52,     53, 54, 55, 56,     NO_LED, 57     },
    { 71, 70, 69, 68,     67, 66, 65,     64, 63,     62, 61, 60, NO_LED, 59,     58     },
    { 72, 73, 74, NO_LED, 75, 76, NO_LED, 77, NO_LED, 78, 79, 80, 81,     82,     83     }
}, {
    // LED Index to Physical Position

    // RGB Matrix centered on the true LED midpoint
    //{198,0}, {182,0}, {169,0}, {156,0}, {143,1}, {126,2}, {113,4}, {85,6}, {72,4}, {56,2}, {43,1}, {30,0}, {16,0}, {0,0},
    //{7,14}, {20,14}, {33,15}, {46,15}, {59,17}, {72,18}, {85,20}, {107,19}, {120,17}, {133,16}, {146,15}, {159,14}, {172,14}, {192,14}, {220,14},
    //{221,25}, {198,25}, {182,25}, {169,25}, {155,25}, {142,26}, {129,27}, {116,29}, {103,31}, {76,30}, {63,28}, {50,27}, {37,26}, {24,25}, {7,25},
    //{6,36}, {24,36}, {37,37}, {51,38}, {64,39}, {77,41}, {109,41}, {122,39}, {135,38}, {149,37}, {162,36}, {175,36}, {196,36}, {223,36},
    //{224,47}, {207,50}, {186,47}, {168,47}, {155,47}, {142,48}, {129,50}, {116,51}, {80,53}, {67,51}, {54,49}, {41,48}, {28,47}, {7,47},
    //{0,58}, {16,58}, {33,59}, {56,61}, {77,64}, {127,61}, {152,59}, {165,58}, {178,58}, {194,61}, {207,61}, {221,61}

    // RGB Matrix centered between F and J keys
    {202,0}, {188,0}, {177,0}, {166,0}, {154,1}, {140,2}, {129,4}, {105,6}, {94,4}, {80,2}, {69,1}, {58,0}, {47,0}, {33,0},
    {39,14}, {50,14}, {61,15}, {72,15}, {83,17}, {95,18}, {106,20}, {124,19}, {135,17}, {146,16}, {157,15}, {169,14}, {180,14}, {197,14}, {220,14},
    {221,25}, {202,25}, {188,25}, {177,25}, {165,25}, {154,26}, {143,27}, {132,29}, {121,31}, {98,30}, {87,28}, {75,27}, {64,26}, {53,25}, {39,25},
    {38,36}, {53,36}, {65,37}, {76,38}, {87,39}, {98,41}, {126,41}, {137,39}, {148,38}, {160,37}, {171,36}, {182,36}, {200,36}, {223,36},
    {224,47}, {210,50}, {192,47}, {176,47}, {165,47}, {154,48}, {143,50}, {132,51}, {101,53}, {90,51}, {79,49}, {68,48}, {56,47}, {38,47},
    {33,58}, {47,58}, {61,59}, {80,61}, {98,64}, {141,61}, {162,59}, {174,58}, {185,58}, {199,61}, {210,61}, {221,61}
}, {
    // LED Index to Flag
    // 0x01: the LED is on a modifier key
    // 0x02: the LED is for underglow
    // 0x04: the LED is for key backlight
    // 0x08: the LED is for keyboard state indication
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,         // row0, right-to-left (top)
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,   // row1, left-to-right
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,   // row2, right-to-left
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,         // row3, left-to-right
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,         // row4, right-to-left
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04                      // row5, left-to-right (bot)
} };
#endif

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
            if (!rgb_matrix_is_enabled()) {
                rgb_matrix_set_flags(LED_FLAG_ALL);
                rgb_matrix_enable();
            }
            return false;
    }
    return true;
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }

    /*
    // Highlight the available keys when a layer other than "0" is active
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }
            }
        }
    }
    */

    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);
#   if defined(CAPS_LOCK_LED_INDEX)
        if (host_keyboard_led_state().caps_lock) {
            RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 255, 0, 0);
        } else {
            if (!rgb_matrix_get_flags()) {
                RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
            }
        }
#   endif // CAPS_LOCK_LED_INDEX
#   if defined(NUM_LOCK_LED_INDEX)
        if (host_keyboard_led_state().num_lock) {
            RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 255, 0, 0);
        } else {
            if (!rgb_matrix_get_flags()) {
                RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 0, 0, 0);
            }
        }
#   endif // NUM_LOCK_LED_INDEX

    return true;
}

/*
Index    Name         X           Y
-----   -----   -------     -------
 0      LED75   322.707      42.875
 1      LED70   298.767      42.875
 2      LED64   279.717      42.874
 3      LED58   260.506      43.242
 4      LED52   241.316      44.365
 5      LED47   217.288      46.871
 6      LED41   198.348      49.720
 7      LED36   157.694      53.236
 8      LED30   138.810      49.637
 9      LED24   114.898      46.197
10      LED19    95.765      44.327
11      LED13    76.573      43.230
12      LED7     57.366      42.875
13      LED1     33.426      42.875
14      LED2     43.383      67.673
15      LED8     62.457      67.731
16      LED14    81.684      68.289
17      LED20   100.870      69.665
18      LED25   119.979      71.855
19      LED31   138.978      74.856
20      LED37   157.833      78.663
21      LED42   189.084      76.730
22      LED48   208.015      73.317
23      LED53   227.073      70.712
24      LED59   246.225      68.920
25      LED65   265.433      67.944
26      LED71   284.607      67.660
27      LED76   313.182      67.660
28      LED80   353.570      67.660
29      LED81   355.710      86.973
30      LED77   322.110      86.973
31      LED72   298.297      86.973
32      LED66   279.260      86.973
33      LED60   260.030      87.387
34      LED54   240.834      88.646
35      LED49   221.713      90.757
36      LED43   202.705      93.715
37      LED38   183.846      97.514
38      LED32   144.294      95.566
39      LED26   125.349      92.192
40      LED21   106.273      89.663
41      LED15    87.103      87.984
42      LED9     67.878      87.160
43      LED3     43.980      86.973
44      LED4     42.278     106.260
45      LED10    68.571     106.483
46      LED16    87.802     107.379
47      LED22   106.970     109.168
48      LED27   126.034     111.848
49      LED33   144.953     115.411
50      LED39   192.759     115.411
51      LED44   211.678     111.848
52      LED50   230.742     109.169
53      LED55   249.911     107.379
54      LED61   269.141     106.484
55      LED67   288.290     106.260
56      LED73   319.239     106.260
57      LED82   357.850     106.260
58      LED83   359.990     125.573
59      LED78   335.915     130.073
60      LED68   304.977     125.560
61      LED62   278.765     125.560
62      LED56   259.513     126.031
63      LED51   240.397     127.440
64      LED45   221.194     129.785
65      LED40   202.217     133.061
66      LED34   150.244     136.366
67      LED28   131.403     132.364
68      LED23   112.389     129.387
69      LED17    93.247     127.143
70      LED11    74.023     125.936
71      LED5     42.913     125.560
72      LED6     33.317     144.860
73      LED12    57.129     144.860
74      LED18    81.183     145.574
75      LED29   114.655     149.508
76      LED35   145.478     154.962
77      LED46   218.908     150.203
78      LED57   254.733     145.666
79      LED63   273.955     145.009
80      LED69   293.058     144.886
81      LED74   316.852     149.123
82      LED79   335.915     149.123
83      LED84   354.965     149.123
*/
