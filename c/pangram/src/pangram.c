#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include "pangram.h"

enum
{
    ALPHA_LENGTH = 26,
    LOWER_CASE_INIT_VALUE = 97,
    UPPER_CASE_INIT_VALUE = 65
};

bool is_pangram(const char *sentence)
{
    if(sentence == NULL || strncmp(sentence, "", 1) == 0)
    {
        return false;
    }

    uint8_t * alpha_check = (uint8_t *) calloc(ALPHA_LENGTH, sizeof(uint8_t));

    for(uint8_t i = 0; i < strlen(sentence); i++)
    {
        if(isalpha(sentence[i]))
        {
            if(islower(sentence[i]))
            {
                alpha_check[sentence[i] - LOWER_CASE_INIT_VALUE]++; 
            }
            else if(isupper(sentence[i]))
            {
                alpha_check[sentence[i] - UPPER_CASE_INIT_VALUE]++; 
            }
        }
    }

    for(uint8_t i = 0; i < ALPHA_LENGTH; i++)
    {
        if(alpha_check[i] == 0)
        {
            return false;
        }
    }

    return true;
}
