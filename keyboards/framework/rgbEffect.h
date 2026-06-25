#include QMK_KEYBOARD_H
#include "rgb.h"
#include "communication.h"

extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const rgb_t    rgb_layout[][RGB_MATRIX_LED_COUNT];
extern led2KeyMap_t   led2KeyMap;
extern ledOrderMap_t  ledOrderMap;
// e.g: A simple effect, self-contained within a single method
typedef struct PACKED location {
    uint8_t x;
    uint8_t y;
} location;

static bool user_map(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    const double brightness = rgb_matrix_config.hsv.v / 255.0;
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t  layerDepth = 0;
            uint8_t  layer      = 0;
            uint16_t keycode    = 0;
            for (uint8_t l = get_highest_layer(layer_state); l > 0; l--) {
                if (IS_LAYER_OFF(l)) continue;
                keycode = keymaps[l][row][col];
                if (keycode == KC_NO) break;
                if (keycode == _______) {
                    layerDepth++;
                    continue;
                };
                if (l > layer) layer = l;
            }
            uint16_t activeKeycode = keymaps[layer][row][col];
            // if (keycode == KC_NO) continue;
            // printf("%d,%d layer %d (%d deep)\n", col, row, layer, layerDepth);
            uint8_t divider = layerDepth > 0 ? (2 << layerDepth) : 1;
            rgb_t   c       = rgb_layout[layer][ledOrderMap[row][col]];
            if ((get_mods() | get_weak_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                if ((activeKeycode >= KC_A && activeKeycode <= KC_Z)) {
                    c = color(255, 0, 255);

                } else if ((activeKeycode >= KC_1 && activeKeycode <= KC_0) || (activeKeycode >= KC_MINUS && activeKeycode <= KC_SLASH) || (activeKeycode == KC_NONUS_BACKSLASH)) {
                    c = color(0, 255, 255);
                }
            }
            // printf("row: %d, col: %d, led index: %d rgb index: %d rgb (%d,%d,%d)\n", row, col, led_index, index,c.r,c.g,c.b);
            if (get_highest_layer(layer_state) == _FN && activeKeycode == MO(_FN)) {
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
            for (uint8_t mapIndex = 0; mapIndex < 8; mapIndex++) {
                if (led2KeyMap[row][col][mapIndex] < led_min || led2KeyMap[row][col][mapIndex] >= led_max) continue;
                rgb_matrix_set_color(led2KeyMap[row][col][mapIndex], scale(c));
            }
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}
