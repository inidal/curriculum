#include <stdio.h>
#include <stdlib.h>

int sqrNumber();

int main()
{
    int input = 5; // 27

    printf("%d", sqrNumber(input));

    return 0;
}

int sqrNumber(int *number)
{

    int *n = &number;
    int square = *n;
    int tmp = *n;
    int result = 0;


    for (int i = 1; i < square; ++i)
    {
        result  = tmp * square;
        tmp = result;

    }

    return result;
}