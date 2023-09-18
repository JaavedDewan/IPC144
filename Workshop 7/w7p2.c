/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : Jaaved Dewan
Student ID#: 126045178
Email      : jdewan@myseneca.ca
Section    : NLL
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_LENGTH 70
#define MIN_LENGTH 10
#define MAX_LIVES 10
#define MIN_LIVES 1

struct PlayerConfig
{
    char symbol;
    int lives;
    int treasure;
    int positionHistory[MAX_LENGTH];
};
struct GameConfig
{
    int moveLimits;
    int pathLength;
    int bombsArray[MAX_LENGTH];
    int treasureArray[MAX_LENGTH];
};

struct GameInfo
{
    int moveLimits;
    int pathLength;
    int bombsArray[MAX_LENGTH];
    int treasuresArray[MAX_LENGTH];
};
struct Board
{
    char recentPosition[MAX_LENGTH + 1];
    char gamePath[MAX_LENGTH + 1];
    char majorRuler[MAX_LENGTH + 1];
    int minorRuler[MAX_LENGTH];
};

int main(void)
{
    struct PlayerConfig player = { 0, 0, 0, {0} };
    struct GameConfig game = { 0, 0, {0}, {0} };
    struct Board gameboard = { {0}, {0}, {0}, {0} };
    int enteredPosition = 0, rmenteredPosition = 0;
    int flag = 0;
    int i, k;
    printf("================================\n"
        "         Treasure Hunt!\n"
        "================================\n\n");


    printf("PLAYER Configuration\n"
        "--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);
    while (getchar() != '\n');
    while (!flag)
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives <= MAX_LIVES && player.lives >= MIN_LIVES)
        {
            flag = 1;
            printf("Player configuration set-up is complete\n\n");
        }
        else
        {
            printf("     Must be between 1 and 10!\n");
        }
        while (getchar() != '\n');
    }


    printf("GAME Configuration\n"
        "------------------\n");
    flag = 0;
    while (!flag)
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
        if (game.pathLength <= MAX_LENGTH && game.pathLength >= MIN_LENGTH && game.pathLength % 5 == 0)
        {
            flag = 1;
        }
        else
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
        while (getchar() != '\n');
    }

    flag = 0;
    while (!flag)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moveLimits);
        if (game.moveLimits <= (int)(game.pathLength * 0.75) && game.moveLimits
            >= player.lives)
        {
            flag = 1;
        }
        else
        {
            printf("    Value must be between %d and %d\n", player.lives,
                (int)(game.pathLength * 0.75));
        }
        while (getchar() != '\n');
    }


    printf("\n");
    printf("BOMB Placement\n"
        "--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n"
        "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength / 5; i++)
    {
        printf("   Positions [%2d-%2d]: ", 5 * i + 1, 5 * (i + 1));
        scanf("%d %d %d %d %d", &game.bombsArray[5 * i], &game.bombsArray[5 * i +
            1], &game.bombsArray[5 * i + 2], &game.bombsArray[5 * i + 3], &game.bombsArray[5 * i +
            4]);
        while (getchar() != '\n');
    }
    printf("BOMB placement set\n\n");


    printf("TREASURE Placement\n"
        "------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n"
        "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength / 5; i++)
    {
        printf("   Positions [%2d-%2d]: ", 5 * i + 1, 5 * (i + 1));
        scanf("%d %d %d %d %d", &game.treasureArray[5 * i], &game.treasureArray[5
            * i + 1], &game.treasureArray[5 * i + 2], &game.treasureArray[5 * i + 3],
            &game.treasureArray[5 * i + 4]);
        while (getchar() != '\n');
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");


    printf("------------------------------------\n"
        "TREASURE HUNT Configuration Settings\n"
        "------------------------------------\n");
    printf("Player:\n"
        "   Symbol     : %c\n"
        "   Lives      : %d\n"
        "   Treasure   : [ready for gameplay]\n"
        "   History    : [ready for gameplay]\n\n", player.symbol, player.lives);
    printf("Game:\n"
        "   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombsArray[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasureArray[i]);
    }
    printf("\n\n");
    printf("====================================\n"
        "~ Get ready to play TREASURE HUNT! ~\n"
        "====================================\n\n");
    
    
    for (i = 0; i < game.pathLength; i++)
    {
        gameboard.recentPosition[i] = ' ';
        gameboard.gamePath[i] = '-';
        gameboard.majorRuler[i] = '|';
        gameboard.minorRuler[i] = (i + 1) % 10;
        if (gameboard.minorRuler[i] == 0)
        {
            gameboard.majorRuler[i] = (i + 1) / 10 + 48;
        }
    }



    printf("  ");
    for (k = 0; k < game.pathLength; k++)
    {
        printf("%c", gameboard.gamePath[k]);
    }
    printf("\n  ");
    for (k = 0; k < game.pathLength; k++)
    {
        printf("%c", gameboard.majorRuler[k]);
    }
    printf("\n  ");
    for (k = 0; k < game.pathLength; k++)
    {
        printf("%d", gameboard.minorRuler[k]);
    }
    printf("\n");



    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
        player.lives, player.treasure, game.moveLimits);
    printf("+---------------------------------------------------+\n");



    for (i = game.moveLimits; i > 0 && player.lives > 0; i--)
    {
        gameboard.recentPosition[enteredPosition] = ' ';



        flag = 0;
        while (!flag)
        {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &enteredPosition);

            rmenteredPosition = enteredPosition;

            if (enteredPosition >= 1 && enteredPosition <= game.pathLength)
            {
                enteredPosition -= 1;
                flag = 1;
            }
            else
            {
                printf("  Out of Range!!!\n");
            }
            while (getchar() != '\n');
        }
        printf("\n");



        if (player.positionHistory[enteredPosition] == 1)
        {
            gameboard.recentPosition[enteredPosition] = player.symbol;
            printf("===============> Dope! You've been here before!\n\n");
            i++;
        }
        else
        {
            player.positionHistory[enteredPosition] = 1;
            gameboard.recentPosition[enteredPosition] = player.symbol;
            if (game.bombsArray[enteredPosition] == 1 &&
                game.treasureArray[enteredPosition] == 0)
            {
                gameboard.gamePath[enteredPosition] = '!';
                player.lives -= 1;
                printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            }
            else if (game.bombsArray[enteredPosition] == 0 &&
                game.treasureArray[enteredPosition] == 1)
            {
                gameboard.gamePath[enteredPosition] = '$';
                player.treasure += 1;
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            }
            else if (game.bombsArray[enteredPosition] == 1 &&
                game.treasureArray[enteredPosition] == 1)
            {
                gameboard.gamePath[enteredPosition] = '&';
                player.lives -= 1;
                player.treasure += 1;
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            }
            else if (game.bombsArray[enteredPosition] == 0 &&
                game.treasureArray[enteredPosition] == 0)
            {
                gameboard.gamePath[enteredPosition] = '.';
                printf("===============> [.] ...Nothing found here... [.]\n\n");
            }
        }


        if (player.lives == 0)
        {
            printf("No more LIVES remaining!\n\n");
        }
  

        printf("  ");
        
        for (k = 0; k < rmenteredPosition; k++)
        {
            printf("%c", gameboard.recentPosition[k]);
        }
        printf("\n  ");
        for (k = 0; k < game.pathLength; k++)
        {
            printf("%c", gameboard.gamePath[k]);
        }
        printf("\n  ");
        for (k = 0; k < game.pathLength; k++)
        {
            printf("%c", gameboard.majorRuler[k]);
        }
        printf("\n  ");
        for (k = 0; k < game.pathLength; k++)
        {
            printf("%d", gameboard.minorRuler[k]);
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
            player.lives, player.treasure, i - 1);
        printf("+---------------------------------------------------+\n");
    }
    printf("\n");
    printf("##################\n"
        "#   Game over!   #\n"
        "##################\n\n");
    printf("You should play again and try to beat your score!\n");
    return 0;
}