#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the number of days in a week
#define NUM_DAYS_IN_WEEK 7

// Structure definition for a day
typedef struct {
    char *acDayName;   // Name of the day
    int iDate;         // Date of the activity
    char *acActivity;  // Description of the activity
} DAYTYPE;

// Function prototypes
DAYTYPE* CreateCal();
void ReadCal(DAYTYPE*);
void DispCal(DAYTYPE*);
void FreeCal(DAYTYPE*);

int main() {
    // Create a weekly calendar
    DAYTYPE *weeklyCalendar = CreateCal();
    if (weeklyCalendar == NULL) {
        printf("Error: Memory allocation failed.\n");
        return -1;
    }

    // Read activities for the calendar
    ReadCal(weeklyCalendar);

    // Display the calendar details
    DispCal(weeklyCalendar);

    // Free the allocated memory
    FreeCal(weeklyCalendar);

    return 0;
}

// Function to create a weekly calendar with default values
DAYTYPE* CreateCal() {
    int i;
    DAYTYPE *calendar = (DAYTYPE*)malloc(NUM_DAYS_IN_WEEK * sizeof(DAYTYPE));
    if (calendar == NULL) {
        return NULL; // Memory allocation failed
    }

    // Initialize the calendar with default values
    for (i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        calendar[i].acDayName = NULL;
        calendar[i].iDate = 0;
        calendar[i].acActivity = NULL;
    }

    return calendar;
}

// Function to read calendar activities from the user
void ReadCal(DAYTYPE *calendar) {
    char choice;
    int i;

    for (i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        printf("Do you want to enter details for day %d? (y/n): ", i + 1);
        scanf(" %c", &choice); // Space before %c to skip newline
        getchar(); // Consume any leftover newline

        if (tolower(choice) == 'n') {
            continue;
        }

        // Input day name
        printf("Day Name: ");
        char dayBuffer[50];
        scanf("%s", dayBuffer);
        calendar[i].acDayName = strdup(dayBuffer); // Dynamically allocate memory for day name

        // Input date
        printf("Date: ");
        scanf("%d", &calendar[i].iDate);

        // Input activity
        printf("Activity: ");
        char activityBuffer[100];
        scanf(" %[^\n]", activityBuffer); // Read until newline
        calendar[i].acActivity = strdup(activityBuffer); // Dynamically allocate memory for activity

        printf("\n");
    }
}

// Function to display the weekly calendar
void DispCal(DAYTYPE *calendar) {
    int i;
    printf("\nWeekly Activity Details\n");
    for (i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        printf("\nDAY %d", i + 1);
        if (calendar[i].iDate == 0) {
            printf("\nNo Activity\n");
            continue;
        }
        printf("\nDay Name: %s", calendar[i].acDayName);
        printf("\nDate: %d", calendar[i].iDate);
        printf("\nActivity: %s\n", calendar[i].acActivity);
    }
}

// Function to free allocated memory for the calendar
void FreeCal(DAYTYPE *calendar) {
    int i;
    for (i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        free(calendar[i].acDayName);
        free(calendar[i].acActivity);
    }
    free(calendar);
}
