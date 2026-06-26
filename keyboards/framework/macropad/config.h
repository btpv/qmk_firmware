#pragma once
#define DYNAMIC_KEYMAP_LAYER_COUNT 16

#define RGB_MATRIX_MINIMAL_BRIGHTNESS 25

#define RGB_MATRIX_DRIVER IS31FL3743A
// I2C for the RBG controller
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP26
#define I2C1_SCL_PIN GP27
// #define RGB_MATRIX_IS31FL3743A
#define IS31FL3743A_I2C_ADDRESS_1 0x20
// Enable only the first 4 SW and disable software shutdown
// Otherwise voltage on SW pins without LEDs causes voltage rise and noise
#define ISSI_CONFIGURATION 0x71

// Limit current to ensure max current draw is just about 500mA
// when white at 100% brightness
#define ISSI_GLOBALCURRENT 185
#include "enabledEffects.h"
