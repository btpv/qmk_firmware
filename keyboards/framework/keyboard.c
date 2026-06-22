#include <quantum.h>
#include "keyboard.h"
#include "communication.h"
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case LED_RST:
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_user_map);
                return false;
        }
    }
    return process_record_user(keycode, record);
}
layer_state_t layer_state_set_kb(layer_state_t state) {
    send_rawmsg(MSG_TYPE_FN_SEND, layer_state_cmp(state, _FN));
    return layer_state_set_user(state);
}


