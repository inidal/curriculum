#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Get pseudo-random number
    time_t t;
    srand((unsigned) time(&t));
    int randomNumber = rand() % 21;

    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20 which you must guess.\n\n");

    int count = 5;

    while (count != 0)
    {
        int guess;
        printf("You have %i tries left.\n", count);
        printf("Enter a guess: ");
        scanf("%i", &guess);

        if (guess == randomNumber)
        {
            printf("\nCongratulations, You guessed it!\n");
            break;
        }
        else
        {
            if (guess > randomNumber)
            {
                printf("Sorry, %i is wrong. My number is less than that.\n\n", guess);
            }
            else
            {
                printf("Sorry, %i is wrong. My number is more than that.\n\n", guess);
            }
        }
        --count;
    }

    if (count == 0)
    {
        printf("\n==========\n");
        printf("Game over!");
        printf("\n==========\n");
    }


    return 0;
}
