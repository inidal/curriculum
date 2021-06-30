#include <stdio.h>
#include <stdlib.h>

// prototyping
int gcd();
float absValue(float);
float sqrRoot(float);


int main()
{
    printf("GCD: %d\n", gcd(15,35));
    printf("Absolute value: %.2f\n", absValue(-44.55));

    float test_sqrroot = 25.55;
    printf("Square root of %.2f: %f\n", test_sqrroot, sqrRoot(test_sqrroot));

    return 0;
}

// Function 1: Greatest common divisor
int gcd(int num1, int num2)
{
    int result;
    for(int i = 1; i <= num1 && i <= num2; ++i)
        {
            if(num1 % i == 0 && num2 % i == 0)
                result = i;
        }
    return result;
}

// Function 2: Absolute value
float absValue(float num)
{
    if  (num < 0)
    {
        return num * (-1);
    }
    else if (num > 0)
    {
        return num;
    }
    else
    {
        return 0;
    }
}

// Function 3: Square root
float sqrRoot(float num)
{
    float tmp, sqrt;

    sqrt = num / 2;
    tmp = 0;

    while(sqrt != tmp)
    {
        tmp = sqrt;
        sqrt = (num / tmp + tmp) / 2;
    }
}
