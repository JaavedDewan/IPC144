/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
#include <string.h>



// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//1. inputInt - Main Input Function
int inputInt()
{
    int input_Integer = -1; // input variable
    char newline_Character = '\0'; //placeholder for the next input variable
    int verify_Integer = 1; //variable for WHILE loop

    while (verify_Integer)
    {
        scanf("%d%c", &input_Integer, &newline_Character);
        if (newline_Character != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else
        {
            verify_Integer = 0; //Ends loop
        }
    }
    return input_Integer;
}

//2. InputIntPositive - Positive Test
int inputIntPositive()
{
    int positiveNum = -1; //input variable

    do
    {
        positiveNum = inputInt();
    } while (positiveNum < 0 && printf("ERROR! Value must be > 0: ")); //Loops so long as the value isn't positive.

    return positiveNum;
}

//3.InputIntRange - Range Test
int inputIntRange(int min, int max)
{
    int intRange = min - 1; //variable placeholder

    do
    {
        intRange = inputInt(); 
    } while ((intRange < min || intRange > max) && printf("ERROR! Value must be between %d and %d inclusive: ", min, max)); //loop when not in range

        return intRange;
}

//4.inputCharOption - Specific Character Test
char inputCharOption(const char *charOption)
{

    char charInput = '\0';
    char nextWord = '\0';
    int i = 0;
    int charLength = strlen(charOption);
    int nextMove = 1;
    do
    {
        scanf("%c%c", &charInput, &nextWord);
        if (nextWord == '\n')
        {
            for (i = 0; i < charLength && nextMove; i++)
                if (charOption[i] == charInput)
                    nextMove = 0; //loop ends
        }
    } while (nextMove && printf("ERROR: Character must be one of [%s]: ", charOption)); //loops until the input is 14.
    return charInput;
}

//5.inputCString - Input within String Test
void inputCString(char* cString, int min, int max)
{
    char maxCharacter[100] = { '\0' };
    int i = 0;
    int length = 0;

    while (!length)
    {
        scanf("%99[^\n]%*c", maxCharacter);
        for (i = 1; maxCharacter[i]; i++)
            ; // this will calculate the length of the string that is required
        if (min == max)
        {
            if (i == min)
            {
                strcpy(cString, maxCharacter);
                length = 1; //ends loop
            }
        }
        else
        {
            if (i >= min && i <= max)
            {
                strcpy(cString, maxCharacter);
                length = 1; //ends loop
            }
        }
        if (!length)
        {
            if (min == max)
            {
                printf("ERROR: String length must be exactly %d chars: ", min);
            }
            else if (min == 0 || i > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
        }
    }
}


//6.displayFormattedPhone - Input within character range Test
void displayFormattedPhone(const char* displayPhone)
{
    int validInt = 1;
    int i = 0;
    if (displayPhone != NULL)
    {
        for (i = 0; displayPhone[i] && validInt; i++)
        {
            if (displayPhone[i] < 48 || displayPhone[i] > 57)
            {
                validInt = 0;
            }
        }
    }
    if (validInt && i == 10)
    {
        printf("(");
        for (i = 0; i < 3; i++)
            printf("%c", displayPhone[i]);
        printf(")");
        for (i = 3; i < 6; i++)
            printf("%c", displayPhone[i]);
        printf("-");
        for (i = 6; i < 10; i++)
            printf("%c", displayPhone[i]);
    }
    else
    {
        printf("(___)___-____");
    }
}