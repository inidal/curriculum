#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Coins available
    int c25 = 25;
    int c10 = 10;
    int c5 = 5;
    int c1 = 1;

    // Get input from user
    float input_user;
    do
    {
        input_user = get_float("Change owed: ");
    } while (input_user < 0);

    int owed = round(input_user * 100);

    // Storing coins needed
    int ctotal = 0;

    // 25 cents substraction
    if (owed >= c25)
    {
        do
        {
            owed = owed - c25;
            ctotal++;
        } while (owed >= c25);
    }

    // 10 cents substraction
    if (owed >= c10)
    {
        do
        {
            owed = owed - c10;
            ctotal++;
        } while (owed >= c10);
    }

    // 5 cents substraction
    if (owed >= c5)
    {
        do
        {
            owed = owed - c5;
            ctotal++;
        } while (owed >= c5);
    }

    // 5 cents substraction
    if (owed >= c1)
    {
        do
        {
            owed = owed - c1;
            ctotal++;
        } while (owed >= c1);
    }

    // Printing, finally...
    printf("%i\n", ctotal);
}