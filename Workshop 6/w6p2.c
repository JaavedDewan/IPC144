/*
*****************************************************************************
                          Workshop - #6 (P2)
Full Name  : Jaaved Dewan
Student ID#: 126045178
Email      : jdewan@myseneca.ca or jilred15@gmail.com
Section    : NLL
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MIN_ITEMS 1
#define MAX_ITEMS 10
int main()
{
    const double MIN_INCOME = 500;
    const double MAX_INCOME = 400000;
    const double MIN_COST = 100.0;
    const int MIN_PRIORITY = 1;
    const int MAX_PRIORITY = 3;
    const int MIN_SELECTION = 0;
    const int MAX_SELECTION = 2;

    int numItems, selection, i = 0, filterPriority;
    double netIncome, sum = 0, forecastTime = 0, forecastYears = 0, forecastMonths = 0, filterAmount, filterTime = 0, filterYear = 0, filterMonth;
    
    double cost[MAX_ITEMS];
    int priority[MAX_ITEMS];
    char finance[MAX_ITEMS];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");


    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &netIncome);
        if (netIncome < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (netIncome > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
    } while (netIncome < MIN_INCOME || netIncome > MAX_INCOME);
    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &numItems);
        if (numItems < MIN_ITEMS || numItems > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    }
    while (numItems < MIN_ITEMS || numItems > MAX_ITEMS);


    for (i = 0; i < numItems; i++)
    {
        printf("\nItem-%d Details:\n", i + 1);
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < MIN_COST)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (cost[i] < MIN_COST);
        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
                scanf("%d", &priority[i]);
            if (priority[i] < MIN_PRIORITY || priority[i] > MAX_PRIORITY)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < MIN_PRIORITY || priority[i] > MAX_PRIORITY);
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%*c%c", &finance[i]);
            if (!(finance[i] == 'y' || finance[i] == 'n'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (finance[i] != 'y' && finance[i] != 'n');
        sum += cost[i];
    }


    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");


    for (i = 0; i < numItems; i++)
    {
        printf("%3d%7d%9c%15.2lf\n", i + 1, priority[i], finance[i], cost[i]);
    }


    printf("---- -------- -------- -----------\n");
    printf("%23c%11.2lf\n", '$', sum);
    forecastTime = (sum / netIncome);


    do
    {
        i = 0;
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);


        if (selection > MAX_SELECTION || selection < MIN_SELECTION)
        {
            printf("\nERROR: Invalid menu selection.\n");
        }


        if (selection == 1)
        {
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", sum);
            forecastYears = forecastTime / 12;
            forecastMonths = (int)(forecastTime + 1) % 12;
            printf("Forecast: %d years, %d months\n", (int)forecastYears,
                (int)forecastMonths);


            for (i = 0; i < numItems; i++)
            {
                if (finance[i] == 'y')
                {
                    printf("NOTE: Financing options are available on some items.\n");
                        printf("      You can likely reduce the estimated months.\n");
                            break;
                }
            }
            printf("====================================================\n");
        }

        if (selection == 2)
        {
            do
            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                    scanf("%d", &filterPriority);
                if (filterPriority > MAX_PRIORITY || filterPriority <
                    MIN_PRIORITY)
                {
                    printf("\nERROR: Value must be between 1 and 3\n");
                }
            } while (filterPriority > MAX_PRIORITY || filterPriority < MIN_PRIORITY);


            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", filterPriority);


            filterAmount = 0;


            for (i = 0; i < numItems; i++)
            {
                if (priority[i] == filterPriority)
                {
                    filterAmount = filterAmount + cost[i];
                }
            }
            printf("Amount:   $%1.2lf\n", filterAmount);
            filterTime = (filterAmount / netIncome);
            filterYear = filterTime / 12;
            filterMonth = (int)(filterTime + 1) % 12;
            printf("Forecast: %d years, %d months\n", (int)filterYear,
                (int)filterMonth);


            for (i = 0; i < numItems; i++)
            {
                if (priority[i] == filterPriority)
                {
                    if (finance[i] == 'y')
                    {
                        printf("NOTE: Financing options are available on some items.\n");
                            printf("      You can likely reduce the estimated months.\n");
                                break;
                    }
                }
            }
            printf("====================================================\n");
        }
    } while (selection > MAX_SELECTION || selection < MIN_SELECTION || selection !=0);


    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}