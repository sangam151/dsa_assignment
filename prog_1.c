/* 
Program to check if a mathematical expression has balanced parentheses.
Uses a stack to keep track of opening brackets and matches them with closing brackets.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 100  // maximum size of stack

// Define stack structure
typedef struct Container {
    int pointer;
    char items[LIMIT];
} Container;

// Function to add a character to the stack
void addItem(Container* c, char symbol) {
    if (c->pointer == LIMIT - 1) {
        // Stack is full, cannot push more
        return;
    }
    c->items[++(c->pointer)] = symbol;  // increase pointer, then store the character
}

// Function to remove a character from the stack
char removeItem(Container* c) {
    if (c->pointer == -1) {
        // Stack is empty
        return '\0'; // return null character
    }
    return c->items[(c->pointer)--]; // return top element, then decrease pointer
}

// Function to check if opening and closing brackets match
int checkMatch(char first, char second) {
    if (first == '(' && second == ')') return 1;
    if (first == '[' && second == ']') return 1;
    if (first == '{' && second == '}') return 1;
    return 0;
}

// Function to check if expression has balanced brackets
int verifyExpression(char* input) {
    Container store;
    store.pointer = -1;  // initialize empty stack
    int size = strlen(input);

    for (int idx = 0; idx < size; idx++) {
        char current = input[idx];

        // If it is an opening bracket, push to stack
        if (current == '(' || current == '[' || current == '{') {
            addItem(&store, current);
        }

        // If it is a closing bracket
        else if (current == ')' || current == ']' || current == '}') {
            if (store.pointer == -1) {
                // Stack empty but found a closing bracket → unbalanced
                return 0;
            }

            if (!checkMatch(removeItem(&store), current)) {
                // Top of stack does not match closing bracket → unbalanced
                return 0;
            }
        }
    }

    // Expression is balanced only if stack is empty at the end
    return (store.pointer == -1);
}

int main() {
    // Test expressions
    char* testCases[] = {
        "a+(b-c)*(d",       // missing closing bracket
        "m+[a-b*(c+d*{m)]", // mismatched brackets
        "a+(b-c)"           // balanced
    };

    printf("Parentheses Balance Checker\n\n");

    for (int j = 0; j < 3; j++) {
        printf("Expression: %s\n", testCases[j]);
        if (verifyExpression(testCases[j])) {
            printf("Balanced\n\n");
        } else {
            printf("Unbalanced\n\n");
        }
    }

    return 0;
}