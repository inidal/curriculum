#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Declaring and assigning the payrate and the number of worked hours
    int payrate = 12;
    int worked_hours;
    int hours_a, hours_b, result;

    // Ask for input (hours worked)
    printf("Number of worked hours: ");
    scanf("%d", &worked_hours);

    // A: Calculating the worked hours if greater than 40 (overtime)
    if (worked_hours > 40)
    {
        hours_a = 40 * payrate;
        hours_b = (worked_hours - 40) * (payrate * 1.5);
        result = hours_a + hours_b;
    }

    // A: Calculating if no overtime
    else if (worked_hours <= 40)
    {
        result = worked_hours * 12;
    }

    // result = 480
    // B: Calculating the tax rate depending on the result of the previous operation
    double tax_1 = 300 - (300 * 0.15);
    double tax_2 = 150 - (150 * 0.2);

    if (result > 450)
    {
        int tmp = result - 450;
        double tax_3 = tmp - (tmp * 0.25);

        double net_pay = tax_1 + tax_2 + tax_3;
        printf("Net pay: %f", net_pay);
    }

    else if (result > 300)
    {
        if (result < 450)
        {
            int tmp = result - 300;
            double net_pay = tax_1 + tmp;
            printf("Net pay: %f", net_pay);
        }

        else if (result == 450)
        {
            double net_pay = tax_1 + tax_2;
            printf("Net pay: %f", net_pay);
        }
    }

    else if (result <= 300)
    {
        if (result == 300)
        {
            printf("Net pay: %f", tax_1);
        }

        else
        {
            printf("Net pay: %i", result);
        }
    }

    return 0;
}
