#pragma once
#include "gpio.h"
#define IS31FL3743A_ENABLE_GPIO GP29
#define rgbOff gpio_write_pin_low(IS31FL3743A_ENABLE_GPIO);
#define rgbOn gpio_write_pin_high(IS31FL3743A_ENABLE_GPIO);
#define color(r,g,b) ((rgb_t){r,g,b})
typedef const uint8_t led2KeyMap_t[MATRIX_ROWS][MATRIX_COLS][8];
typedef const uint8_t ledOrderMap_t[MATRIX_ROWS][MATRIX_COLS];
#include QMK_KEYBOARD_H

