/*
*****************************************************************************
                          Workshop - #3 (P2)
Full Name  : Jaaved Dewan
Student ID#: 126045178
Email      : jdewan@myseneca.ca or jilred15@gmail.com
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    char coffeeType1;
    char coffeeGrind1;
    float coffeeLb1;
    char coffeeCream1;
    float coffeeTemp1;


    char coffeeType2;
    char coffeeGrind2;
    float coffeeLb2;
    char coffeeCream2;
    float coffeeTemp2;


    char coffeeType3;
    char coffeeGrind3;
    float coffeeLb3;
    char coffeeCream3;
    float coffeeTemp3;

 
    char coffeeStrength;
    char coffeeCream;
    int dailyServings;
    char coffeeMaker;
    // Note:
    // You can convert Celsius to Fahrenheit given the following formula:
    // fahrenheit = (celsius * 1.8) + 32.0);

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");

    printf("\n");

    printf("Enter the coffee product information being sold today...\n");

    printf("\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType1);
    
    //Dealing with workshop's odd character-case issue.
    if (coffeeType1 == 'l')
        coffeeType1 = 'L';
    else if (coffeeType1 == 'b')
        coffeeType2 = 'B';
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffeeGrind1);
    if (coffeeGrind1 == 'c')
        coffeeGrind1 = 'C';
    else if (coffeeGrind1 == 'f')
        coffeeGrind1 = 'F';
    printf("Bag weight (g): ");
    scanf(" %f", &coffeeLb1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeCream1);
    if (coffeeCream1 == 'y')
        coffeeCream1 = 'Y';
    else if (coffeeCream1 == 'n')
        coffeeCream1 = 'N';
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &coffeeTemp1);

    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType2);
    if (coffeeType2 == 'l')
        coffeeType2 = 'L';
    else if (coffeeType2 == 'b')
        coffeeType2 = 'B';
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffeeGrind2);
    if (coffeeGrind2 == 'c')
        coffeeGrind2 = 'C';
    else if (coffeeGrind2 == 'f')
        coffeeGrind2 = 'F';
    printf("Bag weight (g): ");
    scanf(" %f", &coffeeLb2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeCream2);
    if (coffeeCream2 == 'y')
        coffeeCream2 = 'Y';
    else if (coffeeCream2 == 'n')
        coffeeCream2 = 'N';
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &coffeeTemp2);

    printf("\n");
 
    printf("COFFEE-3...\n");

    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType3);
    if (coffeeType3 == 'l')
        coffeeType3 = 'L';
    else if (coffeeType3 == 'b')
        coffeeType3 = 'B';
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffeeGrind3);
    if (coffeeGrind3 == 'c')
        coffeeGrind3 = 'C';
    else if (coffeeGrind3 == 'f')
        coffeeGrind3 = 'F';
    printf("Bag weight (g): ");
    scanf(" %f", &coffeeLb3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeCream3);
    if (coffeeCream3 == 'y')
        coffeeCream3 = 'Y';
    else if (coffeeCream3 == 'n')
        coffeeCream3 = 'N';
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &coffeeTemp3);
   
    printf("\n");

    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4.0lf |  %5.3lf |   %d   |  %3.1lf | %3.1lf\n", coffeeType1 == 'L' , coffeeType1 == 'B' , coffeeGrind1 == 'C' , coffeeGrind1 == 'F' , coffeeLb1, coffeeLb1 / GRAMS_IN_LBS, coffeeCream1 == 'Y' , coffeeTemp1, (coffeeTemp1 * 1.8 + 32));
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4.0lf |  %5.3lf |   %d   |  %3.1lf | %3.1lf\n", coffeeType2 == 'L' , coffeeType2 == 'B' , coffeeGrind2 == 'C' , coffeeGrind2 == 'F' , coffeeLb2, coffeeLb2 / GRAMS_IN_LBS, coffeeCream2 == 'Y' , coffeeTemp2, (coffeeTemp2 * 1.8 + 32));
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4.0lf |  %5.3lf |   %d   |  %3.1lf | %3.1lf\n", coffeeType3 == 'L' , coffeeType3 == 'B' , coffeeGrind3 == 'C' , coffeeGrind3 == 'F' , coffeeLb3, coffeeLb3 / GRAMS_IN_LBS, coffeeCream3 == 'Y' , coffeeTemp3, (coffeeTemp3 * 1.8 + 32));
 
    printf("\n");
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStrength);

    if (coffeeStrength == 'm')
        coffeeStrength = 'M';
    else if (coffeeStrength == 'r')
        coffeeStrength = 'R';
    
    
    if (coffeeStrength == 'R')
        coffeeStrength = 'B';
    else
        coffeeStrength = 'L';

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeCream);
    if (coffeeCream == 'y')
        coffeeCream = 'Y';
    else if (coffeeCream == 'n')
        coffeeCream = 'N';
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);

    if (dailyServings <= 4)
        dailyServings = 250;
    else if (dailyServings >= 10)
        dailyServings = 1000;
    else
        dailyServings = 500;

    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &coffeeMaker);

    if (coffeeMaker == 'c')
        coffeeMaker = 'C';
    else if (coffeeMaker == 'r')
        coffeeMaker = 'R';


    if (coffeeMaker == 'R')
        coffeeMaker = 'C';
    else
        coffeeMaker = 'F';

    //Changing Temperature to match making equipment
    if (coffeeTemp1 >= 70.0)
        coffeeTemp1 = 'F';
    else
        coffeeTemp1 = 'C';


    if (coffeeTemp2 >= 70.0)
        coffeeTemp2 = 'F';
    else
        coffeeTemp2 = 'C';

    if (coffeeTemp3 >= 70.0)
        coffeeTemp3 = 'F';
    else
        coffeeTemp3 = 'C';

    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");



    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");

    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", coffeeStrength == coffeeType1 , coffeeMaker == coffeeGrind1 , dailyServings == coffeeLb1 , coffeeCream == coffeeCream1 , coffeeTemp1 == coffeeMaker );

    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", coffeeStrength == coffeeType2 , coffeeMaker == coffeeGrind2 , dailyServings == coffeeLb2 , coffeeCream == coffeeCream2 , coffeeTemp2 == coffeeMaker );

    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", coffeeStrength == coffeeType3 , coffeeMaker == coffeeGrind3 , dailyServings == coffeeLb3 , coffeeCream == coffeeCream3 , coffeeTemp3 == coffeeMaker );
    
   
    printf("\n");
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStrength);


    if (coffeeStrength == 'm')
        coffeeStrength = 'M';
    else if (coffeeStrength == 'r')
        coffeeStrength = 'R';

    if (coffeeStrength == 'R')
        coffeeStrength = 'B';
    else
        coffeeStrength = 'L';

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeCream);
    if (coffeeCream == 'y')
        coffeeCream = 'Y';
    else if (coffeeCream == 'n')
        coffeeCream = 'N';
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);

    if (dailyServings <= 4)
        dailyServings = 250;
    else if (dailyServings >= 10)
        dailyServings = 1000;
    else
        dailyServings = 500;
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &coffeeMaker);

    if (coffeeMaker == 'c')
        coffeeMaker = 'C';
    else if (coffeeMaker == 'r')
        coffeeMaker = 'R';

    if (coffeeMaker == 'R')
        coffeeMaker = 'C';
    else
        coffeeMaker = 'F';

    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");

    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");

    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", coffeeStrength == coffeeType1 , coffeeMaker == coffeeGrind1 , dailyServings == coffeeLb1 , coffeeCream == coffeeCream1 , coffeeTemp1 == coffeeMaker );

    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", coffeeStrength == coffeeType2 , coffeeMaker == coffeeGrind2 , dailyServings == coffeeLb2 , coffeeCream == coffeeCream2 , coffeeTemp2 == coffeeMaker );

    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", coffeeStrength == coffeeType3 , coffeeMaker == coffeeGrind3 , dailyServings == coffeeLb3 , coffeeCream == coffeeCream3 , coffeeTemp3 == coffeeMaker );


    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
    printf("\n");


    return 0;
}