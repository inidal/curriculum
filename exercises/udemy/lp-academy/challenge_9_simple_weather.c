#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Data of 5 years
    float rainfall[5][12] = {
    {9.8, 9.3, 5.4, 11.4, 9.6, 10.1, 1.4, 11.2, 14.6, 8.6, 4.5, 7.3},
    {6.1, 7.8, 13.9, 5.8, 4, 4, 6.1, 9.7, 14.1, 12.3, 5.1, 9.6},
    {5.2, 8, 9.9, 10.3, 3.5, 5, 10.6, 2.3, 7.6, 9.3, 12.6, 5.4},
    {4.7, 7.9, 13.3, 11.4, 9.8, 9.6, 3.9, 6.7, 9.7, 8.1, 14.6, 6.7},
    {9.7, 2.8, 6.1, 10.5, 8.7, 12.8, 9, 11.1, 0.2, 0.5, 6.1, 10}
    };

    // Needed variables
    float avg_allyears;
    float avg_bymonth[12];

    // First block of output
    printf("YEAR  RAINFALL (inches)\n");

    for (int i = 0; i < 5; i++)
    {
        float avg_year = 0;
        int year = 2010;

        for (int k = 0; k < 12; k++)
        {
             avg_year += rainfall[i][k];
             avg_bymonth[k] += rainfall[i][k];


             if (k == 11)
             {
                 printf("%i  %f\n", (year + i), avg_year);
                 avg_allyears += avg_year;
             }

        }
    }

    // Second block of output
    printf("\n\nThe yearly average is %f inches.\n\n", (avg_allyears / 5));

    // Third block of output
    printf("--------------------\n");
    printf("  MONTHLY AVERAGES\n");
    printf("--------------------\n");
    printf("|JAN   |FEB   |MAR   |APR   |MAY   |JUNE  |JULY  |AUG   |SEPT  |OCT   |NOV   |DEC\n");
    for (int l = 0; l < 12; l++)
    {

        printf("|%.2f ", avg_bymonth[l]);
    }
    printf("\n");

    return 0;
}
