#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    // Takes a text as input and calculates the grade
    string text = get_string("Enter your text: ");
    int grade = count_letters(text);

    // Prints the grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int textLength = strlen(text);

    float letterCount = 0;
    float wordCount = 1;
    float sentenceCount = 0;

    // Loops through each character in the text to count letters, words, and sentences
    for (int character = 0; character < textLength; character++)
    {
        char currentCharacter = text[character];

        if ((currentCharacter >= 'a' && currentCharacter <= 'z') || (currentCharacter >= 'A' && currentCharacter <= 'Z'))
        {
            letterCount++;
        }
        else if (currentCharacter == ' ')
        {
            wordCount++;
        }
        else if (currentCharacter == '.' || currentCharacter == '!' || currentCharacter == '?')
        {
            sentenceCount++;
        }
    }

    // Calculates the grade using the Coleman-Liau index
    float averageLetters = letterCount / wordCount * 100;
    float averageSentences = sentenceCount / wordCount * 100;

    int grade = round(0.0588 * averageLetters - 0.296 * averageSentences - 15.8);

    return grade;
}
