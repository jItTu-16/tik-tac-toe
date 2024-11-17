#include<stdio.h>
char game[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

void print_grid();
int check_winner();
void player_input(int player);

int main()
{

    int player = 1, choice, winner = 0;
    puts("-------------Tic Tac Toe-------------");

    // print_grid();

    while (winner == 0)
    {
        print_grid();
        player_input(player);
        winner = check_winner();

        if (winner == 1)
        {
            print_grid();
            printf("Player 1 (X) wins!");
            break;
        }

        else if (winner == 2)
        {
            print_grid();
            printf("Player 2 (O) wins!");
            break;
        }

// check draw condition

        int draw = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (game[i][j] != 'X' && game[i][j] != 'O')
                {
                    draw = 0;
                    break;
                }
            }
            if (!draw)break;
        }

        if (draw) {
            printf("It's a draw!\n");
            break;
        }

// change player

        player = (player == 1) ? 2 : 1;
    }

    return 0;
}

void print_grid()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", game[i][j]);
            if (j < 2)
            {
                printf("%c", 179);
            }
        }
        if (i < 2)
        {
            printf("\n");
            for (int k = 1; k <= 11; k++)
            {
                printf("%c", (k % 4 == 0) ? 197 : 196);
            }
        }
        printf("\n");
    }
}

int check_winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (game[i][0] == game[i][1] && game[i][1] == game[i][2])
        {
            return (game[i][0] == 'X') ? 1 : (game[i][0] == 'O') ? 2
                                                                 : 0;
        }
        if (game[0][i] == game[1][i] && game[1][i] == game[2][i])
        {
            return (game[0][i] == 'X') ? 1 : (game[0][i] == 'O') ? 2
                                                                 : 0;
        }
    }

    if (game[0][0] == game[1][1] && game[1][1] == game[2][2])
    {
        return (game[0][0] == 'X') ? 1 : (game[0][0] == 'O') ? 2
                                                             : 0;
    }
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0])
    {
        return (game[0][2] == 'X') ? 1 : (game[0][2] == 'O') ? 2
                                                             : 0;
    }
    return 0;
}

void player_input(int player)
{
    int pos;
    char symb = (player == 1) ? 'X' : 'O';

    while (1)
    {
        printf("\nPlayer %d (%c), Enter the place number:- ", player, symb);
        scanf("%d", &pos);

        if (pos < 1 || pos > 9)
        {
            printf("Invalid input, choose number between 1-9:- \n");
        }
        else
        {
            if (game[(pos - 1) / 3][(pos - 1) % 3] != 'X' && game[(pos - 1) / 3][(pos - 1) % 3] != 'O')
            {
                game[(pos - 1) / 3][(pos - 1) % 3] = symb;
                break;
            }
            else
            {
                printf("This spot is already taken. Try again.\n");
            }
        }
    }
}