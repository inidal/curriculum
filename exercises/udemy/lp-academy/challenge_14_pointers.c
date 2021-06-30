#include <stdio.h>
#include <stdlib.h>

int main()
{
    int variable = 20;

    int *pvariable = &variable;

    printf("Address of the pointer: %p\n", &pvariable);
    printf("Value of the pointer: %p\n", pvariable);
    printf("Value of what the pointer is pointing to: %d\n", *pvariable);


    return 0;
}
