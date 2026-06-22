#pragma once
#include <stdbool.h>
#include <stdint.h>
enum msg_type {
    // TODO: start with ping on 0x00
    // remove the send recive
    // sync effects
    CM_PING = 0x02,
    CM_OPEN,
    CM_CLOSE,
    CM_ACK,
    MSG_TYPE_FN_SEND = 0x10,
    MSG_TYPE_FN_RECV,
    MSG_TYPE_DC_SEND,
    MSG_TYPE_DC_RECV,
    MSG_TYPE_XM_SEND,
    MSG_TYPE_XM_RECV,
    MSG_TYPE_CMD = 0x20,
    MSG_TYPE_CMD_PRT,
    MSG_TYPE_SET_BRIGHTNESS = 0x30,
};
enum comStateType { closed, buzy, ready };

extern enum comStateType comState;
bool    send_rawarray(uint8_t type, const uint8_t value[31]);
bool    send_rawmsg(uint8_t type, uint8_t value);
void    send_command(const char command[]);
