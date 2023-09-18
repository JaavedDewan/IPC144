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

int main(void) {
    const double TAX = 0.13; //tax
    const char patSize = 'S'; //size
    float smallShirt, mediumShirt, largeShirt; //shirts
    int patBuy, subTotal, total, taxInteger, totalTax;

    //input
    printf("Set Shirt Prices");
    printf("\n================\n");
    printf("Enter the price of a SMALL shirt: $");
    scanf("%f", &smallShirt);
    printf("Enter the price of a MEDIUM shirt: $");
    scanf("%f", &mediumShirt);
    printf("Enter the price of a LARGE shirt: $");
    scanf("%f", &largeShirt);

    printf("\n\nShirt Store Price List");
    printf("\n======================\n");
    printf("SMALL  :  $%.2f\n", smallShirt);
    printf("MEDIUM :  $%.2f\n", mediumShirt);
    printf("LARGE  :  $%.2f\n", largeShirt);

    printf("\nPatty\'s shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &patBuy);

    //convert from float to integer due to restriction.
    int ssInteger = smallShirt * 1000;

    //Rounding formula
    if (ssInteger % 10 >= 5) 
    {
        ssInteger = ssInteger / 10 + 1;
    }
    else
    {
        ssInteger = ssInteger / 10;
    }

    
    subTotal = patBuy * ssInteger;

    //converting tax float to integer
    taxInteger = TAX * 100;

    totalTax = taxInteger * subTotal;
    
    //rounding tax
    if (totalTax % 100 >= 50)
    {
        totalTax = totalTax / 100 + 1;
    }
    else 
    {
        totalTax = totalTax / 100;
    }

    total = subTotal + totalTax;



    printf("\nPatty\'s shopping cart...\n");
    printf("Contains : %i shirts\n", patBuy);

    /*(subTotal / 100) represents the portion of the number before the decimal.
      (subTotal % 100) represents the portion after the decimal.
      This is the case due to the restriction of only using integral data types.
    */

    printf("Sub-total: $%i.%i\n", subTotal/100, subTotal%100);
    printf("Taxes    : $ %i.%i\n", totalTax/100, totalTax%100);
    printf("Total    : $%i.%i\n", total/100, total%100);
    return 0;
}
