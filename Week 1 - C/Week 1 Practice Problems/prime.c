#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // Get minimium value
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // Get maximum value
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Loop from minimum to maximum while checking if it's a prime number
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

// Check if the number is a prime number by dividing it and checking if it has no remainder
// Also checks the square root of a number to avoid repetition
bool prime(int number)
{
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
