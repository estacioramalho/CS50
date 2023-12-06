#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Converts a message to emoji representation
void convertToEmoji(string message);

int main(void)
{
    // Asks for input
    string message = get_string("Type your message: ");

    // Convert each character of the message to emoji
    convertToEmoji(message);
}

void convertToEmoji(string message)
{
    int messageLength = strlen(message);
    int asciiValue;
    char binaryRow[9];

    for (int currentCharacter = 0; currentCharacter < messageLength; currentCharacter++)
    {
        asciiValue = message[currentCharacter];

        // Convert ASCII value to binary
        for (int currentBit = 8; currentBit >= 0; currentBit--)
        {
            binaryRow[7 - currentBit] = (asciiValue & (1 << currentBit)) ? '1' : '0';
            binaryRow[8] = '\0';
        }

        // Print emoji representation of binary
        for (int currentBit= 0; currentBit <= 7; currentBit++)
        {
            if (binaryRow[currentBit] == '0')
            {
                printf("\U000026AB");
            }
            else if (binaryRow[currentBit] == '1')
            {
                printf("\U0001F7E1");
            }
        }
        printf("\n");
    }
}