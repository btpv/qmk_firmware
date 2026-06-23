#include QMK_KEYBOARD_H
#include "rgb.h"
#include "communication.h"

extern const rgb_t    rgb_layout[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
// e.g: A simple effect, self-contained within a single method
typedef struct PACKED location {
    uint8_t x;
    uint8_t y;
} location;

static rgb_t getMapColor(uint8_t led_index, uint8_t layer) {
    static bool     isConfigured = false;
    static location ledPositions[RGB_MATRIX_LED_COUNT];
    static uint32_t lastReset = 0;
    if (!isConfigured || timer_elapsed32(lastReset) > 5000) {
        bool usedX[225] = {[0 ... 224] = false};
        bool usedY[65]  = {[0 ... 64] = false};
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            usedX[g_led_config.point[i].x] = true;
            usedY[g_led_config.point[i].y] = true;
            // positions[g_led_config.point[i].y][g_led_config.point[i].x] = i;
        }
        uint8_t Xpos[225] = {[0 ... 224] = 255};
        uint8_t Ypos[65]  = {[0 ... 64] = 255};
        uint8_t x = 0, y = 0;
        for (uint8_t i = 0; i < 225; i++) {
            if (usedX[i]) {
                Xpos[i] = x++;
                printf("x%d used postion %d\n", i, Xpos[i]);
            }
        }
        for (uint8_t i = 0; i < 65; i++) {
            if (usedY[i]) {
                Ypos[i] = y++;
                printf("y%d used postion %d\n", i, Ypos[i]);
            }
        }
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            ledPositions[i] = (location){Xpos[g_led_config.point[i].x],Ypos[g_led_config.point[i].y]};
            // positions[g_led_config.point[i].y][g_led_config.point[i].x] = i;
        }
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            printf("led %d x:%d y:%d\n", i, ledPositions[i].x, ledPositions[i].y);
        }
        isConfigured = true;
        lastReset    = timer_read32();
    }
    // g_led_config.point[led_index];
    location ledPostion = ledPositions[led_index];
    rgb_t    c          = rgb_layout[layer][ledPostion.y][ledPostion.x];
    return c;
}
static bool user_map(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    const double brightness = rgb_matrix_config.hsv.v / 255.0;
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index < led_min || led_index >= led_max) continue;
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

            rgb_t c = getMapColor(led_index, layer);
            // printf("row: %d, col: %d, led index: %d rgb index: %d rgb (%d,%d,%d)\n", row, col, led_index, index,c.r,c.g,c.b);
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
            rgb_matrix_set_color(led_index, scale(c));
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}
