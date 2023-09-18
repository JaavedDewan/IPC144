/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//1.inputInt - Main Input Function

int inputInt();

//2 inputIntPositive - Positive Test

int inputIntPositive(void);

//3 inputIntRange - Range Test

int inputIntRange(int min, int max);

//4 inputCharOption - Specific Character Test

char inputCharOption(const char charOption[]);

//5 inputCString - Input within String Test

char inputCString(char* cString, int min, int max);

//6 displayFormattedPhone - Input within character range Test

void displayFormattedPhone(const char* displayPhone);

