#include <math.h>
#include <string.h>
#include "binary.h"

int32_t convert(const char *input)
{
    uint32_t decimal_value = 0;

    for(uint8_t i = 0; i < strlen(input); i++)
    {
        if(input[i] == '1')
        {
            decimal_value += pow(2, strlen(input) - 1 - i);
        }
        else if(input[i] != '0')
        {
            return INVALID;
        }
    }

    return decimal_value;
}
