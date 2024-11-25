#include <stdio.h>
#include <string.h>

// Macro to define the maximum stack size
#define MAX_SIZE 6

// Function prototypes
void push(int stack[], int *top, int element);
int pop(int stack[], int *top);
void display(int stack[], int top);
int isPalindrome(int stack[], int *top, char inputString[]);

int main() {
    int stack[MAX_SIZE]; // Stack array
    int top = -1;        // Top pointer for stack
    int element, poppedElement, isPalin, done = 0, choice;
    char inputString[MAX_SIZE];

    while (!done) {
        // Display menu
        printf("\nSTACK OPERATIONS USING ARRAY\n");
        printf("1. Push\n2. Pop\n3. Palindrome Check\n4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push operation
                printf("Enter the element to be pushed: ");
                scanf("%d", &element);
                push(stack, &top, element);
                display(stack, top);
                break;

            case 2: // Pop operation
                poppedElement = pop(stack, &top);
                if (poppedElement != -1) {
                    printf("Popped Element: %d\n", poppedElement);
                    display(stack, top);
                }
                break;

            case 3: // Palindrome check
                printf("Enter the string to check for palindrome: ");
                scanf("%s", inputString);
                top = -1; // Reset the stack for palindrome operation
                isPalin = isPalindrome(stack, &top, inputString);
                if (isPalin == 1)
                    printf("'%s' is a palindrome.\n", inputString);
                else
                    printf("'%s' is not a palindrome.\n", inputString);
                top = -1; // Reset the stack after palindrome check
                break;

            case 4: // Exit
                done = 1;
                break;

            default: // Invalid choice
                printf("Invalid Choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to push an element onto the stack
void push(int stack[], int *top, int element) {
    if (*top == MAX_SIZE - 1) {
        printf("Error: Stack Overflow\n");
    } else {
        ++(*top);
        stack[*top] = element;
    }
}

// Function to pop an element from the stack
int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Error: Stack Underflow\n");
        return -1; // Indicating stack is empty
    } else {
        return stack[(*top)--];
    }
}

// Function to display the stack elements
void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

// Function to check if the given string is a palindrome
int isPalindrome(int stack[], int *top, char inputString[]) {
    // Push all characters of the string onto the stack
    for (int i = 0; i < strlen(inputString); i++) {
        push(stack, top, inputString[i]);
    }

    // Check if characters match when popped
    for (int i = 0; i < strlen(inputString); i++) {
        if (inputString[i] != pop(stack, top)) {
            return -1; // Not a palindrome
        }
    }

    return 1; // Palindrome
}
