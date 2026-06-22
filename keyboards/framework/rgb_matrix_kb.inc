// !!! DO NOT ADD #pragma once !!! //
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
#include "color.h"
RGB_MATRIX_EFFECT(user_map)
// #define RGB_MATRIX_CUSTOM_EFFECT_IMPLS
// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#define scale(c) c.r *(brightness / divider), (c.g * brightness) / divider, (c.b * brightness) / divider
// rgb_matrix_set_color(i, scale(c));
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    include QMK_KEYBOARD_H
#    include "rgb.h"
#    include "communication.h"

extern const rgb_t    rgb_layout[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
// e.g: A simple effect, self-contained within a single method
static bool user_map(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    const double brightness = rgb_matrix_config.hsv.v / 255.0;
    for (uint8_t i = led_min; i < led_max; i++) {
        uint8_t  row        = i / MATRIX_COLS;
        uint8_t  col        = i % MATRIX_COLS;
        uint8_t  layerDepth = 0;
        uint8_t  layer      = 0;
        uint16_t keycode    = 0;
        for (uint8_t l = get_highest_layer(layer_state); l > 0; l--) {
            if (IS_LAYER_OFF(l)) continue;
            keycode = keymaps[l][row][col];
            if (keycode == _______) {
                layerDepth++;
                continue;
            };
            if (l > layer) layer = l;
        }
        // printf("%d,%d layer %d (%d deep)\n", col, row, layer, layerDepth);
        uint8_t divider = layerDepth > 0 ? (2 << layerDepth) : 1;
        rgb_t   c       = rgb_layout[layer][row][col];
        if (get_highest_layer(layer_state) == _FN && keycode == MO(_FN)) {
            switch (comState) {
                case closed:
                    c = color(255, 0, 0);
                    break;
                case buzy:
                    c = color(255, 50, 0);
                    break;
                case ready:
                    c = color(0, 255, 0);
                    break;
            }
        }
        rgb_matrix_set_color(i, scale(c));
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
