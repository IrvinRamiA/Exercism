#include <math.h>
#include "darts.h"

uint8_t score(coordinate_t coordinate)
{
    float vector_magnitude = sqrt(pow(coordinate.x, 2) + pow(coordinate.y, 2));
    
    if(vector_magnitude <= 1)
    {
        return 10;
    }
    else if(vector_magnitude <= 5)
    {
        return 5;
    }
    else if(vector_magnitude <= 10)
    {
        return 1;
    }
    return 0;
}
