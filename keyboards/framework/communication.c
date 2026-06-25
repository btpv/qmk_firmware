#include <communication.h>
#include <keyboard.h>
#include <quantum.h>
#include "raw_hid.h"
void send_command(const char *cmd) {
    register_code(KC_LALT);
    tap_code(KC_F2);
    unregister_code(KC_LALT);
    wait_ms(50);
    SEND_STRING(cmd);
    tap_code(KC_ENTER);
}
enum comStateType comState = closed;

bool send_rawmsg(uint8_t type, uint8_t value) {
    uint8_t buf[31] = {0};   // fill with zeros
    buf[0]          = value; // put your single byte in the first slot
    return send_rawarray(type, buf);
}

bool send_rawarray(uint8_t type, const uint8_t value[31]) {
    if (comState != ready) return false;
    uint8_t msg[32] = {0};
    msg[0]          = type;
    memcpy(&msg[1], value, 31);
    if (type != CM_ACK) comState = buzy;
    raw_hid_send(msg, sizeof(msg));
    return true;
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    switch (data[0]) {
        case CM_OPEN:
        case CM_ACK:
            comState = ready;
            break;
        case CM_CLOSE:
            comState = closed;
            break;
#ifdef RGB_MATRIX_ENABLE
        case MSG_TYPE_SET_BRIGHTNESS:
            uint8_t brightnessLevelTarget = ((uint16_t)data[1] * 15 / 255) + 1;
            if (rgb_matrix_get_val() / 16 + 1 == brightnessLevelTarget) break;
            printf("target brightness %d\t", brightnessLevelTarget);
            printf("brightness %d\t", rgb_matrix_get_val() / 16 + 1);
            if (rgb_matrix_get_val() / 16 + 1 > brightnessLevelTarget) {
                while (rgb_matrix_get_val() / 16 + 1 > brightnessLevelTarget)
                    rgb_matrix_decrease_val();
            }
            if ((rgb_matrix_get_val() / 16 + 1) < brightnessLevelTarget) {
                while (rgb_matrix_get_val() / 16 + 1 < brightnessLevelTarget)
                    rgb_matrix_increase_val();
            }
            printf("newbrightness %d\n", rgb_matrix_get_val() / 16 + 1);
            break;
        case MSG_TYPE_EFFECT:
            justRecivedEffectData = true;
            uint64_t new_value;
            memcpy(&new_value, data + 1, 8);
            rgb_matrix_mode(data[0]);
            rgb_matrix_set_speed(data[1]);
            rgb_matrix_sethsv(data[2], data[3], rgb_matrix_get_val());
            if (data[5]) {
                rgb_matrix_enable();
            } else {
                rgb_matrix_disable();
            }
            break;
#endif
        case MSG_TYPE_FN:
            if (data[1] == 0x01) {
                layer_on(_FN);
            } else {
                layer_off(_FN);
            }
            break;
    }
    if (data[0] != CM_ACK) send_rawmsg(CM_ACK, data[0]);
}

bool    justRecivedEffectData = false;

void            housekeeping_task_kb(void) {
    #ifdef syncrgb
    static uint64_t last_rgb_config = 0;
    if ((rgb_matrix_config.raw & RGBCONFIGMASK) != (last_rgb_config & RGBCONFIGMASK)) {
        if (justRecivedEffectData) {
            justRecivedEffectData = false;
            last_rgb_config = rgb_matrix_config.raw;
        } else {

            uint8_t buf[31] = {0};
            buf[0]          = rgb_matrix_get_mode();
            buf[1]          = rgb_matrix_get_speed();
            buf[2]          = rgb_matrix_get_hue();
            buf[3]          = rgb_matrix_get_sat();
            buf[4]          = rgb_matrix_get_val();
            buf[5]          = rgb_matrix_is_enabled();

            send_rawarray(MSG_TYPE_EFFECT, buf);
            last_rgb_config = rgb_matrix_config.raw;
        }
    }
    #endif
}
