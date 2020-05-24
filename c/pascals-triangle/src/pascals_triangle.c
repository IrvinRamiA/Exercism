#include <stdbool.h>
#include "pascals_triangle.h"

void free_triangle(size_t **triangle, uint8_t length)
{
    for(uint8_t i = 0; i < length; i++)
    {
        free(triangle[i]);
    }
    free(triangle);
}

size_t ** create_triangle(int8_t length)
{
    if(length < 0)
    {
        return NULL;
    }
    
    bool zero_flag = false;
    if(length == 0)
    {
        length = 1;
        zero_flag = true;
    }

    size_t **triangle = (size_t **) calloc(length, sizeof(size_t *));

    for(uint8_t i = 0; i < length; i++)
    {
        triangle[i] = (size_t *) calloc(length, sizeof(size_t));
    }

    for(uint8_t i = 0; i < length; i++)
    {
        for(uint8_t j = 0; j < length; j++)
        {
            if((j == 0 || i == j) && !zero_flag)
            {
                triangle[i][j] = 1;
            }
            else if(i > j)
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; 
            }
        }
    }

    return triangle;
}
