#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char alphabets[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char alphabets_c[26];

int main(int argc, char *argv[])
{
    // if key entirely valid
    int all_valid = 0;

    // check arguments count (must be 2)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }

    // check length of the key (must be 26 chars)
    else if ((unsigned int)(strlen(argv[1])) != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }

    // check if chars are letters
    string key = argv[1];
    int check_alpha = 0;
    for (int k = 0; k <= strlen(argv[1]); k++)
    {
        if (isalpha(key[k]) != 0)
        {
            check_alpha++;
        }
    }

    // check duplicates
    int check_duplicate = 0;

    // count duplicates
    int count;

    // counting characters in key
    for (int d = 0; d < strlen(key); d++)
    {
        count = 1;
        for (int j = d + 1; j < strlen(key); j++)
        {
            if (key[d] == key[j] && key[d] != ' ')
            {
                count++;
                key[j] = '0';
            }
        }
        if (count > 1 && key[d] != '0')
        {
            check_duplicate++;
            printf("Your key should not contain duplicates.\n");
            exit(1);
        }
    }

    // compare length of key with the checked char
    if (check_alpha == strlen(key))
    {
        all_valid++;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }

    // transfer key to array (in order to cipher)
    for (int i = 0; i <= strlen(alphabets); i++)
    {
        alphabets_c[i] = toupper(key[i]);
    }

    // get plaintext from user
    string plaintext = get_string("plaintext: ");
    char ciphertext[strlen(plaintext)];

    // cipher char by char
    for (int t = 0; t <= strlen(plaintext); t++)
    {
        if (plaintext[t] >= 97 && plaintext[t] <= 122) // lowercase
        {
            for (int j = 0; j <= strlen(alphabets); j++)
            {
                if (toupper(plaintext[t]) == alphabets[j])
                {
                    ciphertext[t] = tolower(alphabets_c[j]);
                }
            }
        }

        else if (plaintext[t] >= 65 && plaintext[t] <= 90) // uppercase
        {
            for (int j = 0; j <= strlen(alphabets); j++)
            {
                if (plaintext[t] == alphabets[j])
                {
                    ciphertext[t] = alphabets_c[j];
                }
            }
        }

        else // punctuation marks, spaces, etc...
        {
            ciphertext[t] = plaintext[t];
        }
    }

    // print cipher text
    printf("ciphertext: %s\n", ciphertext);
}