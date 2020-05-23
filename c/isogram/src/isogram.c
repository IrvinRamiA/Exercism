#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>
#include "isogram.h"

enum
{
    UPPER_CASE_INIT_VALUE = 65,
    LOWER_CASE_INIT_VALUE = 97,
    ALPHABET_LENGTH = 26
};

static bool *letters_checklist;

static void check_letter(char letter)
{
    if(isupper(letter))
    {
        letters_checklist[letter - UPPER_CASE_INIT_VALUE] = true;
    }
    else if(islower(letter))
    {
        letters_checklist[letter - LOWER_CASE_INIT_VALUE] = true;
    }
}

static bool repeated_letter(char letter)
{
    if((islower(letter) && letters_checklist[letter - LOWER_CASE_INIT_VALUE]) ||
        (isupper(letter) && letters_checklist[letter - UPPER_CASE_INIT_VALUE]))
    {
        return true;
    }
    return false;
}

bool is_isogram(const char phrase[])
{
    if (phrase == NULL)
    {
        return false;
    }

    letters_checklist = (bool *) calloc(ALPHABET_LENGTH, sizeof(bool));

    for (uint8_t i = 0; i < strlen(phrase); i++)
    {
        if(isalpha(phrase[i]))
        {
            if(repeated_letter(phrase[i]))
            {
                return false;
            }
            check_letter(phrase[i]);
        }
    }

    return true;
}
