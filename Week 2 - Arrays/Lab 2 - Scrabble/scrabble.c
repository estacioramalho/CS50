#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    }

    else if (score2 > score1) {
        printf("Player 2 wins!\n");
    }

    else if (score1 == score2) {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int wordLenght = strlen(word);
    char letter;
    int score = 0;

    // Loops through each letter of the word
    for (int letterPosition = 0; letterPosition < wordLenght; letterPosition++)
    {
        letter = word[letterPosition];

        // Check if it's an uppercase letter and score
        if (letter >= 'A' && letter <= 'Z')
        {
            score += POINTS[(letter - 65)];
        }

        // Check if it's a lowercase letter and score
        else if (letter >= 'a' && letter <= 'z')
        {

            score+= POINTS[(letter - 97)];
        }
    }
    return score;
}