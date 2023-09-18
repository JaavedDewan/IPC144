/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  :
Student ID#:
Email      :
Section    :
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_ITEMS 10
int main(void)
{
    const double minIncome = 500, maxIncome = 400000;
    int priority[10], key, flag = 0, itemList = 0;
    double cost[10], income = 0, sum = 0;
    char financeOption[10];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    while (flag == 0)
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);

        if (income < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        if (income > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
        if ((income >= minIncome) && (income <= maxIncome))
        {
            flag = 1;
        }
    }

    flag = 0;
    while (flag == 0)
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &itemList);

        if ((itemList < 1) || (itemList > MAX_ITEMS))
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else
        {
            flag = 1;
        }
    }

    for (key = 0; key < itemList; key++)
    {
        printf("\nItem-%d Details:\n", (key + 1));
        flag = 0;
        while (flag == 0)
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[key]);
            if (cost[key] < 100)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            else
            {
                sum = sum + cost[key];
                flag = 1;
            }
        }

        flag = 0;
        while (flag == 0)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[key]);
            if (priority[key] < 1 || priority[key] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else
            {
                flag = 1;
            }
        }

        flag = 0;
        while (flag == 0)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%s", &financeOption[key]);
            if (financeOption[key] != 'y' && financeOption[key] != 'n')
            {
                printf("      ERROR: Must be a lowercase \'y\' or \'n\'\n");
            }
            else
            {
                flag = 1;
            }
        }
    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (key = 0; key < itemList; key++)
    {
        printf("%3d %6d %8c %14.2lf\n", (key + 1), priority[key], financeOption[key], cost[key]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sum);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
