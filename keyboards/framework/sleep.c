
#define SLEEP_GPIO GP0
#define MUX_ENABLE_GPIO GP4
#define BOOT_DONE_GPIO GP5

#include "rgb.h"
#include <quantum.h>
void keyboard_pre_init_kb(void) {
    keyboard_pre_init_user();
    gpio_set_pin_output(IS31FL3743A_ENABLE_GPIO);
    rgbOn;


    // Mark boot as done.
    // Before this, when holding down both alt keys QSPI_SS is pulled low to put
    // the RP2040 in bootloader mode during reset.
    gpio_set_pin_output(BOOT_DONE_GPIO);
    gpio_write_pin_low(BOOT_DONE_GPIO);
    gpio_set_pin_input(SLEEP_GPIO);
}

/**
 * Called by QMK when the keyboard suspends
 */
void suspend_power_down_kb(void) {
    suspend_power_down_user();
    rgbOff;
}

/**
 * Called by QMK when the keyboard wakes up from suspend
 */
void suspend_wakeup_init_kb(void) {
    suspend_wakeup_init_user();
    rgbOn;
}
