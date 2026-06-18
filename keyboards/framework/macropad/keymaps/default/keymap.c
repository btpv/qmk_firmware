// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "color.h"
#include QMK_KEYBOARD_H
enum _layers {
    _BASE,
    _NUMLOCK,
    _GAME,
    _F,
    _FN,
};
enum custom_keycodes {
    PM_PERF = SAFE_RANGE,
    PM_BAL,
    PM_PWRS,
    PASSWD,
    FN_BTN,
    RST_LG,
};
const rgb_t PROGMEM rgb_layout[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = {
        {{255, 50,000},  {000,000,255},  {000,000,255},  {000,000,255}},
        {{000,000,000},  {000,000,000},  {000,000,000},  {000,000,000}},
        {{000,000,000},  {000,255,000},  {000,000,000},  {000,000,000}},
        {{000,255,000},  {000,255,000},  {000,255,000},  {000,000,000}},
        {{000,000,000},  {000,000,000},  {000,000,000},  {000,000,000}},
        {{255,255,255},  {000,000,000},  {000,000,000},  {000,000,000}}
    },
    [_NUMLOCK] = {
        {{255, 50,000},  {000,000,255},  {000,000,255},  {000,000,255}},
        {{255,128,000},  {255,128,000},  {255,128,000},  {255,128,000}},
        {{100,000,255},  {100,000,255},  {100,000,255},  {255,000,255}},
        {{100,000,255},  {100,000,255},  {100,000,255},  {255,000,255}},
        {{100,000,255},  {100,000,255},  {100,000,255},  {000,255,000}},
        {{255,255,255},  {100,000,255},  {000,255,128},  {000,255,128}}
    },
    [_GAME] = {
        {{255,000,000},  {255,000,000},  {255,000,000},  {255,000,000}},
        {{255,000,000},  {255,000,000},  {255,000,000},  {255,000,000}},
        {{255,000,000},  {255,000,000},  {255,000,000},  {255,000,000}},
        {{255,000,000},  {255,000,000},  {255,000,000},  {255,000,000}},
        {{255,000,000},  {255,000,000},  {255,000,000},  {255,000,000}},
        {{255,000,000},  {255,000,000},  {255,000,000},  {255,000,000}}
    },
    [_F] = {
        {{000,255,50 },  {000,255,50 },  {000,255,50 },  {000,255,50 }},
        {{000,255,50 },  {000,255,50 },  {000,255,50 },  {000,255,50 }},
        {{000,255,50 },  {000,255,50 },  {000,255,50 },  {000,255,50 }},
        {{000,255,50 },  {000,255,50 },  {000,255,50 },  {000,255,50 }},
        {{000,255,50 },  {000,255,50 },  {000,255,50 },  {000,255,50 }},
        {{000,255,50 },  {000,255,50},   {000,255,50 },  {000,255,50}}
 },
    [_FN] = {
        {{100,000,255},  {000,255,128},  {000,255,128},  {000,255,128}},
        {{000,000,000},  {175,255,000},  {000,000,000},  {63,63,63}},
        {{000,000,000},  {000,000,000},  {000,000,000},  {000,000,000}},
        {{255,000,000},  {000,000,000},  {000,000,000},  {255,000,000}},
        {{000,255,50 },  {255,050,000},  {255,050,000},  {255, 50,000}},
        {{255,255,255},  {255,050,000},  {255,000,000},  {000,255,000}}
}
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = {
        {PASSWD,    KC_MPRV,   KC_MPLY,   KC_MNXT},
        {KC_NO,     KC_NO,     KC_NO,     KC_NO},
        {KC_NO,     KC_UP,     KC_NO,     KC_NO},
        {KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_NO},
        {KC_NO,     KC_NO,     KC_NO,     KC_NO},
        {FN_BTN,    KC_NO,     KC_NO,     KC_NO}
    },
    [_NUMLOCK] = {
        {PASSWD,    KC_MPRV,   KC_MPLY,   KC_MNXT},
        {KC_PPLS,   KC_PMNS,   KC_PAST,   KC_PSLS},
        {KC_P7,     KC_P8,     KC_P9,     KC_HOME},
        {KC_P4,     KC_P5,     KC_P6,     KC_END},
        {KC_P1,     KC_P2,     KC_P3,     KC_PENT},
        {FN_BTN ,   KC_P0,     KC_PDOT,   KC_PCMM}
    },
    [_GAME] = {
        {PB_1,      PB_2,      PB_3,      PB_4},
        {PB_5,      PB_6,      PB_7,      PB_8},
        {PB_9,      PB_10,     PB_11,     PB_12},
        {PB_13,     PB_14,     PB_15,     PB_16},
        {PB_17,     PB_18,     PB_19,     PB_20},
        {FN_BTN,    PB_22,     PB_23,     PB_24}
    },
    [_F] = {
        {KC_F1,      KC_F2,      KC_F3,      KC_F4},
        {KC_F5,      KC_F6,      KC_F7,      KC_F8},
        {KC_F9,      KC_F10,     KC_F11,     KC_F12},
        {KC_F13,     KC_F14,     KC_F15,     KC_F16},
        {KC_F17,     KC_F18,     KC_F19,     KC_F20},
        {KC_F21,     KC_F22,     KC_F23,     KC_F24}
    },
    [_FN] = {
        {KC_NUM ,   KC_VOLD,   KC_MUTE,   KC_VOLU} ,
        {_______,   RST_LG ,   _______,   QK_BOOT},
        {_______,   _______,   _______,   _______},
        {TG(_GAME), _______,   _______,   PM_PERF},
        {TG(_F),    RM_PREV,   RM_NEXT,   PM_BAL} ,
        {FN_BTN ,   RM_TOGG,   _______,   PM_PWRS}
    }
};
bool led_update_user(led_t led_state) {
    // Change layer if numlock state changes, either triggered by OS or
    // by numlock key on this keyboard
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
        case FN_BTN:
            if (record->event.pressed) {
                layer_on(_FN);
            } else {
                layer_off(_FN);
            }
            return false;
    }
    return true;
}
