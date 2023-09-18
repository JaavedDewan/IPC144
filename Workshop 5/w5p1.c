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

int main(void)
{
    const int JAN = 1, DEC = 12;
    int month, year, validMonth = 0, validYear = 0;

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

    printf("\n*** Log date set! ***\n\n");

    if (month == 1)
        printf("Log starting date: %d-JAN-01\n", year);
    else if (month == 2)
        printf("Log starting date: %d-FEB-01\n", year);
    else if (month == 3)
        printf("Log starting date: %d-MAR-01\n", year);
    else if (month == 4)
        printf("Log starting date: %d-APR-01\n", year);
    else if (month == 5)
        printf("Log starting date: %d-MAY-01\n", year);
    else if (month == 6)
        printf("Log starting date: %d-JUN-01\n", year);
    else if (month == 7)
        printf("Log starting date: %d-JUL-01\n", year);
    else if (month == 8)
        printf("Log starting date: %d-AUG-01\n", year);
    else if (month == 9)
        printf("Log starting date: %d-SEP-01\n", year);
    else if (month == 10)
        printf("Log starting date: %d-OCT-01\n", year);
    else if (month == 11)
        printf("Log starting date: %d-NOV-01\n", year);
    else if (month == 12)
        printf("Log starting date: %d-DEC-01\n", year);

    return 0;
}