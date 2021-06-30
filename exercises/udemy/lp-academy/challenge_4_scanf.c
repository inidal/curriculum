#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare and store minutes input
    int minutes;

    // Input from user
    printf("Minutes: ");
    scanf("%d", &minutes);

    // Calculation of days and years
    double days = minutes / 1440.0;
    double years = days / 365;

    // Print the result
    printf("\nThe number of minutes you entered is equivalent to %f in days or %f in years.\n", days, years);

    return 0;
}
