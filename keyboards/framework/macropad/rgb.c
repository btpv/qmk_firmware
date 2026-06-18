#include QMK_KEYBOARD_H
#define IS31FL3743A_ENABLE_GPIO GP29

#define LED_0 {0, SW1_CS3, SW1_CS2, SW1_CS1}
#define LED_1 {0, SW2_CS3, SW2_CS2, SW2_CS1}
#define LED_2 {0, SW3_CS3, SW3_CS2, SW3_CS1}
#define LED_3 {0, SW4_CS3, SW4_CS2, SW4_CS1}
#define LED_4 {0, SW1_CS6, SW1_CS5, SW1_CS4}
#define LED_5 {0, SW3_CS6, SW3_CS5, SW3_CS4}
#define LED_6 {0, SW4_CS6, SW4_CS5, SW4_CS4}
#define LED_7 {0, SW2_CS6, SW2_CS5, SW2_CS4}
#define LED_8 {0, SW1_CS9, SW1_CS8, SW1_CS7}
#define LED_9 {0, SW2_CS9, SW2_CS8, SW2_CS7}
#define LED_10 {0, SW3_CS9, SW3_CS8, SW3_CS7}
#define LED_11 {0, SW4_CS9, SW4_CS8, SW4_CS7}
#define LED_12 {0, SW1_CS12, SW1_CS11, SW1_CS10}
#define LED_13 {0, SW2_CS12, SW2_CS11, SW2_CS10}
#define LED_14 {0, SW3_CS12, SW3_CS11, SW3_CS10}
#define LED_15 {0, SW4_CS12, SW4_CS11, SW4_CS10}
#define LED_16 {0, SW2_CS15, SW2_CS14, SW2_CS13}
#define LED_17 {0, SW3_CS15, SW3_CS14, SW3_CS13}
#define LED_18 {0, SW1_CS15, SW1_CS14, SW1_CS13}
#define LED_19 {0, SW4_CS15, SW4_CS14, SW4_CS13}
#define LED_20 {0, SW1_CS18, SW1_CS17, SW1_CS16}
#define LED_21 {0, SW2_CS18, SW2_CS17, SW2_CS16}
#define LED_22 {0, SW3_CS18, SW3_CS17, SW3_CS16}
#define LED_23 {0, SW4_CS18, SW4_CS17, SW4_CS16}

void keyboard_pre_init_kb(void) {
    keyboard_pre_init_user();
    gpio_set_pin_output(IS31FL3743A_ENABLE_GPIO);
    gpio_write_pin_high(IS31FL3743A_ENABLE_GPIO);
}

const is31fl3743a_led_t PROGMEM g_is31fl3743a_leds[RGB_MATRIX_LED_COUNT] = {
    /* Refer to IS31 manual for these locations
     *   driver
     *   |   R location
     *   |   |         G location
     *   |   |         |         B location
     *   |   |         |         | */
    // Re-arranged in LED ID order so it matches with the physical location array
    LED_5, LED_2, LED_22, LED_17, LED_4, LED_0, LED_20, LED_18, LED_7, LED_1, LED_21, LED_16, LED_6, LED_3, LED_23, LED_19, LED_9, LED_11, LED_15, LED_13, LED_8, LED_10, LED_14, LED_12};

led_config_t g_led_config = {
    {// Key Matrix to LED Index
     {0, 1, 2, 3},
     {4, 5, 6, 7},
     {8, 9, 10, 11},
     {12, 13, 14, 15},
     {16, 17, 18, 19},
     {20, 21, 22, 23}},
    {
        // LED Index to Physical Position
        {0, 0},  {73, 0},  {150, 0},  {223, 0},

        {0, 10}, {73, 10}, {150, 10}, {223, 10},

        {0, 24}, {73, 24}, {150, 24}, {223, 24},

        {0, 37}, {73, 37}, {150, 37}, {223, 37},

        {0, 50}, {73, 50}, {150, 50}, {223, 50},

        {0, 64}, {73, 64}, {150, 64}, {223, 64},
    },
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4} // LED Index to Flag
};
