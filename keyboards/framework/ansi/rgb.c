#include <quantum.h>
#include "rgb.h"

/* =========================================================
 * LEFT DRIVER (0x20)
 * ========================================================= */

#define LED_0 {0, SW1_CS3, SW1_CS2, SW1_CS1}
#define LED_1 {0, SW2_CS3, SW2_CS2, SW2_CS1}
#define LED_2 {0, SW3_CS3, SW3_CS2, SW3_CS1}
#define LED_3 {0, SW4_CS3, SW4_CS2, SW4_CS1}
#define LED_4 {0, SW5_CS3, SW5_CS2, SW5_CS1}
#define LED_5 {0, SW6_CS3, SW6_CS2, SW6_CS1}
#define LED_6 {0, SW7_CS3, SW7_CS2, SW7_CS1}
#define LED_7 {0, SW8_CS3, SW8_CS2, SW8_CS1}

#define LED_8 {0, SW1_CS6, SW1_CS5, SW1_CS4}
#define LED_9 {0, SW2_CS6, SW2_CS5, SW2_CS4}
#define LED_10 {0, SW3_CS6, SW3_CS5, SW3_CS4}
#define LED_11 {0, SW4_CS6, SW4_CS5, SW4_CS4}
#define LED_12 {0, SW5_CS6, SW5_CS5, SW5_CS4}
#define LED_13 {0, SW6_CS6, SW6_CS5, SW6_CS4}
#define LED_14 {0, SW7_CS6, SW7_CS5, SW7_CS4}
#define LED_15 {0, SW8_CS6, SW8_CS5, SW8_CS4}

#define LED_16 {0, SW1_CS9, SW1_CS8, SW1_CS7}
#define LED_17 {0, SW2_CS9, SW2_CS8, SW2_CS7}
#define LED_18 {0, SW3_CS9, SW3_CS8, SW3_CS7}
#define LED_19 {0, SW4_CS9, SW4_CS8, SW4_CS7}
#define LED_20 {0, SW5_CS9, SW5_CS8, SW5_CS7}
#define LED_21 {0, SW6_CS9, SW6_CS8, SW6_CS7}
#define LED_22 {0, SW7_CS9, SW7_CS8, SW7_CS7}
#define LED_23 {0, SW8_CS9, SW8_CS8, SW8_CS7}

#define LED_24 {0, SW1_CS12, SW1_CS11, SW1_CS10}
#define LED_25 {0, SW2_CS12, SW2_CS11, SW2_CS10}
#define LED_26 {0, SW3_CS12, SW3_CS11, SW3_CS10}
#define LED_27 {0, SW4_CS12, SW4_CS11, SW4_CS10}
#define LED_28 {0, SW5_CS12, SW5_CS11, SW5_CS10}
#define LED_29 {0, SW6_CS12, SW6_CS11, SW6_CS10}
#define LED_30 {0, SW7_CS12, SW7_CS11, SW7_CS10}
#define LED_31 {0, SW8_CS12, SW8_CS11, SW8_CS10}

/* =========================================================
 * RIGHT DRIVER (0x23)
 * ========================================================= */

#define LED_32 {1, SW1_CS3, SW1_CS2, SW1_CS1}
#define LED_33 {1, SW2_CS3, SW2_CS2, SW2_CS1}
#define LED_34 {1, SW3_CS3, SW3_CS2, SW3_CS1}
#define LED_35 {1, SW4_CS3, SW4_CS2, SW4_CS1}
#define LED_36 {1, SW5_CS3, SW5_CS2, SW5_CS1}
#define LED_37 {1, SW6_CS3, SW6_CS2, SW6_CS1}
#define LED_38 {1, SW7_CS3, SW7_CS2, SW7_CS1}
#define LED_39 {1, SW8_CS3, SW8_CS2, SW8_CS1}

#define LED_40 {1, SW1_CS6, SW1_CS5, SW1_CS4}
#define LED_41 {1, SW2_CS6, SW2_CS5, SW2_CS4}
#define LED_42 {1, SW3_CS6, SW3_CS5, SW3_CS4}
#define LED_43 {1, SW4_CS6, SW4_CS5, SW4_CS4}
#define LED_44 {1, SW5_CS6, SW5_CS5, SW5_CS4}
#define LED_45 {1, SW6_CS6, SW6_CS5, SW6_CS4}
#define LED_46 {1, SW7_CS6, SW7_CS5, SW7_CS4}
#define LED_47 {1, SW8_CS6, SW8_CS5, SW8_CS4}

