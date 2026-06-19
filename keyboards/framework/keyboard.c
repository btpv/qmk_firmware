#include <quantum.h>
#include "keyboard.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case LED_BGS:
                if (rgb_matrix_get_val() > 0) {
                    for (int8_t _ = 0;_<5;_++) rgb_matrix_decrease_val();
                } else {
                    while (rgb_matrix_get_val() < 255)
                        rgb_matrix_increase_val();
                }
                return false;

            case LED_RST:
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_user_map);
                return false;
        }
    }
    return process_record_user(keycode, record);
}
layer_state_t layer_state_set_kb(layer_state_t state) {
    if (layer_state_cmp(state, _FN)) {
        printf("_FN is active\n");
    } else {
        printf("_FN is not active\n");
    }
    return layer_state_set_user(state);
}
