#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get input from user
    int prompt;
    do
    {
        prompt = get_int("Height: ");
    } while (prompt > 8 || prompt < 1);

    // Print rows
    int row, space, hash;
    for (row = 1; row <= prompt; row++)
    {
        for (space = 0; space < (prompt - row); space++)
        {
            // Printing spaces
            do
            {
                printf(" ");
                break;
            } while (prompt > space);
        }

        for (hash = 1; hash <= row; hash++)
        {
            // Printing hashes
            do
            {
                printf("#");
                break;
            } while (prompt > space);
        }
        // Return to line
        printf("\n");
    }
}