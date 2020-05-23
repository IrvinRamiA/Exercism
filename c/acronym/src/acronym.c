#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "acronym.h"

static bool there_is_a_space_or_dash(char character)
{
    return character == ' ' || character == '-';
}

char * abbreviate(const char *phrase)
{
    if(phrase == NULL || strncmp(phrase, "", 1) == 0)
    {
        return NULL;
    }

    char *phrase_acronym = (char *) malloc(sizeof(char));
    bool space_flag = false;
    uint8_t acronym_index = 0;

    for(uint8_t i = 0; i < strlen(phrase); i++)
    {
        if(isalpha(phrase[i]))
        {
            if(i == 0)
            {
                phrase_acronym[acronym_index] = toupper(phrase[i]);
            }
            else if(space_flag)
            {
                space_flag = false;
                phrase_acronym[++acronym_index] = toupper(phrase[i]);
            }
        }
        else if(there_is_a_space_or_dash(phrase[i]))
        {
            space_flag = true;
        }        
    }

    return phrase_acronym; 
}
