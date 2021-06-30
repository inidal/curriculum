#include <stdio.h>
#include <stdlib.h>

int calcLengh();

int main()
{
    // Input string
    char input[] = "Hello world!"; // 12 chars

    // Calculating length of the string
    printf("Length of the string: %d.", calcLengh(input));


    return 0;
}

int calcLengh(const char *pstring)
{
    int count = 0;
    while (*(pstring++))
    {
        ++count;
    }
    return count;
}
