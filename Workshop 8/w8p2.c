/*
*****************************************************************************
						  Workshop - #8 (Part - 2)
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
#include "w8p2.h"

// 1. Get user input of int type and validate for a positive number
int getIntPositive(int* i_num)
{
	int integer_num = 0;
	do
	{
		scanf("%d", &integer_num);
		if (integer_num < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (integer_num < 1);
	if (i_num != NULL)
	{
		*i_num = integer_num;
	}
	return(integer_num);
}

// 2. Get user input of double type and validate for a positive number
double getDoublePositive(double* d_num)
{
	double double_num = 0.0;
	while (double_num < 1.0)
	{
		scanf("%lf", &double_num);
		if (double_num < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
	}
	if (d_num != NULL)
	{
		*d_num = double_num;
	}
	return(double_num);
}

// 3. Opening Message
void openingMessage(const int msg)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCT);
	printf("NOTE: A 'serving' is %dg\n\n", MAX_GRAMS);
}

// 4. Get user input for cat food product
struct CatFoodInfo getCatFoodInfo(const int i)
{
	struct CatFoodInfo product = { 0 };
	double Rate, Weight;
	int Sku, Calories;
	printf("Cat Food Product #%d\n", i + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	product.sku = getIntPositive(&Sku);
	printf("PRICE         : $");
	product.price = getDoublePositive(&Rate);
	printf("WEIGHT (LBS)  : ");
	product.weight = getDoublePositive(&Weight);
	printf("CALORIES/SERV.: ");
	product.calories = getIntPositive(&Calories);
	printf("\n");
	return(product);
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double price, const int calories, const double weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, price, weight, calories);
}

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catFoodDetail[MAX_PRODUCT];
	int i = 0, cheapproduct = 0;
	openingMessage(MAX_PRODUCT);
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		catFoodDetail[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		displayCatFoodData(catFoodDetail[i].sku, catFoodDetail[i].price, catFoodDetail[i].calories, catFoodDetail[i].weight);
	}
	struct ReportData reportArray[MAX_PRODUCT];
	displayReportHeader();
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		reportArray[i] = calculateReportData(catFoodDetail[i]);
		if (reportArray[i].perServe < reportArray[i - 1].perServe)
		{
			cheapproduct = i;
		}
	}
	int j;
	for (j = 0; j < MAX_PRODUCT; j++)
	{
		struct ReportData x = { 0 };
		x = reportArray[j];
		displayReportData(x, cheapproduct);
		if (cheapproduct == j)
		{
			printf(" ***");
		}
		printf("\n");
	}
	displayFinalAnalysis(catFoodDetail[cheapproduct]);
}

// 8. convert lbs to kg
double convertLbsKg(const double* lbs, double* kg)
{
	double i;
	i = *lbs / LBS_KG;
	if (kg != NULL)
	{
		*kg = i;
	}
	return(i);
}

// 9. convert lbs to g
int convertLbsG(const double* lbs, int* g)
{
	int j;
	j = convertLbsKg(lbs, 0) * 1000;
	if (g != NULL)
	{
		*g = j;
	}
	return(j);
}

// 10. convert lbs to kg / g
void convertLbs(const double* lbs_convert, double* kg, int* g)
{
	convertLbsKg(lbs_convert, kg);
	convertLbsG(lbs_convert, g);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingGrams, const int sumGrams, double* resultGrams)
{
	double i;
	i = (double)sumGrams / (double)servingGrams;
	if (resultGrams != NULL)
	{
		*resultGrams = i;
	}
	return(i);
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* rate, const double* result, double*
	resultCost)
{
	double cost = 0;
	cost = *rate / *result;
	if (resultCost != NULL)
	{
		*resultCost = cost;
	}
	return(cost);
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double*
	CostCalories)
{
	double cost = 0;
	cost = *price / *calories;
	if (CostCalories != NULL)
	{
		*CostCalories = cost;
	}
	return(cost);
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo getDetailCatFood)
{
	struct ReportData report;
	double calo;
	
	// For SKU, RATE, Weight and Calories
	report.sku = getDetailCatFood.sku;

	report.rate = getDetailCatFood.price;

	report.weightLbs = getDetailCatFood.weight;

	report.calories = getDetailCatFood.calories;

	
	// For kg and g
	report.kg = convertLbsKg(&getDetailCatFood.weight, &report.kg);

	report.g = convertLbsG(&getDetailCatFood.weight, &report.g);

	report.sumServe = calculateServings(MAX_GRAMS, report.g, &report.sumServe);

	report.perServe = calculateCostPerServing(&report.rate, &report.sumServe, &report.perServe);

	calo = report.calories * report.sumServe;

	report.calPerServe = calculateCostPerCal(&report.rate, &calo, &report.calPerServe);

	return(report);
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\n");
	printf("Analysis Report (Note: Serving = %dg)\n", MAX_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheap)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.sku, report.rate, report.weightLbs, report.kg, report.g, report.calories, report.sumServe, report.perServe, report.calPerServe);
}

// 17. Display the Cheapest Findings
void displayFinalAnalysis(const struct CatFoodInfo cheaperOption)
{
	printf("\n");
	printf("Final Analysis\n--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", cheaperOption.sku, cheaperOption.price);
	printf("Happy shopping!\n");
}