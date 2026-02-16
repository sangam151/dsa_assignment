# Qn 2: Infix to Postfix Conversion and Evaluation

## 1. Overview
This program converts mathematical expressions from infix notation (e.g., 2+3) to postfix notation (e.g., 23+) and evaluates the postfix expression using stacks.

The program uses a character stack for conversion and an integer stack for evaluation. It also follows operator precedence rules and supports the exponent (^) operator.

## 2. Data Structures Used:

### CharStack Structure 

typedef struct {
    int top;
    char items[SIZE];
} CharStack;
- Purpose: Used during infix to postfix conversion to temporarily store operators and parentheses.

### Integer Stack ( Used in Evaluation)
int stack[SIZE];
int top;
- Purpose: Used during postfix evaluation to store numeric operands and intermediate results.

-  The two different Stacks are CharStack: Used to store operators during conversion . Integer Stack: Used to store numbers during evaluation.

## 3. Functions Implemented :

### a. void initCharStack(CharStack* st)
- Purpose: Initializes the stack.

### b. void pushChar(CharStack* st, char ch)
-Purpose: Pushes a character onto the stack.

### c. char popChar(CharStack* st)
- Purpose: Removes and returns the top character.

### d. char peekChar(CharStack* st)
- Purpose: Returns the top element without removing it.

### e. int isOperator(char ch)
- Purpose: Checks if character is an operator.

### f. int precedence(char op)
- Purpose: Returns operator precedence. ( In precedence table, higher precedence means higher priority).

### g. int isOperand(char ch)
- Purpose: Checks if character is operand (digit or letter).
 
### h. void convertInfixToPostfix(char* infix, char* postfix)
- Purpose: Converts infix expression into postfix expression.
 
 #### Algorithm:
- Scan infix expression from left to right
- If operand, Add to postfix
- If '('
 Push to stack
 -If ')'
Pop operators until '(' is found
- If operator
Pop operators with higher or equal precedence
Push current operator
- Pop remaining operators
- Add null character to postfix

### i. int evaluatePostfix(char* postfix)
- Purpose: Evaluates postfix expression and returns result.
 #### Algorithm:
- Scan postfix expression from left to right
- If operand,  Convert to integer and push into stack
- If operator
 Pop two operands
Perform operation
Push result back
- Final value in stack is result

## 4. Main Method Organization :
- Declares two character arrays:
-infix[SIZE] to store the input infix expression
- postfix[SIZE] to store the converted postfix expression
- Displays a message prompting the user to enter an infix expression
- Reads the infix expression from the user using scanf()
- Calls the function convertInfixToPostfix(infix, postfix)
- This converts the infix expression into postfix form
- Stores the result in the postfix array
- Prints the postfix expression using printf()
- Calls the function evaluatePostfix(postfix)
- This evaluates the postfix expression
- Stores the result in an integer variable result
- Displays the final evaluated result using printf()
- Returns 0 to indicate successful program execution

## 5. Sample Output :
Enter infix expression: (5+2)*3
Postfix: 52+3*
Result: 21