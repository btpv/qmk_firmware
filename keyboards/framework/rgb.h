#pragma once
#include "gpio.h"
#define IS31FL3743A_ENABLE_GPIO GP29
#define rgbOff gpio_write_pin_low(IS31FL3743A_ENABLE_GPIO);
#define rgbOn gpio_write_pin_high(IS31FL3743A_ENABLE_GPIO);