#define LED_48 {1, SW1_CS9, SW1_CS8, SW1_CS7}
#define LED_49 {1, SW2_CS9, SW2_CS8, SW2_CS7}
#define LED_50 {1, SW3_CS9, SW3_CS8, SW3_CS7}
#define LED_51 {1, SW4_CS9, SW4_CS8, SW4_CS7}
#define LED_52 {1, SW5_CS9, SW5_CS8, SW5_CS7}
#define LED_53 {1, SW6_CS9, SW6_CS8, SW6_CS7}
#define LED_54 {1, SW7_CS9, SW7_CS8, SW7_CS7}
#define LED_55 {1, SW8_CS9, SW8_CS8, SW8_CS7}

#define LED_56 {1, SW1_CS12, SW1_CS11, SW1_CS10}
#define LED_57 {1, SW2_CS12, SW2_CS11, SW2_CS10}
#define LED_58 {1, SW3_CS12, SW3_CS11, SW3_CS10}
#define LED_59 {1, SW4_CS12, SW4_CS11, SW4_CS10}
#define LED_60 {1, SW5_CS12, SW5_CS11, SW5_CS10}
#define LED_61 {1, SW6_CS12, SW6_CS11, SW6_CS10}
#define LED_62 {1, SW7_CS12, SW7_CS11, SW7_CS10}
#define LED_63 {1, SW8_CS12, SW8_CS11, SW8_CS10}

const is31fl3743a_led_t PROGMEM g_is31fl3743a_leds[RGB_MATRIX_LED_COUNT] =
    {
        /* Refer to IS31 manual for these locations
         *   driver
         *   |   R location
         *   |   |         G location
         *   |   |         |         B location
         *   |   |         |         | */
        // Re-arranged in LED ID order so it matches with the physical location array
        LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_10, LED_11, LED_12, LED_13, LED_14, LED_15, LED_16, LED_17, LED_18, LED_19, LED_20, LED_21, LED_22, LED_23, LED_24, LED_25, LED_26, LED_27, LED_28, LED_29, LED_30, LED_31, LED_32, LED_33, LED_34, LED_35, LED_36, LED_37, LED_38, LED_39, LED_40, LED_41, LED_42, LED_43, LED_44, LED_45, LED_46, LED_47, LED_48, LED_49, LED_50, LED_51, LED_52, LED_53, LED_54, LED_55, LED_56, LED_57, LED_58, LED_59, LED_60, LED_61, LED_62, LED_63
    };

led_config_t g_led_config = {
    /* =========================================================
     * 1) MATRIX → LED INDEX
     * (ANSI-style 6 rows × split halves)
     * ========================================================= */

    {
        /* Row 0 */
        {0, 1, 2, 3, 4, 5, 6, 7,      32, 33, 34, 35, 36, 37, 38, 39},

        /* Row 1 */
        {8, 9, 10, 11, 12, 13, 14, 15, 40, 41, 42, 43, 44, 45, 46, 47},

        /* Row 2 */
        {16, 17, 18, 19, 20, 21, 22, 23, 48, 49, 50, 51, 52, 53, 54, 55},

        /* Row 3 */
        {24, 25, 26, 27, 28, 29, 30, 31, 56, 57, 58, 59, 60, 61, 62, 63},

        /* Row 4 (modifiers / partial keys) */
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,
         NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},

        /* Row 5 (spacebar / extra keys) */
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,
         NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
    },

    /* =========================================================
     * 2) LED INDEX → PHYSICAL POSITION (x, y)
     * ========================================================= */

    {
        /* LEFT SIDE */
        {0,0},   {18,0},  {36,0},  {54,0},  {72,0},  {90,0},  {108,0}, {126,0},

        {0,12},  {18,12}, {36,12}, {54,12}, {72,12}, {90,12}, {108,12}, {126,12},

        {0,24},  {18,24}, {36,24}, {54,24}, {72,24}, {90,24}, {108,24}, {126,24},

        {0,36},  {18,36}, {36,36}, {54,36}, {72,36}, {90,36}, {108,36}, {126,36},

        /* RIGHT SIDE */
        {160,0}, {178,0}, {196,0}, {214,0}, {232,0}, {250,0}, {268,0}, {286,0},

        {160,12},{178,12},{196,12},{214,12},{232,12},{250,12},{268,12},{286,12},

        {160,24},{178,24},{196,24},{214,24},{232,24},{250,24},{268,24},{286,24},

        {160,36},{178,36},{196,36},{214,36},{232,36},{250,36},{268,36},{286,36},
    },

    /* =========================================================
     * 3) FLAGS (all normal keys = 4)
     * ========================================================= */

    {
        4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,

        4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4
    }
};
