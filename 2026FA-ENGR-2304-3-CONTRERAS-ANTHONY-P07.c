// 2026FA-ENGR-2304-3-CONTRERAS-ANTHONY-P07

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeBoard(char board[]);
void displayBoard(char board[]);
int checkWinner(char board[], char mark);
int boardFull(char board[]);
int validMove(char board[], int move);
int findWinningMove(char board[], char mark);
int computerMove(char board[], char computerMark, char humanMark);
void delaySeconds(double seconds);

int main()
{
    char board[9];
    int mode;
    char player1Mark, player2Mark;
    int currentPlayer;
    int move;
    int playAgain = 1;

    srand((unsigned int)time(NULL));

    while (playAgain == 1)
    {
        initializeBoard(board);

        printf("\nTIC-TAC-TOE\n");
        printf("1. One Player vs Computer\n");
        printf("2. Two Player Mode\n");
        printf("Select mode: ");
        scanf("%d", &mode);

        while (mode != 1 && mode != 2)
        {
            printf("Invalid choice. Enter 1 or 2: ");
            scanf("%d", &mode);
        }

        printf("\nPlayer 1, choose X or O: ");
        scanf(" %c", &player1Mark);

        while (player1Mark != 'X' && player1Mark != 'x' &&
               player1Mark != 'O' && player1Mark != 'o')
        {
            printf("Invalid choice. Enter X or O: ");
            scanf(" %c", &player1Mark);
        }

        if (player1Mark == 'x')
            player1Mark = 'X';

        if (player1Mark == 'o')
            player1Mark = 'O';

        if (player1Mark == 'X')
            player2Mark = 'O';
        else
            player2Mark = 'X';

        /* Randomly select who goes first */
        currentPlayer = (rand() % 2) + 1;

        if (mode == 1)
        {
            if (currentPlayer == 1)
                printf("\nRandom selection: You go first.\n");
            else
                printf("\nRandom selection: Computer goes first.\n");
        }
        else
        {
            printf("\nRandom selection: Player %d goes first.\n",
                   currentPlayer);
        }

        displayBoard(board);

        while (1)
        {
            char currentMark;

            if (currentPlayer == 1)
                currentMark = player1Mark;
            else
                currentMark = player2Mark;

            /* Computer turn */
            if (mode == 1 && currentPlayer == 2)
            {
                printf("\nComputer is thinking...\n");
                delaySeconds(1.0);

                move = computerMove(board,
                                    player2Mark,
                                    player1Mark);

                board[move - 1] = player2Mark;

                printf("Computer selected position %d.\n",
                       move);
            }

            /* Human turn */
            else
            {
                if (mode == 1)
                {
                    printf("\nYour move (%c). "
                           "Choose position 1-9: ",
                           currentMark);
                }
                else
                {
                    printf("\nPlayer %d (%c), "
                           "choose position 1-9: ",
                           currentPlayer,
                           currentMark);
                }

                scanf("%d", &move);

                while (!validMove(board, move))
                {
                    printf("Invalid move. "
                           "Choose an empty position 1-9: ");
                    scanf("%d", &move);
                }

                board[move - 1] = currentMark;
            }

            displayBoard(board);

            /* Check for winner */
            if (checkWinner(board, currentMark))
            {
                if (mode == 1)
                {
                    if (currentPlayer == 1)
                        printf("\nYou win!\n");
                    else
                        printf("\nComputer wins!\n");
                }
                else
                {
                    printf("\nPlayer %d wins!\n",
                           currentPlayer);
                }

                break;
            }

            /* Check for tie */
            if (boardFull(board))
            {
                printf("\nThe game is a tie.\n");
                break;
            }

            /* Switch players */
            if (currentPlayer == 1)
                currentPlayer = 2;
            else
                currentPlayer = 1;
        }

        printf("\nPlay again? (1 = Yes, 0 = No): ");
        scanf("%d", &playAgain);

        while (playAgain != 0 && playAgain != 1)
        {
            printf("Enter 1 to play again or 0 to exit: ");
            scanf("%d", &playAgain);
        }
    }

    printf("\nClosing Tic-Tac-Toe...\n");

    return 0;
}

void initializeBoard(char board[])
{
    int i;

    for (i = 0; i < 9; i++)
    {
        board[i] = ' ';
    }
}

void displayBoard(char board[])
{
    int i;
    char shown[9];

    for (i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
            shown[i] = '1' + i;
        else
            shown[i] = board[i];
    }

    printf("\n");

    printf(" %c | %c | %c \n",
           shown[0], shown[1], shown[2]);

    printf("---+---+---\n");

    printf(" %c | %c | %c \n",
           shown[3], shown[4], shown[5]);

    printf("---+---+---\n");

    printf(" %c | %c | %c \n",
           shown[6], shown[7], shown[8]);
}

int checkWinner(char board[], char mark)
{
    int wins[8][3] =
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    int i;

    for (i = 0; i < 8; i++)
    {
        if (board[wins[i][0]] == mark &&
            board[wins[i][1]] == mark &&
            board[wins[i][2]] == mark)
        {
            return 1;
        }
    }

    return 0;
}

int boardFull(char board[])
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
            return 0;
    }

    return 1;
}

int validMove(char board[], int move)
{
    if (move < 1 || move > 9)
        return 0;

    if (board[move - 1] != ' ')
        return 0;

    return 1;
}

int findWinningMove(char board[], char mark)
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = mark;

            if (checkWinner(board, mark))
            {
                board[i] = ' ';
                return i + 1;
            }

            board[i] = ' ';
        }
    }

    return 0;
}

int computerMove(char board[],
                 char computerMark,
                 char humanMark)
{
    int move;

    int corners[4] =
    {
        1, 3, 7, 9
    };

    int available[9];

    int count = 0;
    int i;

    /* First try to win */
    move = findWinningMove(board, computerMark);

    if (move != 0)
        return move;

    /* Then block the player */
    move = findWinningMove(board, humanMark);

    if (move != 0)
        return move;

    /* Take center */
    if (validMove(board, 5))
        return 5;

    /* Try an available corner */
    for (i = 0; i < 4; i++)
    {
        if (validMove(board, corners[i]))
        {
            available[count] = corners[i];
            count++;
        }
    }

    if (count > 0)
    {
        return available[rand() % count];
    }

    /* Otherwise choose any empty space */
    count = 0;

    for (i = 1; i <= 9; i++)
    {
        if (validMove(board, i))
        {
            available[count] = i;
            count++;
        }
    }

    return available[rand() % count];
}

void delaySeconds(double seconds)
{
    clock_t start = clock();

    while (((double)(clock() - start) /
            CLOCKS_PER_SEC) < seconds)
    {
    }
}