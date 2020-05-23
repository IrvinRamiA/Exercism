#include <math.h>
#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t resistor_band[])
{
    resistor_value_t resistor_value;

    resistor_value.value = resistor_band[0] * 10 + resistor_band[1];
    resistor_value.value *= pow(10, resistor_band[2]);
    
    if(resistor_value.value < KILOOHMS)
    {
        resistor_value.unit = OHMS; 
    }
    else
    {
        resistor_value.value /= KILOOHMS;
        resistor_value.unit = KILOOHMS;
    }

    return resistor_value;
}
