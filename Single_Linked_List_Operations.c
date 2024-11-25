#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size for the strings.
#define MAX 30

// Macro to handle memory allocation with error checking.
#define MALLOC(ptr, size, type) \
    ptr = (type) malloc(size); \
    if (ptr == NULL) { \
        fprintf(stderr, "Insufficient Memory\n"); \
        exit(EXIT_FAILURE); \
    }

// Define a structure for student data.
struct Student {
    int usn;                // Unique student number
    char name[MAX];         // Name of the student
    char programme[MAX];    // Programme the student is enrolled in
    int semester;           // Semester the student is currently in
    char phone[MAX];        // Phone number of the student
    struct Student *next;   // Pointer to the next student in the list
};

// Define a pointer to the structure for easier handling of linked list.
typedef struct Student* StudentNode;

// Function prototypes
StudentNode createStudentList(StudentNode, int);
StudentNode insertStudentFront(StudentNode);
StudentNode insertStudentRear(StudentNode);
StudentNode deleteStudentFront(StudentNode);
StudentNode deleteStudentRear(StudentNode);
void displayStudentList(StudentNode);
void readStudentData();

// Global variable declarations for student data
int usn;                // Student USN
char studentName[MAX];  // Student name
char programme[MAX];    // Programme name
int semester;           // Semester
char phone[MAX];        // Phone number

// Main function
int main() {
    int choice, done = 0;
    StudentNode studentList = NULL;  // Initialize the student list as empty

    while (!done) {
        // Menu for the operations
        printf("\n1. Create Student List\n2. Insert Student at Front\n3. Insert Student at Rear\n");
        printf("4. Delete Student from Front\n5. Delete Student from Rear\n6. Display Students\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of students: ");
                int n;
                scanf("%d", &n);
                studentList = createStudentList(studentList, n);
                break;

            case 2:
                readStudentData();
                studentList = insertStudentFront(studentList);
                break;

            case 3:
                readStudentData();
                studentList = insertStudentRear(studentList);
                break;

            case 4:
                studentList = deleteStudentFront(studentList);
                break;

            case 5:
                studentList = deleteStudentRear(studentList);
                break;

            case 6:
                displayStudentList(studentList);
                break;

            case 7:
                done = 1;
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to read student data from the user
void readStudentData() {
    printf("Enter Student USN: ");
    scanf("%d", &usn);

    printf("Enter Student Name: ");
    scanf("%s", studentName);

    printf("Enter Student Programme: ");
    scanf("%s", programme);

    printf("Enter Semester: ");
    scanf("%d", &semester);

    printf("Enter Student Phone: ");
    scanf("%s", phone);
}

// Function to create a list of students with front insertion
StudentNode createStudentList(StudentNode first, int n) {
    if (first == NULL) {
        for (int i = 1; i <= n; i++) {
            printf("Enter details for Student <%d>:\n", i);
            readStudentData();
            first = insertStudentFront(first);
        }
    } else {
        printf("The list already contains student data.\n");
    }

    return first;
}

// Function to insert a student at the front of the list
StudentNode insertStudentFront(StudentNode first) {
    StudentNode newNode;

    // Allocate memory for the new node
    MALLOC(newNode, sizeof(struct Student), StudentNode);

    // Copy data to the new node
    newNode->usn = usn;
    strcpy(newNode->name, studentName);
    strcpy(newNode->programme, programme);
    newNode->semester = semester;
    strcpy(newNode->phone, phone);
    
    // Make the new node point to the previous first node
    newNode->next = first;
    
    // Update the first pointer to point to the new node
    first = newNode;

    return first;
}

// Function to insert a student at the rear of the list
StudentNode insertStudentRear(StudentNode first) {
    StudentNode newNode, temp = first;

    // Allocate memory for the new node
    MALLOC(newNode, sizeof(struct Student), StudentNode);

    // Copy data to the new node
    newNode->usn = usn;
    strcpy(newNode->name, studentName);
    strcpy(newNode->programme, programme);
    newNode->semester = semester;
    strcpy(newNode->phone, phone);
    newNode->next = NULL;

    // If the list is empty, the new node becomes the first node
    if (first == NULL) {
        first = newNode;
    } else {
        // Traverse the list to find the last node
        while (temp->next) {
            temp = temp->next;
        }
        // Link the last node to the new node
        temp->next = newNode;
    }

    return first;
}

// Function to delete the student from the front of the list
StudentNode deleteStudentFront(StudentNode first) {
    if (first == NULL) {
        printf("Can't delete, the list is empty.\n");
    } else {
        StudentNode temp = first;
        first = first->next;
        free(temp); // Free the memory of the deleted node
    }

    return first;
}

// Function to delete the student from the rear of the list
StudentNode deleteStudentRear(StudentNode first) {
    if (first == NULL) {
        printf("Can't delete, the list is empty.\n");
        return first;
    }

    if (first->next == NULL) {
        free(first);
        return NULL;
    }

    StudentNode temp = first;
    StudentNode prev = NULL;

    // Traverse the list to find the last node
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }

    // Free the last node and update the second last node's next pointer to NULL
    free(temp);
    prev->next = NULL;

    return first;
}

// Function to display the list of students
void displayStudentList(StudentNode first) {
    int count = 0;
    if (first == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("\nStudent List:\n");
        printf("USN\tName\tProgramme\tSemester\tPhone\n");

        // Traverse the list and display each student's data
        while (first) {
            printf("%d\t%s\t%s\t%d\t%s\n", first->usn, first->name, first->programme, first->semester, first->phone);
            first = first->next;
            count++;
        }

        printf("Total students: %d\n", count);
    }
}
