#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Get length input
    int length_input = 0;
    printf("Length of the input: ");
    scanf("%d", &length_input);

    // Create pointer and malloc needed memory
    char* ptr;
    ptr = (char*) malloc(length_input * sizeof(char));

    // Get input
    printf("Type a string: ");
    scanf("%s", ptr);

    // Count and print chars
    printf("\nString stored is '");
    int count = 0;
    while (*ptr != '\0')
    {
        ++count;
        printf("%c", *ptr);
        ++ptr;
    }
    printf("' and the length of it is '%d'.\n", count);

    // Freeing the goddamn memory
    free(ptr);

    return 0;
}
