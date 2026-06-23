// !!! DO NOT ADD #pragma once !!! //
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
#include "color.h"
RGB_MATRIX_EFFECT(user_map)
// #define RGB_MATRIX_CUSTOM_EFFECT_IMPLS
// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#define scale(c) c.r *(brightness / divider), (c.g * brightness) / divider, (c.b * brightness) / divider
// rgb_matrix_set_color(i, scale(c));
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#include <rgbEffect.h>
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
