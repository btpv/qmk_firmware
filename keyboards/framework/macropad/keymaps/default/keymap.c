// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "color.h"
#include <communication.h>
#include "keyboard.h"
#include QMK_KEYBOARD_H

enum _layers {
    _BASE,
    _NUMLOCK,
    _GAME,
    _F,
};
enum custom_keycodes {
    PM_PERF = SAFE_RANGE,
    PM_BAL,
    PM_PWRS,
    PASSWD,
    RST_LG,
};
const rgb_t PROGMEM rgb_layout[][RGB_MATRIX_LED_COUNT] = {
    [_BASE] = {
        {255,050,000},  {000,000,255},  {000,000,255},  {000,000,255},
        {000,000,000},  {000,000,000},  {000,000,000},  {000,000,000},
        {000,000,000},  {000,255,000},  {000,000,000},  {000,000,000},
        {000,255,000},  {000,255,000},  {000,255,000},  {000,000,000},
        {000,000,000},  {000,000,000},  {000,000,000},  {000,000,000},
        {255,255,255},  {000,000,000},  {000,000,000},  {000,000,000}
    },
    [_NUMLOCK] = {
        {255, 50,000},  {000,000,255},  {000,000,255},  {000,000,55},
        {255,128,000},  {255,128,000},  {255,128,000},  {255,128,000},
        {100,000,255},  {100,000,255},  {100,000,255},  {255,000,255},
        {100,000,255},  {100,000,255},  {100,000,255},  {255,000,255},
        {100,000,255},  {100,000,255},  {100,000,255},  {000,255,000},
        {255,255,255},  {100,000,255},  {000,255,128},  {000,255,128}
    },
    [_GAME] = {
        {255,000,000},  {255,000,000},  {255,000,000},  {255,000,000},
        {255,000,000},  {255,000,000},  {255,000,000},  {255,000,000},
        {255,000,000},  {255,000,000},  {255,000,000},  {255,000,000},
        {255,000,000},  {255,000,000},  {255,000,000},  {255,000,000},
        {255,000,000},  {255,000,000},  {255,000,000},  {255,000,000},
        {255,000,000},  {255,000,000},  {255,000,000},  {255,000,000}
    },
    [_F] = {
        {000,255,050},  {000,255,050},  {000,255,050},  {000,255,050},
        {000,255,050},  {000,255,050},  {000,255,050},  {000,255,050},
        {000,255,050},  {000,255,050},  {000,255,050},  {000,255,050},
        {000,255,050},  {000,255,050},  {000,255,050},  {000,255,050},
        {000,255,050},  {000,255,050},  {000,255,050},  {000,255,050},
        {000,255,050},  {000,255,50},   {000,255,050},  {000,255,050}
    },
    [_FN] = {
        {100,000,255},  {000,255,128},  {000,255,128},  {000,255,128},
        {255,050,000},  {175,255,000},  {175,255,000},  {063,063,063},
        {000,000,000},  {175,255,000},  {175,255,000},  {000,000,000},
        {255,000,000},  {175,255,000},  {175,255,000},  {255,000,000},
        {000,255,050},  {175,255,000},  {175,255,000},  {255,050,000},
        {255,255,255},  {175,255,000},  {175,255,000},  {000,255,000}
    }
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        PASSWD,    KC_MPRV,   KC_MPLY,   KC_MNXT,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,
        KC_NO,     KC_UP,     KC_NO,     KC_NO,
        KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_NO,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,
        MO(_FN),   KC_NO,     KC_NO,     KC_NO
    ),
    [_NUMLOCK] = LAYOUT(
        PASSWD,    KC_MPRV,   KC_MPLY,   KC_MNXT,
        KC_PPLS,   KC_PMNS,   KC_PAST,   KC_PSLS,
        KC_P7,     KC_P8,     KC_P9,     KC_HOME,
        KC_P4,     KC_P5,     KC_P6,     KC_END,
        KC_P1,     KC_P2,     KC_P3,     KC_PENT,
        MO(_FN),   KC_P0,     KC_PDOT,   KC_PCMM
    ),
    [_GAME] = LAYOUT(
        PB_1,      PB_2,      PB_3,      PB_4,
        PB_5,      PB_6,      PB_7,      PB_8,
        PB_9,      PB_10,     PB_11,     PB_12,
        PB_13,     PB_14,     PB_15,     PB_16,
        PB_17,     PB_18,     PB_19,     PB_20,
        MO(_FN),   PB_22,     PB_23,     PB_24
    ),
    [_F] = LAYOUT(
        KC_F1,      KC_F2,      KC_F3,      KC_F4,
        KC_F5,      KC_F6,      KC_F7,      KC_F8,
        KC_F9,      KC_F10,     KC_F11,     KC_F12,
        KC_F13,     KC_F14,     KC_F15,     KC_F16,
        KC_F17,     KC_F18,     KC_F19,     KC_F20,
    LT(_FN, KC_F21),KC_F22,     KC_F23,     KC_F24
    ),
    [_FN] = LAYOUT(
        KC_NUM,    KC_VOLD,   KC_MUTE,   KC_VOLU ,
        RST_LG,    RM_SATU,   RM_SPDU,   QK_BOOT,
        _______,   RM_SATD,   RM_SPDD,   _______,
        TG(_GAME), RM_HUED,   RM_HUEU,   PM_PERF,
        TG(_F),    RM_PREV,   RM_NEXT,   PM_BAL ,
        MO(_FN),   RM_TOGG,   LED_RST,   PM_PWRS
    )
};
bool led_update_user(led_t led_state) {
    if (led_state.num_lock) {
        layer_on(_NUMLOCK);
    } else {
        layer_off(_NUMLOCK);
    }
    return true;
}
void keyboard_post_init_user(void) {
    if (host_keyboard_led_state().num_lock) {
        layer_on(_NUMLOCK);
    } else {
        layer_off(_NUMLOCK);
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PM_PERF:
            if (record->event.pressed) {
                send_command("powerprofilesctl set performance");
            }
            return false;
        case PM_BAL:
            if (record->event.pressed) {
                send_command("powerprofilesctl set balanced");
            }
            return false;
        case PM_PWRS:
            if (record->event.pressed) {
                send_command("powerprofilesctl set power-saver");
            }
            return false;
        case RST_LG:
            if (record->event.pressed) {
                send_command("sudo systemctl restart logid");
            }
            return false;
        case PASSWD:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_L);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            return false;
    }
    return true;
}
