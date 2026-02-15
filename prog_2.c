#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 100  // Max size for stack and expression

// Stack structure for characters 
typedef struct {
    int top;
    char items[SIZE];
} CharStack;

// Initialize the stack
void initCharStack(CharStack* st) {
    st->top = -1;
}

// Push a character onto the stack
void pushChar(CharStack* st, char ch) {
    if(st->top == SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    st->items[++st->top] = ch;
}

// Pop a character from the stack
char popChar(CharStack* st) {
    if(st->top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return st->items[st->top--];
}

// Peek top character without removing
char peekChar(CharStack* st) {
    if(st->top == -1) return '\0';
    return st->items[st->top];
}

// Utility functions 

// Check if a character is an operator
int isOperator(char ch) {
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

// Operator precedence
int precedence(char op) {
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

// Check if character is operand (digit/letter)
int isOperand(char ch) {
    return isalnum(ch);
}

//  Infix to Postfix Conversion
void convertInfixToPostfix(char* infix, char* postfix) {
    CharStack st;
    initCharStack(&st);

    int i=0, j=0;
    while(infix[i]) {
        char ch = infix[i];
        if(isOperand(ch)) {
            postfix[j++] = ch;  // Add operand directly to output
        }
        else if(ch == '(') {
            pushChar(&st, ch);  // Push '(' to stack
        }
        else if(ch == ')') {
            // Pop until '('
            while(peekChar(&st) != '(' && st.top != -1)
                postfix[j++] = popChar(&st);
            popChar(&st); // Remove '('
        }
        else if(isOperator(ch)) {
            // Pop operators with higher or equal precedence
            while(st.top != -1 && 
                  ((precedence(peekChar(&st)) > precedence(ch)) || 
                  (precedence(peekChar(&st)) == precedence(ch) && ch != '^'))) {
                postfix[j++] = popChar(&st);
            }
            pushChar(&st, ch);
        }
        i++;
    }

    // Pop remaining operators
    while(st.top != -1)
        postfix[j++] = popChar(&st);

    postfix[j] = '\0';
}

// Postfix Evaluation 
int evaluatePostfix(char* postfix) {
    int stack[SIZE];
    int top = -1;

    for(int i=0; postfix[i]; i++) {
        char ch = postfix[i];
        if(isOperand(ch)) {
            stack[++top] = ch - '0';  // Convert char to int
        }
        else if(isOperator(ch)) {
            int b = stack[top--];
            int a = stack[top--];
            int res;
            switch(ch) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': res = (int)pow(a, b); break;
            }
            stack[++top] = res;
        }
    }
    return stack[top];
}

// Main 
int main() {
    char infix[SIZE], postfix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    convertInfixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}