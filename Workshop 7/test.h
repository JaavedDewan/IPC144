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
#define MAX_PRODUCT 3
#define NUM_GRAMS 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    int calories;
    double weight;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)

int getIntPositive(int* int_ptr);

// 2. Get user input of double type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* double_ptr);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int no_of_products);

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int seq_number);

// 5. Display the formatted table header

void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData(int sku, double* price, double* weight, int calories);

// 7. Logic entry point
void start(void);
