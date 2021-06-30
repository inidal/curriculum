#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Prototyping needed functions
int markBoard();
int drawBoard();
int checkForWin();

// Board numbers/score
char board[10] =
{
    '0',
    '1', '2', '3',
    '4', '5', '6',
    '7', '8', '9'
};

// Variables needed
bool game_on = true;

// Track for draw
int players_moves = 0;

int main()
{



    // ================ Live playing ================
    while (game_on == true)
    {
        markBoard();
    }


    return 0;
}

// Function 1: markboard()
int markBoard()
{
    // Player turn
    int player = 1; // (default player 1 to start)
    char players_marks[3] = {'?', 'X', 'O'};
    int error_flag = 0;

    while (true)
    {
        int input_p1;
        drawBoard();

        // Break the game if a player wins
        if (checkForWin() == true)
        {
            game_on = false;
            break;
        }

        // In case of input out of range
        if (error_flag == 1)
        {
            printf("\nERROR: Only digits between 1 and 9 are authorized. Try again.");
            printf("\nPlayer %d (%c) enter a number: ", player, players_marks[player]);
        }
        else
        {
            printf("\nPlayer %d (%c) enter a number: ", player, players_marks[player]);
        }

        error_flag = 0;

        // Get input from user
        scanf("%d", &input_p1);

        // Accepts only digits from 1 to 9
        if (input_p1 >= 1 && input_p1 <= 9)
        {
            // Fill if not already played
            if (board[input_p1] != 'X' && board[input_p1] != 'O')
            {
                // Fill with current mark player
                board[input_p1] = players_marks[player];

                // Prepare if draw
                ++players_moves;

                // Clear screen and pre-increment player variable
                system("clear");

                // Switching players turn
                player == 1 ? ++player : --player;
            }
            else
            {
                system("clear");
            }

        }
        else
        {
            system("clear");
            ++error_flag;
        }
    }
    return 0;
}

// Function 2: Draw board and check with markboard()
int drawBoard()
{
    // Printing the board
    printf("\n\n====== [Tic Tac Toe] ======\n");

    printf("Player 1 (X) - Player 2 (O)\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
    printf("     |     |     \n");

    return 0;
}


// Function 3: If player win break
int checkForWin()
{
    int winner_pattern[8][3] =
    {
        // Horizontal
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},

        // Vectical
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},

        // Diagonal
        {1, 5, 9},
        {3, 5, 7}
    };

    //int winner_count;

    // Score of each player
    int p1_score;
    int p2_score;

    // Rows
    for (int i = 0; i < 8; ++i)
    {
        //winner_count = 0;

        p1_score = 0;
        p2_score = 0;

        // Columns
        for (int j = 0; j < 3; ++j)
        {
            if (board[winner_pattern[i][j]] == 'X')
            {
                //++winner_count;
                ++p1_score;
            }

            else if (board[winner_pattern[i][j]] == 'O')
            {
                //++winner_count;
                ++p2_score;
            }
        }

        // If count of 3, then winner
        if (p1_score == 3)
        {
            printf("\nPlayer 1 has won! Congratulations.\n");
            return true;
        }
        else if (p2_score == 3)
        {
            printf("\nPlayer 2 has won! Congratulations.\n");
            return true;
        }

        // Draw
        else if (players_moves == 9)
        {
            printf("\nDraw, congratulations to both of you!\n");
            return true;
        }
    }

    return 0;
}