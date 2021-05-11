#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Assign needed variables
    long ask = get_long("Number: ");
    long input = ask;
    long input2 = input;
    long rinput = 0;
    int length = 0;
    int checksum = 0;
    int luhn_logic = 1;
    int checksum_valid = 0;
    int mmntry_calc;

    // Loop the following until 0 reached (counting purpose)
    do
    {
        // Grab first digit
        int frst_dgt = input % 10;

        // Remove first digit and 0 from input
        input = (input - frst_dgt) / 10;

        // Transfer first digits to rinput
        rinput = (rinput * 10) + frst_dgt;
        length++; // Count length of the input
    } while (input != 0);

    // Luhn's algorithm
    do
    {
        // Grab first digit
        int frst_dgt = input2 % 10;

        // Luhn's logic
        if (luhn_logic == 2)
        {

            if (frst_dgt >= 5 && frst_dgt <= 9)
            {
                mmntry_calc = frst_dgt * 2;
                checksum = checksum + ((int)((mmntry_calc % 10) + (mmntry_calc / 10)));
                mmntry_calc = 0;
            }
            else
            {
                checksum = checksum + (frst_dgt * 2);
            }

            luhn_logic = luhn_logic - 1;
        }
        else
        {
            checksum = checksum + frst_dgt;
            luhn_logic = luhn_logic + 1;
        }

        // Remove first digit and 0 from input
        input2 = (input2 - frst_dgt) / 10;
    } while (input2 != 0);

    if (checksum % 10 == 0)
    {
        checksum_valid++;
    }

    // Get MII (2-digits)
    int mii = ask / (pow(10, (length - 2)));

    if (checksum_valid == 1)
    {
        // Check card type if valid (AMEX, VISA, MASTERCARD supported)
        if ((mii >= 40 && mii <= 49) && (length >= 13 && length <= 16)) // VISA check
        {
            printf("VISA\n");
        }

        else if ((mii == 34 || mii == 37) && length == 15) // AMEX check
        {
            printf("AMEX\n");
        }

        else if ((mii >= 51 && mii <= 55) && length == 16) // MASTERCARD check
        {
            printf("MASTERCARD\n");
        }

        else // Return "INVALID" if all are incorrect
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}