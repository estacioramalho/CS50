#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int startingPopulation;
    do
    {
        startingPopulation = get_int("Starting population: ");
    }
    while (startingPopulation < 9);

    // Prompt for end size
    int targetPopulation;
    do
    {
        targetPopulation = get_int("Target population: ");
    }
    while (targetPopulation < startingPopulation);

    // Initialize current population and years elapsed
    int currentPopulation = startingPopulation;
    int yearsElapsed = 0;

    // If starting and target population are the same, print years: 0
    if (startingPopulation == targetPopulation)
    {
        printf("Years: 0\n");
    }
    else
    {
        // Calculate number of years until we reach target population
        do
        {
            int currentBirthRate = currentPopulation / 3;
            int currentDeathRate = currentPopulation / 4;

            currentPopulation += currentBirthRate - currentDeathRate;

            yearsElapsed++;
        }
        while(currentPopulation < targetPopulation);

        // Print number of years
        printf("Years: %i\n", yearsElapsed);
    }
}
