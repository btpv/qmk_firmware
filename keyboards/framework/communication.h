#pragma once
#include <stdbool.h>
#include <stdint.h>
#include QMK_KEYBOARD_H
#ifndef RGB_MATRIX_MINIMAL_BRIGHTNESS
#define RGB_MATRIX_MINIMAL_BRIGHTNESS 0
#endif
#define RGBCONFIGMASK ~((uint64_t)0xFF << (3 * 8))
enum msg_type {
    // sync effects
    CM_PING = 0x00,
    CM_OPEN,
    CM_CLOSE,
    CM_ACK,
    MSG_TYPE_FN = 0x10,
    MSG_TYPE_EFFECT,
    MSG_TYPE_CMD = 0x20,
    MSG_TYPE_CMD_PRT,
    MSG_TYPE_SET_BRIGHTNESS = 0x30,
};
enum comStateType { closed, buzy, ready };

extern enum comStateType comState;
bool    send_rawarray(uint8_t type, const uint8_t value[31]);
bool    send_rawmsg(uint8_t type, uint8_t value);
void    send_command(const char command[]);
bool    justRecivedEffectData;
