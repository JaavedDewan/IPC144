/*
*****************************************************************************
                          Workshop - #5 (P1)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int month, year, validMonth = 0, validYear = 0, i;
    float eveningRating = 0, morningRating = 0, rating;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%d", &year, &month);

        if (year >= MIN_YEAR && year <= MAX_YEAR)
        {
            validYear = 1;
        }
        else
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);

            validYear = 0;
        }
        if (month >= JAN && month <= DEC)

        {
            validMonth = 1;
        }
        else
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
            validMonth = 0;
        }

    } while (validMonth == 0 || validYear == 0);

    printf("\n*** Log date set! ***\n");

    for (i = 1; i <= LOG_DAYS; i++)
    {
        if (month == 1)
            printf("\n%d-JAN-%02d", year, i);
        else if (month == 2)
            printf("\n%d-FEB-%02d", year, i);
        else if (month == 3)
            printf("\n%d-MAR-%02d", year, i);
        else if (month == 4)
            printf("\n%d-APR-%02d", year, i);
        else if (month == 5)
            printf("\n%d-MAY-%02d", year, i);
        else if (month == 6)
            printf("\n%d-JUN-%02d", year, i);
        else if (month == 7)
            printf("\n%d-JUL-%02d", year, i);
        else if (month == 8)
            printf("\n%d-AUG-%02d", year, i);
        else if (month == 9)
            printf("\n%d-SEP-%02d", year, i);
        else if (month == 10)
            printf("\n%d-OCT-%02d", year, i);
        else if (month == 11)
            printf("\n%d-NOV-%02d", year, i);
        else if (month == 12)
            printf("\n%d-DEC-%02d", year, i);
        printf("\n");

        do

        {

            printf("   Morning rating (0.0-5.0): ");

            scanf("%f", &rating);

            if (rating < 0.0 || rating > 5.0)

                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");

        } while (rating < 0.0 || rating > 5.0);

        morningRating += rating;

        do

        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%f", &rating);
            if (rating < 0.0 || rating > 5.0)
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");

        } while (rating < 0.0 || rating > 5.0);

        eveningRating += rating;

    }
        printf("\n");
        printf("Summary\n");
        printf("=======\n");
        printf("Morning total rating: %6.3f\n", morningRating);
        printf("Evening total rating: %6.3f\n", eveningRating);
        printf("----------------------------\n");
        printf("Overall total rating: %6.3f\n", (eveningRating + morningRating));
        
        printf("\nAverage morning rating: %4.1f\n", (morningRating / LOG_DAYS));
        printf("Average evening rating: %4.1f\n", (eveningRating / LOG_DAYS));
        printf("----------------------------\n");
        printf("Average overall rating: %4.1f\n", ((eveningRating / LOG_DAYS) + (morningRating / LOG_DAYS)) / 2);
    
    return 0;
}