// !!! DO NOT ADD #pragma once !!! //
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
#include "color.h"

RGB_MATRIX_EFFECT(my_cool_effect)
// #define RGB_MATRIX_CUSTOM_EFFECT_IMPLS
// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    include QMK_KEYBOARD_H

extern const rgb_t    rgb_layout[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
    // e.g: A simple effect, self-contained within a single method
static bool my_cool_effect(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        uint8_t row        = i / MATRIX_COLS;
        uint8_t col        = i % MATRIX_COLS;
        uint8_t layerDepth = 0;
        uint8_t layer      = 0;
        for (uint8_t l = get_highest_layer(layer_state); l > 0; l--) {
            printf("testing %d",l);
            if (IS_LAYER_OFF(l)) continue;
            printf("state: active");
            if (keymaps[l][row][col] == _______) continue;
            printf("key: %d",keymaps[l][row][col]);
            if (l > layer) layer = l;
            layerDepth++;

        }
        rgb_t c = rgb_layout[layer][row][col];
        uint8_t divider = layerDepth*8+2;
        rgb_matrix_set_color(i, c.r/divider, c.g/d  ivider, c.b/divider);
        // rgb_matrix_set_color(i, c.r, c.g, c.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
