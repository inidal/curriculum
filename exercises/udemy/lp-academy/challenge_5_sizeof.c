#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Size of int: %i.\n", (int) sizeof(int));
    printf("Size of char: %i.\n", (int) sizeof(char));
    printf("Size of long: %i.\n", (int) sizeof(long));
    printf("Size of long long: %i.\n", (int) sizeof(long long));
    printf("Size of double: %i.\n", (int) sizeof(double));
    printf("Size of long double: %i.\n", (int) sizeof(long double));

    return 0;
}
