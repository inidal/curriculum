#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Generating an array with numbers from 1 to 100
    int numbers[98];

    for (int i = 1; i <= 100; i++)
    {
        numbers[i - 1] = i;

    }

    // Printing prime numbers from the array 'numbers'
    for (int j = 1; j <= 98; j++)
    {
        //printf("%d ", numbers[j]);
        int flag = 0;
        for(int i = 2; i <= numbers[j] / 2; i++)
        {
            // Not prime
            if(numbers[j] % i == 0)
            {
            flag = 1;
            break;
            }
        }
        // Prime
        if(flag == 0)
        printf("%d ", numbers[j]);
    }

    return 0;
}
