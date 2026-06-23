#include "analog.h"
#include "debounce.h"
#include "btpv_matrix.h"

#define PAL_MODE_ADC_PULLUP (PAL_MODE_INPUT_ANALOG | PAL_RP_PAD_PUE)



void matrix_init_custom(void) {
    gpio_set_pin_output(SGM_A);
    gpio_set_pin_output(SGM_B);
    gpio_set_pin_output(SGM_C);
    gpio_set_pin_output(SGM_ENABLE);
    gpio_set_pin_input(GP6);
    gpio_set_pin_input(GP7);
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        gpio_set_pin_output(FIRST_ROWPIN + i);
    }
    palSetLineMode(GP28, PAL_MODE_ADC_PULLUP);
    // Unless hardware debouncing - Init the configured debounce routine
    debounce_init();

    // This *must* be called for correct keyboard behavior
    matrix_init_kb();
}

void selectMuxCH(uint8_t ch) {
    // assert(ch >= 0 && ch <= 3);

    // Not in order - need to remap them

    // X0 - KSI1
    // X1 - KSI2
    // X2 - KSI0
    // X3 - KSI3
    // Only for keyboard, not for num-/grid-pad
    // X4 - KSI4
    // X5 - KSI5
    // X6 - KSI6
    // X7 - KSI7
    int index = ch;
    // if (ch > 2) {
    //     index = ch;
    // } else {
    //     const int map[] = {2, 0, 1};
    //     index           = map[ch];
    // }
    gpio_write_pin(SGM_A, (index >> 0) & 1);
    gpio_write_pin(SGM_B, (index >> 1) & 1);
    gpio_write_pin(SGM_C, (index >> 2) & 1);
}
bool applyMatrix(Matrix current_matrix, AdcValueMatrix adcValueMatrix) {
    bool                 changed                                = false;
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        matrix_row_t row_value = 0;
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            row_value += adcValueMatrix[row][col] << col;
        }
        changed |= current_matrix[row] != row_value;
        current_matrix[row] = row_value;
    }
    return changed;
}
bool matrix_scan_custom(Matrix current_matrix) {
    bool changed = false;
    for (uint8_t col = 0; col < MATRIX_ROWS; col++) {
        gpio_write_pin_high(FIRST_ROWPIN + col);
    }
    gpio_write_pin(SGM_ENABLE, 0);
    // matrix_print();
    AdcMatrix      adcMatrix;
    AdcValueMatrix adcValueMatrix;

    for (uint8_t drivePin = 0; drivePin < MATRIX_ROWS; drivePin++) {
        gpio_write_pin_low(FIRST_ROWPIN + drivePin);
        for (uint8_t muxCH = 0; muxCH < MATRIX_COLS; muxCH++) {
            selectMuxCH(muxCH);
            // wait_us(500);
            adcMatrix[drivePin][muxCH] = ANALOG_READ(SGM_INPUT);
            // uprintf("r:%u c:%u ADC: %u\n", row, col, adc_read(SGM_INPUT));
        }
        gpio_write_pin_high(FIRST_ROWPIN + drivePin);
    }
    gpio_write_pin(SGM_ENABLE, 1);
    // TODO: add matrix scanning routine here
    for (uint8_t muxCH = 0; muxCH < MATRIX_COLS; muxCH++) {
        uint8_t pressed_in_row = 0;
        for (int drivePin = 0; drivePin < MATRIX_ROWS; drivePin++) {
            if (adcMatrix[drivePin][muxCH] < ANALOG_THRESHOLD) {
                pressed_in_row += 1;
            }
        }
        uint16_t threshold = ANALOG_THRESHOLD;
        switch (pressed_in_row) {
            case 0:
            case 1:
                threshold = 1000; // 1.0V
                break;
            case 2:
                threshold = 2000; // 2.0V
                break;
            case 3:
                threshold = 2500; // 2.5V
                break;
            default:
                threshold = ANALOG_THRESHOLD;
                break;
        }
        for (int drivePin = 0; drivePin < MATRIX_ROWS; drivePin++) {
            adcValueMatrix[drivePin][muxCH] = adcMatrix[drivePin][muxCH] < threshold;
            if (adcMatrix[drivePin][muxCH] < threshold){
            printf("row: %d, col: %d, led index: %d\n",drivePin,muxCH,g_led_config.matrix_co[drivePin][muxCH]);

            }
        }
    }
    changed |= applyMatrix(current_matrix, adcValueMatrix);
    return changed;
}
