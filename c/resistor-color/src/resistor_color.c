#include <stdlib.h>
#include <stdio.h>
#include "resistor_color.h"

#define LENGTH  (WHITE + 1)

resistor_band_t color_code(resistor_band_t color)
{
    return color;
}

resistor_band_t * colors(void)
{
    resistor_band_t *color_array = (resistor_band_t *) malloc(LENGTH * sizeof(resistor_band_t));

    for(resistor_band_t i = 0; i < LENGTH; i++)
    {
        color_array[i] = color_code(i);
    }

    return color_array;
}
