#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "armstrong_numbers.h"

static int get_number_of_digits(int candidate)
{
    if (candidate == 0)
    {
        return 1;
    }

    int divisor = 1;
    int counter = 0;

    while (candidate / divisor >= 1)
    {
        counter++;
        divisor *= 10;
    }

    return counter;
}

static int extract_digit(int candidate)
{
    int divisor = 1;
    int digit = 0;

    while (candidate / divisor >= 10)
    {
        divisor *= 10;
    }

    digit = candidate / divisor;

    return digit;
}

int is_armstrong_number(int candidate)
{
    int numberOfDigits = 0;
    int iteratorOfDigits = 0; 
    int sum = 0;
    int currentDigit = 0;
    int candidateCopy = candidate;

    numberOfDigits = get_number_of_digits(candidate);
    iteratorOfDigits = numberOfDigits;

    while (iteratorOfDigits)
    {
        currentDigit = extract_digit(candidateCopy);
        candidateCopy -= currentDigit * pow(10, get_number_of_digits(candidateCopy) - 1);
        sum += pow(currentDigit, numberOfDigits);
        iteratorOfDigits--;
    }

    if (sum == candidate)
    {
        return 1;
    }

    return 0;
}
