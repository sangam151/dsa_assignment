# Q1: Balanced Parentheses Checker (Using Stack)

## 1. Introduction
This program checks whether a given mathematical expression has balanced parentheses.
A stack is used to keep track of opening brackets and match them correctly with closing brackets while scanning the expression.

## 2. Data Structure Used
The program employs a stack data structure for its operations.

The Stack structure defines a storage system which contains an integer top value and a character array elements that has a maximum length of MAX.

The top variable maintains the index position of the currently highest item present in the stack.
The element storage system uses elements[MAX to contain all types of opening brackets which include character symbols like ( and [ and {.

The stack structure operates under the LIFO system which enables it to effectively handle parenthesis matching tasks.

## 3. Objective
- To verify that every opening bracket has a corresponding closing bracket.
- The system verifies that all brackets close according to their required sequence.
- The system works with all three types of brackets which include parentheses, square brackets, and curly braces.
- The system enables modular development through the implementation of distinct stack operation functions and matching logic functions.

## 4. Functions Used
a. push(Stack* s, char ch)
The system adds an opening bracket to the stack.
The system checks for stack overflow.
The system updates the top value and stores the character.

b. pop(Stack* s)
The function removes the topmost stack element and returns it to the caller.
The system checks for stack underflow condition.
The function returns \0 when the stack does not contain any elements.

c. isPair(char open, char close)
The function checks if the two provided brackets form a valid opening and closing bracket combination.
The function returns 1 when the brackets match otherwise it returns 0.

d. checkBalanced(char* expr)
The function serves as the primary method to validate balanced parentheses.
The system scans the expression character by character:
- The system pushes opening brackets onto the stack.
- The system pops closing brackets and checks for matching pairs.
The system stops functioning when it detects any mismatch or additional closing bracket.
The function returns 1 when all brackets match and the stack shows empty status at the procedure's conclusion.

## 5. Program Flow in main()
The system establishes a collection of test expressions.
The system operates checkBalanced() on all the expressions.
The system displays Balanced or Unbalanced status for each expression.
The demonstration proves that the stack-based method produces accurate results.

## 6. Sample Output
Parentheses Balance Checker

Expression: a+(b-c)*(d
Result: Unbalanced

Expression: m+[a-b*(c+d*{m)]
Result: Unbalanced

Expression: a+(b-c)
Result: Balanced