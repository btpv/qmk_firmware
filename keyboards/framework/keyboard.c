#include <quantum.h>
#include "keyboard.h"
#include "communication.h"
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
#ifdef RGB_MATRIX_ENABLE

            case LED_RST:
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_user_map);
                return false;
#endif
            case KC_SCRN:
                if (record->event.pressed) {
                    register_code(KC_LGUI);
                    register_code(KC_P);
                } else {
                    unregister_code(KC_P);
                    unregister_code(KC_LGUI);
                }
                return false;
        }
    }
    return process_record_user(keycode, record);
}
layer_state_t layer_state_set_kb(layer_state_t state) {
    send_rawmsg(MSG_TYPE_FN, layer_state_cmp(state, _FN));
    return layer_state_set_user(state);
}
