#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

// Global variables
char stack[SIZE], infixExpression[SIZE];
char symbol, poppedElement;
int top = -1;

// Function to push an element onto the stack
void push(char item) {
    if (top >= SIZE - 1) {
        printf("Error: Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Error: Stack Underflow\n");
        exit(0);
    } else {
        return stack[top--];
    }
}

// Function to determine the precedence of operators
int priority(char operator) {
    if (operator == '(') {
        return 0;
    } else if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '^' || operator == '$') {
        return 3; // '^' or '$' is assumed to represent exponentiation
    } else {
        return 0;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char infixExpression[]) {
    printf("Postfix Expression: ");
    for (int i = 0; infixExpression[i] != '\0'; i++) {
        symbol = infixExpression[i];

        if (isalnum(symbol)) { // If the symbol is an operand (alphanumeric)
            printf("%c", symbol);
        } else if (symbol == '(') { // If the symbol is an opening parenthesis
            push(symbol);
        } else if (symbol == ')') { // If the symbol is a closing parenthesis
            while ((poppedElement = pop()) != '(') {
                printf("%c", poppedElement);
            }
        } else { // If the symbol is an operator
            while (priority(stack[top]) >= priority(symbol)) {
                printf("%c", pop());
            }
            push(symbol);
        }
    }

    // Pop remaining operators from the stack
    while (top > -1) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    printf("ASSUMPTION: The infix expression contains single-letter variables and single-digit constants only.\n");
    printf("\nEnter the infix expression: ");
    scanf("%s", infixExpression);
    printf("\n");

    // Add an initial '(' to the stack and append ')' to the infix expression
    push('(');
    strcat(infixExpression, ")");

    // Convert the infix expression to postfix
    infixToPostfix(infixExpression);

    return 0;
}
