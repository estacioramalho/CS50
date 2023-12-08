#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string encrypt (string plaintext, int keyValue);

int main(int argc, string argv[])
{
    // Checks if command line has more than one argument (not including the program name), or no argument at all
    if (argc != 2)
    {
        printf("Invalid key. Please enter a single argument, a non-negative integer.\n");
        return 1;
    }

    // Stores the key and the key length
    string key = argv[1];
    int keyValue = atoi(key);
    int keyLength = strlen(key);

    // Loops through each character of the key to check if it's a non decimal digit
    for (int character = 0; character < keyLength; character++)
    {
        if (!isdigit(key[character]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Prompt for plaintext, convert to cipher and then print it
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: %s\n", encrypt(plaintext, keyValue));

    return 0;
}

string encrypt (string plaintext, int keyValue)
{
    int alphabetLength = 26;
    int textLength = strlen(plaintext);
    string ciphertext = plaintext;

    int oldPosition;
    int newPosition;

    // Loops through each character of the plaintext
    for (int i = 0; i < textLength; i++)
    {
        // Checks if it's a lowercase letter
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            oldPosition = plaintext[i] - 'a';
            newPosition = (oldPosition + keyValue) % alphabetLength;
            ciphertext[i] = 'a' + newPosition;
        }
        // Checks if it's an uppercase letter
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            oldPosition = plaintext[i] - 'A';
            newPosition = (oldPosition + keyValue) % alphabetLength;
            ciphertext[i] = 'A' + newPosition;
        }
        // If not a letter, just add the same symbol to the ciphertext
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    return ciphertext;
}
