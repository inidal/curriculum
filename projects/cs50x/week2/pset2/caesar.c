#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Validation level
    int valid_level = 1;

    // Show usage if arguments are not 2
    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./caesar key\n");
        valid_level--;
        exit(1);
    }

    // Check validation level
    else if (valid_level == 1)
    {
        // Validation key
        int key_check = 0;

        // Calculate number of integers (if any)
        int i;
        for (i = 0; i <= strlen(argv[1]) - 1; i++)

            if ((argv[1][i] >= 48) && (argv[1][i] <= 57))
            {
                key_check += 1;
            }

        // Caesar cipher
        if (key_check == strlen(argv[1]))
        {
            // Convert argv to integer
            int shift = atoi(argv[1]);

            // Convert input string to char
            string gtinput = get_string("plaintext: ");
            char plaintext[strlen(gtinput)];

            for (int k = 0; k <= strlen(gtinput); k++)
            {
                plaintext[k] = gtinput[k];
            }
            char ciphertext[strlen(plaintext)];

            // Ceaser cipher logic (should have used function instead)
            for (int j = 0; j <= strlen(plaintext); j++)
            {
                // If lowercase
                if (plaintext[j] >= 97 && plaintext[j] <= 122)
                {
                    int res;
                    int precalc = (int) plaintext[j] + shift;
                    int calc = precalc - 97;

                    res = calc % 26;
                    ciphertext[j] = 97 + (char) res;
                }

                // If uppercase
                else if (plaintext[j] >= 65 && plaintext[j] <= 90)
                {
                    int res;
                    int precalc = (int) plaintext[j] + shift;
                    int calc = precalc - 65;

                    res = calc % 26;
                    ciphertext[j] = 65 + (char) res;
                }

                // Anything that is not upper or lower case
                else
                {
                    ciphertext[j] = plaintext[j];
                }
            }
            // Printing the cipher text
            printf("ciphertext: %s\n", ciphertext);
        }

        else
        {
            printf("Usage: ./caesar key\n");
        }
    }
}