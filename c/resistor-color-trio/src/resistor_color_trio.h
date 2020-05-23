#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <stdint.h>

typedef enum
{
    OHMS = 1,
    KILOOHMS = 1000
} unit_t;

typedef struct
{
    uint32_t value;
    unit_t unit;
} resistor_value_t;

typedef enum
{
    BLACK, 
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

resistor_value_t color_code(resistor_band_t resistor_band[]);

#endif
