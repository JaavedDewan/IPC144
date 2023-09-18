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
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intNumber) {
	int num = 0;
	while (num < 1) {
		scanf("%d", &num);
		if (num < 1)
			printf("ERROR: Enter a positive value: ");
	}
	if (intNumber != NULL)
		*intNumber = num;
	return num;
}
// 2. Get user input of double type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doubleNumber) {
	double num = 0;
	while (num < 1) {
		scanf("%lf", &num);
		if (num < 1)
			printf("ERROR: Enter a positive value: ");
	}
	if (doubleNumber != 0)
		*doubleNumber = num;
	return num;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int openMessage)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n", MAX_GRAMS);
}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber)
{
	struct CatFoodInfo product;
	int flag;
	printf("\nCat Food Product #%d\n", sequenceNumber);
	printf("--------------------\n");
	flag = 1;
	printf("SKU           : ");
	do
	{
		scanf("%d", &product.sku);
		if (product.sku <= 0)
			printf("ERROR: Enter a positive value: ");
		else
			flag = 0;
	} while (flag);
	flag = 1;
	printf("PRICE         : $");
	do
	{
		scanf("%lf", &product.price);
		if (product.price <= 0)
			printf("ERROR: Enter a positive value: ");
		else
			flag = 0;
	} while (flag);
	flag = 1;
	printf("WEIGHT (LBS)  : ");
	do
	{
		scanf("%lf", &product.weight);
		if (product.weight <= 0)
			printf("ERROR: Enter a positive value: ");
		else
			flag = 0;
	} while (flag);
	flag = 1;
	printf("CALORIES/SERV.: ");
	do
	{
		scanf("%d", &product.calories);
		if (product.calories <= 0)
			printf("ERROR: Enter a positive value: ");
		else
			flag = 0;
	} while (flag);
	return product;
};

// 5. Display the formatted table header
void displayCatFoodHeader()
{
	printf("\n");
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}
// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, double* weight, int calorie_per_serving)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calorie_per_serving);
}
// 7. Logic entry point
void start()
{
	int i;
	struct CatFoodInfo product[MAX_PRODUCTS] = { {0} };
	openingMessage(MAX_PRODUCTS);
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		product[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(product[i].sku, &product[i].price, &product[i].weight, product[i].calories);
	}
}