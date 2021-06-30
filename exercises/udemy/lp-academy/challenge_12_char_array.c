#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Prototyping
int charCounter();
char strConcat();
int areStrEqual();

int main()
{
    char myString[] = "Hello world!"; // 12 chars
    char myString2[] = " And the whole universe!"; // 18 chars

    // Demo: Count characters
    int string_count = charCounter(myString);
    int string_count2 = charCounter(myString2);
    printf("The first string is %d chars longer and the second is %d.\n", string_count, string_count2);

    // Demo: Concatenate two strings
    strConcat(myString, myString2);

    // Demo: Comparing strings if equal
    areStrEqual(myString, myString2);

    return 0;
}

// Function 1: Characters counter
int charCounter(char *input)
{
    int count = 0;

    while (true)
    {
        ++count;
        if (input[count] == '\0')
        {
            break;
        }
    }
    return count;
}

// Function 2: Concatenate two strings
char strConcat(char *input1, char *input2)
{
    // Counting both strings
    int str1 = charCounter(input1);
    int str2 = charCounter(input2);
    int total_length = str1 + str2;

    // Creating an array for both strings
    char *tmp_concat[total_length];

    // Append first string
    for (int i = 0; i < str1; ++i)
    {
        tmp_concat[i] = input1[i];
    }

    // Append second string
    for (int j = 0; j < str2; ++j)
    {
        tmp_concat[str1 + j] = input2[j];
    }

    // Printing concatenated strings
    for (int l = 0; l < total_length; ++l)
    {
        printf("%s", &tmp_concat[l]);

    }

    // Adding a new line
    printf("\n");

    return 0;
}

// Function 3: Check if two strings are equal
int areStrEqual(char *input1, char *input2)
{
    int str1 = charCounter(input1);
    int str2 = charCounter(input2);

    if (str1 == str2)
    {
        printf("Both strings are equal!\n");
    }
    else
    {
        printf("Both strings are NOT equal!\n");
    }

    return 0;
}
