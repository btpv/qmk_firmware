#pragma once
#include <stdint.h>
typedef struct {
    uint8_t drivePin;
    uint8_t muxCH;
} MatrixPosition;
#define matrixPos

#define SGM_A GP1
#define SGM_B GP2
#define SGM_C GP3
#define SGM_ENABLE GP4
#define SGM_INPUT GP28
#define FIRST_ROWPIN GP8
#define ANALOG_READ(pin) adc_read(pinToMux(pin)) * 3300 / 1023
#define ANALOG_THRESHOLD 2900


#include QMK_KEYBOARD_H
typedef matrix_row_t Matrix[MATRIX_ROWS];
typedef uint16_t     AdcMatrix[MATRIX_ROWS][MATRIX_COLS];
typedef bool         AdcValueMatrix[MATRIX_ROWS][MATRIX_COLS];
