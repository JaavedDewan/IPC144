/*
*****************************************************************************
                          Workshop - #4 (P1)
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

    int iterateNum, j;
    char loopLetter;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    printf("\n");
    while (1) 
    {

        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopLetter, &iterateNum);
        if (loopLetter == 'D') {
            if (iterateNum >= 3 && iterateNum <= 20) {
                printf("DO-WHILE: ");
                for (j = 0; j < iterateNum; j++) {
                    printf("%c", loopLetter);
                }
                printf("\n");
                printf("\n");

            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                printf("\n");
            }

        }
        else if (loopLetter == 'W') {
            if (iterateNum >= 3 && iterateNum <= 20) {
                printf("WHILE   : ");
                for (j = 0; j < iterateNum; j++) {
                    printf("%c", loopLetter);
                }
                printf("\n");
                printf("\n");

            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                printf("\n");
            }

        }
        else if (loopLetter == 'F') {
            if (iterateNum >= 3 && iterateNum <= 20) {
                printf("FOR     : ");
                for (j = 0; j < iterateNum; j++) {
                    printf("%c", loopLetter);
                }
                printf("\n");
                printf("\n");
            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                printf("\n");
            }
        }
        else if (loopLetter == 'Q') {
            if (iterateNum == 0) {
                printf("\n");
                printf("+--------------------+\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n");
                break;
            }
            else {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
                printf("\n");
            }
        }
        else {
            printf("ERROR: Invalid entered value(s)!\n");
            printf("\n");
        }


    }
    return 0;
}