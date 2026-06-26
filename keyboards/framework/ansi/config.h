#pragma once
#define DYNAMIC_KEYMAP_LAYER_COUNT 16
#define RGB_MATRIX_MINIMAL_BRIGHTNESS 25

// I2C for the RBG controller
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP26
#define I2C1_SCL_PIN GP27
// #define RGB_MATRIX_IS31FL3743A
#define IS31FL3743A_I2C_ADDRESS_1 0x20
#define IS31FL3743A_I2C_ADDRESS_2 0x23
#define DRIVER_1_LED_TOTAL 48
#define DRIVER_2_LED_TOTAL 49
#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
#define ISSI_CONFIGURATION 0x21

// Limit current to ensure max current draw is just about 500mA
// when white at 100% brightness
// #define ISSI_GLOBALCURRENT 185
#include "enabledEffects.h"
