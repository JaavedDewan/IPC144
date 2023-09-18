/*
*****************************************************************************
                          Workshop - #8 (Part - 1)
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
// System Libraries
#include <stdio.h>
// User Libraries
#include "test.h"
// 1. Get user input of int type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number)
{
    int value;
    do
    {
        scanf("%d", &value);
        if (value <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);
    if (number != NULL)
    {
        *number = value;
    }
    return value;
}
// 2. Get user input of double type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number)
{
    double value;
    do
    {
        scanf("%lf", &value);
        if (value <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);
    if (number != NULL)
    {
        *number = value;
    }
    return value;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product)
{
    //printf("\n===========================\n");
    //printf("Starting Main Program Logic\n");
    //printf("===========================\n\n");
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
    printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS);
}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_number)
{
    struct CatFoodInfo food = { 0 };
    printf("\nCat Food Product #%d\n", sequence_number);
    printf("--------------------\n");
    printf("SKU : ");
    getIntPositive(&food.sku);
    printf("PRICE : $");
    getDoublePositive(&food.price);
    printf("WEIGHT (LBS) : ");
    getDoublePositive(&food.weight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&food.calories);
    return food;
}
// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU $Price Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}
// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories,
    const double* weight)
{
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}
// 7. Logic entry point
void start()
{
    struct CatFoodInfo cats[MAX_PRODUCT] = { {0} };
    int i = 0;
    openingMessage(MAX_PRODUCT);
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        cats[i] = getCatFoodInfo(i + 1);
    }
    printf("\n");
    displayCatFoodHeader();
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        displayCatFoodData(cats[i].sku, &cats[i].price, cats[i].calories,
            &cats[i].weight);
    }
}