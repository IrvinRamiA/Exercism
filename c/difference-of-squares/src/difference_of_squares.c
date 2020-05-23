#include <math.h>
#include "difference_of_squares.h"

uint32_t sum_of_squares(uint32_t number)
{
    uint32_t sum = 0;

    for(uint32_t i = 1; i <= number; i++)
    {
        sum += pow(i, 2);
    }
    return sum;
}

uint32_t square_of_sum(uint32_t number)
{
    uint32_t sum = 0;

    for(uint32_t i = 1; i <= number; i++)
    {
        sum += i;
    }
    return pow(sum, 2);
}

uint32_t difference_of_squares(uint32_t number)
{
    return square_of_sum(number) - sum_of_squares(number);
}
