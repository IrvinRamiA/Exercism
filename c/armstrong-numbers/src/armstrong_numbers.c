#include <math.h>
#include "armstrong_numbers.h"

static uint8_t get_number_of_digits(uint32_t candidate)
{
    if (candidate == 0)
    {
        return 1;
    }

    uint32_t divisor = 1;
    uint8_t counter = 0;

    while (candidate / divisor >= 1)
    {
        counter++;
        divisor *= 10;
    }

    return counter;
}

static uint8_t extract_more_significant_digit(uint32_t candidate)
{
    uint32_t divisor = 1;
    uint8_t digit = 0;

    while (candidate / divisor >= 10)
    {
        divisor *= 10;
    }

    digit = candidate / divisor;

    return digit;
}

bool is_armstrong_number(uint32_t candidate)
{
    uint8_t numberOfDigits = 0;
    uint8_t iteratorOfDigits = 0; 
    uint32_t sum = 0;
    uint8_t currentDigit = 0;
    uint32_t candidateCopy = candidate;

    numberOfDigits = get_number_of_digits(candidate);
    iteratorOfDigits = numberOfDigits;

    while (iteratorOfDigits)
    {
        currentDigit = extract_more_significant_digit(candidateCopy);
        candidateCopy -= currentDigit * pow(10, get_number_of_digits(candidateCopy) - 1);
        sum += pow(currentDigit, numberOfDigits);
        iteratorOfDigits--;
    }

    if (sum == candidate)
    {
        return true;
    }

    return false;
}
