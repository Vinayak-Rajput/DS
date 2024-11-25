#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30  // Define the maximum size for strings

// Define the structure for storing employee data
struct Employee {
    int ssn;                // Employee SSN (Social Security Number)
    char name[MAX];         // Employee's name
    char department[MAX];   // Employee's department
    char designation[MAX];  // Employee's designation
    float salary;           // Employee's salary
    char phone[MAX];        // Employee's phone number
    struct Employee *prev;  // Pointer to the previous employee in the list
    struct Employee *next;  // Pointer to the next employee in the list
};

// Define a pointer to the Employee structure for easier handling of the linked list
typedef struct Employee* EmployeeNode;

// Macro for memory allocation with error handling
#define MALLOC(p, size, type)  \
    p = (type)malloc(size);    \
    if (p == NULL) {           \
        printf("Insufficient Memory\n"); \
        exit(EXIT_FAILURE);    \
    }

// Function prototypes
EmployeeNode createEmployeeList(EmployeeNode, int);
EmployeeNode insertEmployeeFront(EmployeeNode);
EmployeeNode insertEmployeeRear(EmployeeNode);
EmployeeNode deleteEmployeeFront(EmployeeNode);
EmployeeNode deleteEmployeeRear(EmployeeNode);
void displayEmployeeList(EmployeeNode);
void readEmployeeData();

// Global variables for holding employee data
int ssn;                    // Employee SSN
char name[MAX];             // Employee name
char department[MAX];       // Department
char designation[MAX];      // Designation
float salary;               // Salary
char phone[MAX];            // Phone number

// Main function
int main() {
    int choice, done = 0;
    EmployeeNode employeeList = NULL;  // Initialize the employee list as empty

    while (!done) {
        // Display menu for operations
        printf("\n1. Create Employee List\n2. Insert Employee at Front\n3. Insert Employee at Rear\n");
        printf("4. Delete Employee from Front\n5. Delete Employee from Rear\n6. Display Employees\n7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of employees: ");
                int n;
                scanf("%d", &n);
                employeeList = createEmployeeList(employeeList, n);
                break;

            case 2:
                readEmployeeData();
                employeeList = insertEmployeeFront(employeeList);
                break;

            case 3:
                readEmployeeData();
                employeeList = insertEmployeeRear(employeeList);
                break;

            case 4:
                employeeList = deleteEmployeeFront(employeeList);
                break;

            case 5:
                employeeList = deleteEmployeeRear(employeeList);
                break;

            case 6:
                displayEmployeeList(employeeList);
                break;

            case 7:
                done = 1;
                break;

            default:
                printf("Invalid Choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to read employee data from user input
void readEmployeeData() {
    printf("Enter Employee SSN: ");
    scanf("%d", &ssn);

    printf("Enter Employee Name: ");
    scanf("%s", name);

    printf("Enter Employee Department: ");
    scanf("%s", department);

    printf("Enter Designation: ");
    scanf("%s", designation);

    printf("Enter Salary: ");
    scanf("%f", &salary);

    printf("Enter Phone: ");
    scanf("%s", phone);
}

// Function to create a list of employees using front insertion
EmployeeNode createEmployeeList(EmployeeNode first, int n) {
    if (first == NULL) {
        for (int i = 1; i <= n; i++) {
            printf("Enter details for Employee <%d>:\n", i);
            readEmployeeData();
            first = insertEmployeeFront(first);
        }
    } else {
        printf("The list already contains employee data.\n");
    }

    return first;
}

// Function to insert an employee at the front of the list
EmployeeNode insertEmployeeFront(EmployeeNode first) {
    EmployeeNode newNode;

    // Allocate memory for the new employee node
    MALLOC(newNode, sizeof(struct Employee), EmployeeNode);

    // Copy data to the new node
    newNode->ssn = ssn;
    strcpy(newNode->name, name);
    strcpy(newNode->department, department);
    strcpy(newNode->designation, designation);
    newNode->salary = salary;
    strcpy(newNode->phone, phone);
    newNode->prev = NULL;
    newNode->next = first;

    // If the list is not empty, set the previous pointer of the first employee to the new node
    if (first != NULL) {
        first->prev = newNode;
    }

    return newNode;  // Return the new node as the first element in the list
}

// Function to insert an employee at the rear of the list
EmployeeNode insertEmployeeRear(EmployeeNode first) {
    EmployeeNode newNode, current = first;

    // Traverse the list to find the last node
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }

    // Allocate memory for the new employee node
    MALLOC(newNode, sizeof(struct Employee), EmployeeNode);

    // Copy data to the new node
    newNode->ssn = ssn;
    strcpy(newNode->name, name);
    strcpy(newNode->department, department);
    strcpy(newNode->designation, designation);
    newNode->salary = salary;
    strcpy(newNode->phone, phone);
    newNode->next = NULL;

    // If the list is empty, set the first element to the new node
    if (current == NULL) {
        first = newNode;
    } else {
        // Otherwise, link the last node to the new node
        current->next = newNode;
        newNode->prev = current;
    }

    return first;
}

// Function to delete the employee from the front of the list
EmployeeNode deleteEmployeeFront(EmployeeNode first) {
    if (first == NULL) {
        printf("Can't delete, the list is empty.\n");
        return NULL;
    }

    EmployeeNode temp = first;
    first = first->next;

    if (first != NULL) {
        first->prev = NULL;
    }

    free(temp);  // Free the memory of the deleted node
    return first;
}

// Function to delete the employee from the rear of the list
EmployeeNode deleteEmployeeRear(EmployeeNode first) {
    if (first == NULL) {
        printf("Can't delete, the list is empty.\n");
        return NULL;
    }

    EmployeeNode current = first;

    // Traverse the list to find the last node
    while (current->next != NULL) {
        current = current->next;
    }

    // If the list has only one node
    if (current->prev == NULL) {
        free(current);
        return NULL;
    }

    // Otherwise, update the previous node to be the last node
    current->prev->next = NULL;
    free(current);

    return first;
}

// Function to display the details of all employees in the list
void displayEmployeeList(EmployeeNode first) {
    if (first == NULL) {
        printf("The list is empty.\n");
        return;
    }

    int count = 0;
    printf("\nEmployee List:\n");
    printf("SSN\tName\tDepartment\tDesignation\tSalary\tPhone\n");

    // Traverse the list and display each employee's details
    while (first != NULL) {
        printf("%d\t%s\t%s\t%s\t%.2f\t%s\n", first->ssn, first->name, first->department, first->designation, first->salary, first->phone);
        first = first->next;
        count++;
    }

    printf("Total employees: %d\n", count);
}
