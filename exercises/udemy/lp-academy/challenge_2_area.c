#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaring and assigning variables
    double width = 25.45;
    double height = 33.95;
    double perimeter = (height + width) * 2;
    double area = width * height;

    // Printing the result of the calculation
    printf("- Printing Perimeter:\n");
    printf("Height: %.2lf\nWidth: %.2lf\nPerimeter: %.2lf\n\n", height, width, perimeter);

    printf("- Printinf Area:\n");
    printf("Height: %.2lf\nWidth: %.2lf\nArea: %.2lf\n", height, width, area);

    return 0;
}