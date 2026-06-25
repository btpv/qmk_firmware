#include "sleep.h"
#include "rgb.h"
#include <quantum.h>
static bool isSuspended = false;
static bool prevLidClosed = false;
bool handle_idle(void) {
    bool lidClosed = !gpio_read_pin(SLEEP_GPIO);
    bool lidChanged = lidClosed != prevLidClosed;
    prevLidClosed = lidClosed;

    /* If lid is closed and the keyboard is not currently suspended, we need to
     * suspend the keyboard.
     *
     * This does not normally happen, unless the user has configured their OS
     * to not suspend if lid is closed.
     *
     * There is no case where the lid is closed that the keyboard should stay active.
     **/
    if (lidClosed && !isSuspended) {
        suspend_power_down();
    }

    /* If the lid is open and the system is transitioning between sleep states,
     * QMK automatically handles suspending by monitoring USB suspend state.
     *
     * The only case where we need custom behavior is when the system was awake
     * with lid closed and then the lid is opened. In this case we need to wake
     * the keyboard.
     */
    if (!lidClosed && lidChanged) {
        suspend_wakeup_init();
    }

    // TODO: Try this again later, but for now USB suspend should be fine
    // This seems to cause issues with waking up the host by keypresses
    //  static int host_sleep = 0;
    //  /* reduce the scan speed to 10Hz */
    //  if (prev_asleep != asleep) {
    //      prev_asleep = asleep;
    //      if (!asleep) {
    //          suspend_power_down_quantum();
    //      } else {
    //          suspend_wakeup_init_quantum();
    //      }
    //  }
    //  if (!asleep) {
    //      if (timer_elapsed32(host_sleep) < 100) {
    //          port_wait_for_interrupt();
    //          return true;
    //      } else {
    //          host_sleep = timer_read32();
    //      }
    //  }

    // Ignore keypresses if lid closed
    return lidClosed;
}

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
    isSuspended = true;
    rgbOff;
}

/**
 * Called by QMK when the keyboard wakes up from suspend
 */
void suspend_wakeup_init_kb(void) {
    suspend_wakeup_init_user();
    isSuspended = false;
    rgbOn;
}
