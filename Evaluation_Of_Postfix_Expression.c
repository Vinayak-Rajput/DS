#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Stack and necessary variables for evaluation
int top = -1;  // Stack pointer
int operand1, operand2, result;  // Operands for operations
int stack[20];  // Stack for storing intermediate results
char postfixExpression[90], currentChar;

// Function to push an item onto the stack
void push(int item) {
    top = top + 1;  // Increment top to add new item
    stack[top] = item;
}

// Function to pop an item from the stack
int pop() {
    int item = stack[top];  // Get the item from top
    top = top - 1;  // Decrement top to remove the item
    return item;
}

int main() {
    printf("\nEnter a valid Postfix Expression: ");
    scanf("%s", postfixExpression);  // Read the postfix expression

    // Iterate over the expression character by character
    for (int i = 0; postfixExpression[i] != '\0'; i++) {
        currentChar = postfixExpression[i];  // Current character in expression

        // If the character is a digit, push it onto the stack
        if (isdigit(currentChar)) {
            push(currentChar - '0');  // Convert char to int (ASCII trick)
        }
        else {
            // Pop two operands from the stack for the operation
            operand2 = pop();
            operand1 = pop();

            // Perform the operation based on the current operator
            switch (currentChar) {
                case '+':
                    push(operand1 + operand2);  // Addition
                    break;
                
                case '-':
                    push(operand1 - operand2);  // Subtraction
                    break;
                
                case '*':
                    push(operand1 * operand2);  // Multiplication
                    break;
                
                case '/':
                    // Division: check for division by zero
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(0);  // Exit the program on error
                    } else {
                        push(operand1 / operand2);  // Division
                    }
                    break;
                
                case '%':
                    push(operand1 % operand2);  // Modulus
                    break;
                
                case '^':
                    push(pow(operand1, operand2));  // Exponentiation
                    break;
                
                default:
                    printf("Invalid Expression\n");  // Invalid operator
                    exit(0);  // Exit the program on invalid operator
            }
        }
    }

    // The final result is the last item in the stack
    result = pop();
    printf("\nResult = %d\n", result);  // Output the result

    return 0;
}
