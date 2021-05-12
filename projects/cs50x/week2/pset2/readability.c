#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Setting up needed variables
    int i, length;
    float letters = 0;
    float words = 1;
    float sentences = 0;

    // Getting input from user
    string input = get_string("Text: ");

    // Processing each character in the input
    for (i = 0, length = strlen(input); i < length; i++)
    {
        // letters
        if (((unsigned)input[i] >= 65 && (unsigned)input[i] <= 90) || ((unsigned)input[i] >= 97 && (unsigned)input[i] <= 122))
        {
            letters++;
        }

        // words
        else if ((unsigned)input[i] == 32)
        {
            words++;
        }

        // sentences
        else if ((unsigned)input[i] == 33 || (unsigned)input[i] == 46 || (unsigned)input[i] == 63)
        {
            sentences++;
        }
    }

    // Readability test: Coleman-Liau index
    int score = round(0.0588 * ((letters / words) * 100) - 0.296 * ((sentences / words) * 100) - 15.8);

    // Returning Grade level
    if (score > 16)
    {
        printf("Grade 16+\n");
    }
    else if (score <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", score);
    }
}
