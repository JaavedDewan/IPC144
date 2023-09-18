/*
*****************************************************************************
                          Workshop - #4 (P2)
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

int main(void)
{
    int apple, oranges, pears, tomatoes, cabbages;
    int pickApple, pickOrange, pickPear, pickTomatoes, pickCabbage;
    int choice;

    while (1)
    {


        printf("Grocery Shopping\n");
        printf("================\n");


        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apple);
            if (apple < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apple < 0);
        printf("\n");
        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (oranges < 0);
        printf("\n");
        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pears < 0);
        printf("\n");
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatoes < 0);
        printf("\n");
        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbages < 0);
        

        printf("\n");
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");
        
        
        if (apple > 0) {
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickApple);
                if (pickApple > apple)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apple);
                }
                else if (pickApple < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickApple < apple)
                {
                    printf("Looks like we still need some APPLES...\n");
                    apple -= pickApple;
                }
                else
                {
                    printf("Great, that's the apples done!\n");
                    printf("\n");
                    apple -= pickApple;
                }

            } while (apple > 0);
        }

        if (oranges > 0) {
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickOrange);
                if (pickOrange > oranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
                }
                else if (pickOrange < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickOrange < oranges)
                {
                    printf("Looks like we still need some ORANGES...\n");
                    oranges -= pickOrange;
                }
                else
                {
                    printf("Great, that's the oranges done!\n");
                    printf("\n");
                    oranges -= pickOrange;
                }
            } while (oranges > 0);
        }

        if (pears > 0) {
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickPear);
                if (pickPear > pears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                }
                else if (pickPear < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickPear < pears)
                {
                    printf("Looks like we still need some PEARS...\n");
                    pears -= pickPear;
                }
                else
                {
                    printf("Great, that's the pears done!\n");
                    printf("\n");
                    pears -= pickPear;
                }
            } while (pears > 0);
        }

        if (tomatoes > 0) {
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickTomatoes);
                if (pickTomatoes > tomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                }
                else if (pickTomatoes < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickTomatoes < tomatoes)
                {
                    printf("Looks like we still need some TOMATOES...\n");
                    tomatoes -= pickTomatoes;
                }
                else
                {
                    printf("Great, that's the tomatoes done!\n");
                    printf("\n");
                    tomatoes -= pickTomatoes;
                }
            } while (tomatoes > 0);
        }

        if (cabbages > 0) {
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickCabbage);
                if (pickCabbage > cabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                }
                else if (pickCabbage < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickCabbage < cabbages)
                {
                    printf("Looks like we still need some CABBAGES...\n");
                    cabbages -= pickCabbage;
                }
                else
                {
                    printf("Great, that's the cabbages done!\n");
                    printf("\n");
                    cabbages -= pickCabbage;
                }
            } while (cabbages > 0);
        }

        printf("All the items are picked!\n");
        printf("\nDo another shopping? (0=NO): ");
        scanf("%d", &choice);
        printf("\n");
        
        if (choice == 0)
        {
            printf("Your tasks are done for today - enjoy your free time!\n");
            break;
        }
    }
    return 0;
}