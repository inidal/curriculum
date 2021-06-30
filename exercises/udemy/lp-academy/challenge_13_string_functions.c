#include <stdio.h>
#include <stdlib.h>

// Prototyping
char reverseStr();
char sortStr(int);

// Constants needed
#define MAX 100

int main()
{
    // Get input
    printf("Input: ");
    char *get_string[MAX];
    scanf("%s", &get_string);

    // Needed variables
    int stringLength = strlen(get_string);

    // Demo: Reversing the input
    reverseStr(get_string, stringLength);

    // Demo: Sort 3 strings (Bubble sort)
    int *input_number;
    printf("\n\n==================");
    printf("\nNumber of strings: ");
    scanf("%i", &input_number);
    sortStr(input_number);

    return 0;
}

// Function 1: Reversing the input string
char reverseStr(char *input, int length)
{
    for (int i = length; i >= 0; i--)
    {
        printf("%c", input[i]);
    }
    return 0;
}

// Function 2: Bubble Sort 3 strings
char sortStr(int inputs_num)
{
    // Declaring the needed array
    char *input_strings[inputs_num];

    // Inserting strings in array
    for (int i = 0; i < inputs_num; ++i)
    {
        printf("Input %i: ", i + 1);
        scanf("%s", &input_strings[i]);
    }

    // Bubble sort algorithm
    int tmp, i, j;
    for(i = 0; i < inputs_num - 1; i++)
    {
        for(j = 0; j < inputs_num - i - 1; j++)
        {
            if(input_strings[j] > input_strings[j + 1])
            {
                tmp = input_strings[j];
                input_strings[j] = input_strings[j + 1];
                input_strings[j + 1] = tmp;
            }
        }
    }

    // Print array
    printf("\n===== Sorted =====\n");
    for (int i = 0; i < inputs_num; ++i)
    {
        printf("Output: %s\n", &input_strings[i]);
    }
    return 0;
}