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

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function protodescriptions are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}



//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0;
    int displayNumber = 0;
    displayPatientTableHeader();


    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            displayNumber++;
        }
    }
    if (displayNumber == 0)
    {
        printf("*** No records found ***");
    }
    printf("\n");
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientData(const struct Patient patient[], int max)
{
    int patientRecord = -1;

    while (patientRecord != 0)
    {
        printf("Search Options\n==========================\n1) By patient number\n2) By phone number\n..........................\n0) Previous menu\n..........................\nSelection: ");

        patientRecord = inputInt(0, 2);
        putchar('\n');

        if (patientRecord == 1)
        {
            searchPatientByPatientNumber(patient, max);
            putchar('\n');
            suspend();
        }
        if (patientRecord == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            putchar('\n');
            suspend();
        }
    }
}


// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void addPatient(struct Patient patient[], int max)
{
    int i;
    int recordCapacity = 0;
    int indexVal = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            recordCapacity++;
        }
    }
    if (max > recordCapacity)
    {
        for (i = 0; i < recordCapacity; i++)
        {
            if (patient[i].patientNumber == 0)
            {
                indexVal = i;
                break;
            }
        }
        patient[indexVal].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[indexVal]);
        
        printf("*** New patient record added ***\n");
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n");
    }
    putchar('\n');
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void editPatient(struct Patient patient[], int max)
{
    printf("Enter the patient number: ");

    int patientId = inputInt();
    putchar('\n');
    int indexVal = findPatientIndexByPatientNum(patientId, patient, max);

    if (indexVal == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        menuPatientEdit(&patient[indexVal]);
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void removePatient(struct Patient patient[], int max)
{
        int patientID = 0;
        char selection[30] = { '\0' };
        int indexVal = 0;
        
        printf("Enter the patient number: ");
        scanf(" %d", &patientID);
        
        clearInputBuffer();
        putchar('\n');
        indexVal = findPatientIndexByPatientNum(patientID, patient, max);
        
        if (indexVal != -1)
        {
            displayPatientData(&patient[indexVal], FMT_FORM);
            putchar('\n');
            printf("Are you sure you want to remove this patient record? (y/n): ");
           
            while (strcmp(selection, "y") != 0)
            {
                scanf(" %s", selection);
                clearInputBuffer();
                
                if (strcmp(selection, "y") == 0)
                {
                    strcpy(patient[indexVal].name, "\0");
                    patient[indexVal].patientNumber = 0;
                    strcpy(patient[indexVal].phone.description, "\0");
                    strcpy(patient[indexVal].phone.number, "\0");
                    
                    printf("Patient record has been removed!\n\n");
                }
                else
                {
                    printf("ERROR: Character must be one of [yn]: ");
                }
            }
        }
        else
        {
            printf("ERROR: Patient record not found!\n\n");
        }
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:

void viewAllAppointments(struct ClinicData* data)
{
    int i = 0;
    int j = 0;
    int appointmentCapacity = 0;
    

    appointmentCapacity = calculateAppointmentsArraySize(data->appointments, data -> maxAppointments);
    

    appointmentSorter(data->appointments, appointmentCapacity);
    if (data)
    {
        displayScheduleTableHeader(&data->appointments->date, APP_ALL);
        
        for (i = 0; i < data->maxAppointments; i++)
        {
            
            for (j = 0; j < data->maxPatient; j++)
            {
                
                if (data->appointments[i].patientNumber == data -> patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data -> appointments[i], APP_ALL);
                    break;
                }
            }
        }
        putchar('\n');
    }
    else
    {
        printf("*** No records found ***\n\n");
    }
}

// View appointment schedule for the user input date
// Todo:

void viewAppointmentSchedule(struct ClinicData* data)
{
    int i, j;
    int appointmentCapacity = 0;
    struct Date userInput = { '\0' };

    checkLeapYear(&userInput);
    putchar('\n');


    appointmentCapacity = calculateAppointmentsArraySize(data->appointments, data -> maxAppointments);
    
    displayScheduleTableHeader(&userInput, APP_DATE);
    for (i = 0; i < appointmentCapacity; i++)
    {
 
        if (userInput.year == data->appointments[i].date.year &&
            userInput.month == data->appointments[i].date.month && userInput.day == data -> appointments[i].date.day)
        {
            for (j = 0; j < appointmentCapacity; j++)
            {
                if (data->appointments[i].patientNumber == data -> patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data -> appointments[i], APP_DATE);
                }
            }
        }
    }
    putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:

void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{
    int i;
    int appointmentCapacity = 0;
    int flag = 1;

    appointmentCapacity = calculateAppointmentsArraySize(appointments, maxAppointments);

    if (maxAppointments > appointmentCapacity)
    {
        printf("Patient Number: ");
        scanf(" %d", &appointments[appointmentCapacity].patientNumber);
        clearInputBuffer();


        if (findPatientIndexByPatientNum(appointments[appointmentCapacity].patientNumber,
            patients, maxPatient) != -1)
        {
            while (flag == 1)
            {
                int timeslot = 0;
                checkLeapYear(&appointments[appointmentCapacity].date);
                
                while (timeslot == 0)
                {
                    printf("Hour (0-23)  : ");
                    appointments[appointmentCapacity].time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    appointments[appointmentCapacity].time.min = inputIntRange(0, 59);

                        for (i = 0; i < appointmentCapacity; i++)
                        {
                            if (appointments[appointmentCapacity].date.year == appointments[i].date.year && appointments[appointmentCapacity].date.month == appointments[i].date.month && appointments[appointmentCapacity].date.day == appointments[i].date.day && appointments[appointmentCapacity].time.hour == appointments[i].time.hour && appointments[appointmentCapacity].time.min == appointments[i].time.min)
                            {
                                printf("\nERROR: Appointment timeslot is not available!\n\n");
                                    timeslot = 1;
                            }
                        }

                    if (timeslot == 0)
                    {
                        if (appointments[appointmentCapacity].time.hour >= START_HOUR
                            && appointments[appointmentCapacity].time.hour <= END_HOUR)
                        {
                            if (appointments[appointmentCapacity].time.min >=
                                START_MIN && appointments[appointmentCapacity].time.min <= END_MIN)
                            {
                                printf("\n*** Appointment scheduled! ***\n\n");
                                    flag = 0;
                                break;
                            }
                            else
                            {
                                printf("ERROR: Time must be between 10:00 and 14:00 in %d minute intervals.\n\n", MIN_INT);
                            }
                        }
                        else
                        {
                            printf("ERROR: Time must be between 10:00 and 14:00 in %d minute intervals.\n\n", MIN_INT);
                        }
                    }
                }
            }
        }
        else
        {
            printf("\nERROR: Patient record not found!\n\n");
        }
    }
}

// Remove an appointment record from the appointment array
// Todo:

void removeAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatient)
{
    int indexVal;
    char selection;
    int i;
    struct Appointment removeAppm = { 0 };
    int appointmentCapacity = 0;
 
    appointmentCapacity = calculateAppointmentsArraySize(appointments, maxAppointments);

    appointmentSorter(appointments, appointmentCapacity);
    
    printf("Patient Number: ");
    scanf(" %d", &removeAppm.patientNumber);
    clearInputBuffer();
    
    indexVal = findPatientIndexByPatientNum(removeAppm.patientNumber, patients, maxPatient);
    
    if (indexVal != -1)
    {
        checkLeapYear(&removeAppm.date);
        putchar('\n');
        displayPatientData(&patients[indexVal], FMT_FORM);
        
        printf("Are you sure you want to remove this appointment (y,n): ");
        scanf(" %c", &selection);
        clearInputBuffer();
        
        if (selection == 'y')
        {

            for (i = 0; i < maxAppointments; i++)
            {
                if (removeAppm.patientNumber == appointments[i].patientNumber && removeAppm.date.day == appointments[i].date.day && removeAppm.date.month == appointments[i].date.month && removeAppm.date.year == appointments[i].date.year)
                {
                    indexVal = i;
                    break;
                }
            }

            appointments[indexVal].patientNumber = 0;
            appointments[indexVal].date.day = 0;
            appointments[indexVal].date.month = 0;
            appointments[indexVal].date.year = 0;
            appointments[indexVal].time.hour = 0;
            appointments[indexVal].time.min = 0;
            
            printf("\nAppointment record has been removed!\n\n");
        }
        else
        {
            printf("Operation aborted.\n\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}

//Calculate the size of the appointments array
int calculateAppointmentsArraySize(const struct Appointment* appointments, int maxAppointment)
{
    int appointmentCapacity = 0;
    int i;
    
    for (i = 0; i < maxAppointment; i++)
    {
        if (appointments[i].date.day != 0)
        {
            appointmentCapacity++;
        }
    }
    return appointmentCapacity;
}

//Check Leap Year
void checkLeapYear(struct Date* leapYear)
{
    printf("Year        : ");
    
    scanf(" %d", &leapYear->year);
    clearInputBuffer();
    
    printf("Month (1-12): ");
    
    leapYear->month = inputIntRange(0, 12);
    
    switch (leapYear->month)
    {
    case 1:

        printf("Day (1-31)  : ");
        leapYear->day = inputIntRange(0, 31);
        break;

    case 2:

        if (leapYear->year % 400 == 0 || leapYear->year % 100 == 0 ||
            leapYear->year % 4 == 0)
        {
            printf("Day (1-29)  : ");
            leapYear->day = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            leapYear->day = inputIntRange(1, 28);
        }
        break;

    case 3:

        printf("Day (1-31)  : ");
        leapYear->day = inputIntRange(1, 31);
        break;

    case 4:

        printf("Day (1-30)  : ");
        leapYear->day = inputIntRange(1, 30);
        break;

    case 5:

        printf("Day (1-31)  : ");
        leapYear->day = inputIntRange(1, 31);
        break;

    case 6:

        printf("Day (1-30)  : ");
        leapYear->day = inputIntRange(1, 30);
        break;

    case 7:

        printf("Day (1-31)  : ");
        leapYear->day = inputIntRange(1, 31);
        break;

    case 8:

        printf("Day (1-31)  : ");
        leapYear->day = inputIntRange(1, 31);
        break;

    case 9:

        printf("Day (1-30)  : ");
        leapYear->day = inputIntRange(1, 30);
        break;

    case 10:

        printf("Day (1-31)  : ");
        leapYear->day = inputIntRange(1, 31);
        break;

    case 11:

        printf("Day (1-30)  : ");
        leapYear->day = inputIntRange(1, 30);
        break;

    case 12:

        printf("Day (1-31)  : ");
        leapYear->day = inputIntRange(1, 31);
        break;

    default:

        inputIntRange(1, 12);
        break;
    }
}

//Selection Sort
void appointmentSorter(struct Appointment* appointments, int size)
{
    int i, j;
    struct Appointment temp;
    for (i = size - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {

            if (appointments[j].date.year > appointments[j + 1].date.year)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }

            else if (appointments[j].date.year == appointments[j + 1].date.year && appointments[j].date.day > appointments[j + 1].date.day)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }

            else if (appointments[j].date.year == appointments[j + 1].date.year && appointments[j].date.day == appointments[j + 1].date.day && appointments[j].time.hour > appointments[j + 1].time.hour)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }

            else if (appointments[j].date.year == appointments[j + 1].date.year && appointments[j].date.day == appointments[j + 1].date.day && appointments[j].time.hour == appointments[j + 1].time.hour && appointments[j].time.min > appointments[j + 1].time.min)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    printf("Search by patient number: ");

    int patientId = inputInt();
    putchar('\n');
    int indexNum = findPatientIndexByPatientNum(patientId, patient, max);

    if (indexNum == -1)
    {
        printf("*** No records found ***\n");
    }
    else
    {
        displayPatientData(&patient[indexNum], FMT_FORM);
    }
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i = 0;
    char patientPhone[11] = { 0 };
    int displayedNumber = 0;

    printf("Search by phone number: ");

    inputCString(patientPhone, 10, 10);
    putchar('\n');
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (strcmp(patientPhone, patient[i].phone.number) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            displayedNumber++;
        }
    }
    if (displayedNumber == 0)
    {
        printf("\n*** No records found ***\n");
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int nextPatientNumber(const struct Patient patient[], int max)
{
    int i = 0;
    int highestNum = patient[i].patientNumber;

    for (i = 1; i < max; i++)
    {
        if (patient[i].patientNumber > highestNum)
            highestNum = patient[i].patientNumber;
    }
    return highestNum + 1;
}


// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[],
    int max)
{
    int i = 0;
    int patientIndex = -1;

    for (i = 0; i < max && patientIndex == -1; i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            patientIndex = i;
        }
    }
    return patientIndex;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    do
    {
        scanf(" %[^\n]", patient->name);
        clearInputBuffer();
        if (strlen(patient->name) > NAME_LEN)
        {
            printf("ERROR: String length must be no more than 15 chars: ");
        }
    } while (strlen(patient->name) > NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPhoneData(struct Phone* phone)
{
    int phoneType;
    char phoneNum[15] = { '\0' };
    
    
    
    printf("Phone Information\n-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    
    
    phoneType = inputIntRange(1, 4);
    putchar('\n');
    
    
    switch (phoneType)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
    }
    if (phoneType != 4)
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        do
        {
            scanf(" %[^\n]", phoneNum);
            clearInputBuffer();
            
            if (strlen(phoneNum) != PHONE_LEN)
            {
                printf("Invalid 10-digit number! Number: ");
            }
            else
            {
                strcpy(phone->number, phoneNum);
            }
        } while (strlen(phoneNum) != PHONE_LEN);
        putchar('\n');
    }
    else
    {
        strcpy(phone->number, "\0");
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:

int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* patientData = fopen(datafile, "r");
    int i = 0;
    int patientRecords = 0;
    
    
    if (patientData != NULL)
    {
        for (i = 0; i < max; i++)
        {
            //Check if the records are not empty and count the records
            if (fscanf(patientData, "%d|%[^|]|%[^|]|%[^\n]",
                &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number) > 0)
            {
                patientRecords++;
            }
        }
        fclose(patientData);
    }
    return patientRecords;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    FILE* appointmentData = fopen(datafile, "r");
    int i = 0;
    int appointmentRecords = 0;
    
    if (appointmentData != NULL)
    {
        for (i = 0; i < max; i++)
        {
            if (fscanf(appointmentData, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) > 0)
            {
                appointmentRecords++;
            }
        }
        fclose(appointmentData);
    }
    return appointmentRecords;
}