#include "resistor_color_duo.h"

#define TWO_BAR_LENGTH  2   

uint16_t color_code(resistor_band_t resistor_band[])
{
    uint16_t value = 0;

    for(uint8_t i = 0; i < TWO_BAR_LENGTH; i++)
    {
        value += (uint16_t) resistor_band[i];
        
        if(i == 0)
        {
            value *= 10;
        }
    }

    return value;
}
