#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int s, e;

    // TODO: Prompt for start size
    do
    {
        s = get_int("Start size? ");
    } while (s < 9);

    // TODO: Prompt for e size
    do
    {
        e = get_int("End size? ");
    } while ((e + 1) <= s);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (s < e)
    {
        s = (s + (s / 3) - (s / 4));
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}