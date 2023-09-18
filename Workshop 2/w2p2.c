/*
*****************************************************************************
<assessment name example: Workshop - #2 (Part-1)>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NLL
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
	const double TAX = 0.13;
	const char patSize = 'S', salSize = 'M', tomSize = 'L';
	double smallShirt, mediumShirt, largeShirt;
	int patBuy, salBuy, tomBuy;
	double subTotal1, subTotal2, subTotal3, taxes1, taxes2, taxes3;
	double total1, total2, total3;
	double fullSubtotal, taxes, total;
	int looniesQty, tooniesQty, quartersQty, nickelQty, dimesQty, penniesQty, subIn, taxIn, totaltaxIn, totalIn;
	double balance;
	double toonies = 2.0, loonies = 1.0, quarter = 25, dime = 10, nickel = 5;

	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf("%lf", &smallShirt);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%lf", &mediumShirt);
	printf("Enter the price for a LARGE shirt: $");
	scanf("%lf", &largeShirt);
	
	printf("\nShirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%0.2lf\n", smallShirt);
	printf("MEDIUM : $%0.2lf\n", mediumShirt);
	printf("LARGE  : $%0.2lf\n", largeShirt);
	printf("\nPatty's shirt size is '%c'\n", patSize);
	
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &patBuy);
	
	printf("\nTommy's shirt size is '%c'\n", tomSize);
	printf("Number of shirts Tommy is buying: ");
	scanf("%d", &tomBuy);
	
	printf("\nSally's shirt size is '%c'\n", salSize);
	printf("Number of shirts Sally is buying: ");
	scanf("%d", &salBuy);
	printf("\n");
	subTotal1 = patBuy * smallShirt;
	subTotal2 = salBuy * mediumShirt;
	subTotal3 = tomBuy * largeShirt;

	taxes1 = subTotal1 * TAX;
	taxes2 = subTotal2 * TAX;
	taxes3 = subTotal3 * TAX;

	total1 = subTotal1 + taxes1;
	total2 = subTotal2 + taxes2;
	total3 = subTotal3 + taxes3;

	fullSubtotal = subTotal1 + subTotal2 + subTotal3;
	taxes = taxes1 + taxes2 + taxes3;
	total = total1 + total2 + total3;

	printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("Patty    S    %0.2lf  %2d %9.4lf%8.2lf00%8.2lf00\n", smallShirt, patBuy, subTotal1, taxes1, total1);
	printf("Sally    M    %0.2lf  %2d %9.4lf%8.2lf00%8.2lf00\n", mediumShirt, salBuy, subTotal2, taxes2, total2);
	printf("Tommy    L    %0.2lf  %2d %9.4lf%8.2lf00%8.2lf00\n", largeShirt, tomBuy, subTotal3, taxes3, total3);
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("                        %9.4lf %7.2lf00  %6.2lf00\n", fullSubtotal, taxes, total);

	//coins for subtotal
	balance = fullSubtotal;
	printf("\nDaily retail sales represented by coins\n");
	printf("=======================================\n");
	printf("\nSales EXCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	printf("            %8.2lf00\n", balance);
	tooniesQty = balance / toonies;
	balance -= (tooniesQty * toonies);
	printf("Toonies  %3d %7.2lf00\n", tooniesQty, balance);
	looniesQty = balance / loonies;
	balance -= (looniesQty * loonies);
	printf("Loonies  %3d %7.2lf00\n", looniesQty, balance);
	balance *= 100;
	quartersQty = balance / quarter;
	if (quartersQty >= 1) {
		balance -= (quartersQty * quarter);
	}
	printf("Quarters %3d %7.2lf00\n", quartersQty, balance/100);
	dimesQty = balance / dime;
	if (dimesQty >= 1) {
		balance -= (dimesQty * dime);
	}
	printf("Dimes    %3d %7.2lf00\n", dimesQty, balance/100);
	nickelQty = balance / nickel;
	if (nickelQty >= 1) {
		balance -= (nickelQty * nickel);
	}
	printf("Nickels  %3d %7.2lf00\n", nickelQty, balance/100);
	if (balance >= 3)
	{
		penniesQty = balance;
	}
	else if (balance > 1.5) {
		penniesQty = 2;
	}
	else if (balance == 0) {
		penniesQty = 0;
	}
	else {
		penniesQty = 1;
	}
	balance = 0;
	printf("Pennies  %3d %7.2lf00\n", penniesQty, balance);

	double avgCost = fullSubtotal / (patBuy + salBuy + tomBuy);
	printf("\nAverage cost/shirt: $%0.4lf", avgCost);



	//Coins for Total
	balance = total;
	printf("\n\nSales INCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	printf("            %8.2lf00\n", balance);
	tooniesQty = balance / toonies;
	balance -= (tooniesQty * toonies);
	printf("Toonies  %3d %7.2lf00\n", tooniesQty, balance);
	looniesQty = balance / loonies;
	balance -= (looniesQty * loonies);
	printf("Loonies  %3d %7.2lf00\n", looniesQty, balance);
	balance *= 100;
	quartersQty = balance / quarter;
	if (quartersQty >= 1) {
		balance -= (quartersQty * quarter);
	}
	printf("Quarters %3d %7.2lf00\n", quartersQty, balance / 100);
	dimesQty = balance / dime;
	if (dimesQty >= 1) {
		balance -= (dimesQty * dime);
	}
	printf("Dimes    %3d %7.2lf00\n", dimesQty, balance / 100);
	nickelQty = balance / nickel;
	if (nickelQty >= 1) {
		balance -= (nickelQty * nickel);
	}
	printf("Nickels  %3d %7.2lf00\n", nickelQty, balance / 100);
	if (balance >= 3)
	{
		penniesQty = balance;
	}
	else if (balance > 1.5) {
		penniesQty = 2;
	}
	else if (balance == 0) {
		penniesQty = 0;
	}
	else {
		penniesQty = 1;
	}
	balance = 0;
	printf("Pennies  %3d %7.2lf00\n", penniesQty, balance);

	//converting to integer
	
	subIn = fullSubtotal * 1000;

	if (subIn % 10 >= 5)
	{
		subIn = subIn / 10 + 1;
	}
	else
	{
		subIn = subIn / 10;
	}

	//converting tax float to integer
	taxIn = TAX * 100;

	 totaltaxIn = taxIn * subIn;

	//rounding tax
	if (totaltaxIn % 100 >= 50)
	{
		totaltaxIn = totaltaxIn / 100 + 1;
	}
	else
	{
		totaltaxIn = totaltaxIn / 100;
	}

	totalIn = (totaltaxIn + subIn)*1000;
	total = (double)(totalIn)/100000;

	double avgCostTax = total / (patBuy + salBuy + tomBuy);
	printf("\nAverage cost/shirt: $%0.4lf\n", avgCostTax);

	return 0;
}
