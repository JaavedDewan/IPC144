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
#define MAX_PRODUCT 3
#define MAX_GRAMS 64
#define LBS_KG 2.20462

struct CatFoodInfo
{
    int sku;
    double price;
    int calories;
    double weight;
};
struct ReportData
{
    int sku;
    double rate;
    int calories;
    double weightLbs;
    double kg;
    int g;
    double sumServe;
    double perServe;
    double calPerServe;
};

// Function: 1. Get user input of int type and validate for a positive number

int getIntPositive(int* i_num);

// Function: 2. Get user input of double type and validate for a positive number

double getDoublePositive(double* d_num);

// Function: 3. Opening Message

void openingMessage(const int msg);

// Function: 4. Get user input for cat food product

struct CatFoodInfo getCatFoodInfo(const int i);

// Function: 5. Display the formatted table header

void displayCatFoodHeader(void);

// Function: 6. Display a formatted record of cat food data

void displayCatFoodData(const int sku, const double price, const int calories, const double weight);

// Function: 7. Logic entry point

void start(void);

// Function: 8. convert lbs to kg
double convertLbsKg(const double* lbs, double* kg);

// Function: 9. convert lbs to g

int convertLbsG(const double* lbs, int* g);

// Function: 10. convert lbs to kg / g

void convertLbs(const double* lbs_convert, double* kg, int* g);

// Function: 11. calculate: servings based on gPerServ

double calculateServings(const int servingGrams, const int sumGrams, double* resultGrams);

// Function: 12. calculate: cost per serving

double calculateCostPerServing(const double* rate, const double* result, double* resultCost);
// Function: 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double* CostCalories);

// Function: 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo getDetailCatFood);

// Function: 15. Display the formatted table header for the analysis results

void displayReportHeader(void);

// Function: 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData reportinfo, const int cheap);

// Function: 17. Display the Cheapest Findings

void displayFinalAnalysis(const struct CatFoodInfo cheaperOption);

