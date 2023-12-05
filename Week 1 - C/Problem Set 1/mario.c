#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int targetDimension;

    // Get the target height from the user and set it as the target dimension
    do
    {
        targetDimension = get_int("Target height: ");
    }
    while (targetDimension < 1 || targetDimension > 8);

    // Loop the rows, counting from top to bottom
    for (int currentRow = targetDimension; currentRow > 0; currentRow--)
    {
        // Loop the columns, counting from left to right
        for (int currentColumn = 1; currentColumn <= targetDimension; currentColumn++)
        {
            // Decide if the space of the column of the row is going to have a brick or be empty
            if (currentColumn >= currentRow)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        // Jump to a new line at the end of each row
        printf("\n");
    }
}