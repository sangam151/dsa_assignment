# Q3: Reverse Traversal of a Linked List

## 1. Introduction
The program shows how to traverse a **singly linked list in reverse order** without making any permanent changes to the list structure.
The program uses **recursion** to display the list elements starting from the last node down to the first node.

The program focuses on three main objectives:
- The student needs to gain knowledge about the linked list structure.
- The student needs to learn how to use recursion for executing reverse list traversal.
- The student needs to demonstrate traversal by using a basic linked list implementation found in `main()`.

## 2. Data Structure Used
Singly Linked List Node

struct Node {
    int data;
    struct Node* next;
};

- The field `data` contains the node's stored value.
- The field `next` provides the reference to the subsequent node within the list.

This structure allows a user to construct a linked list that can expand to any desired size.

## 3. Objective
- The program needs to display the linked list elements in reverse order without making any changes to the list structure.
- The program needs to use recursion for list reversal instead of performing physical list reversal operations.
- The project demonstrates modular programming through separate functions for creating nodes, showing nodes, and traversing linked lists.

## 4. Functions Implemented

a. struct Node* createNode(int value)
- The process creates a new node by allocating memory space.
- The process assigns the data field value to match the value parameter.
- The process establishes the next pointer to point towards NULL.
- The process delivers a pointer which points to the newly established node.

b. void display(struct Node* head)
- The function starts at the head position to traverse the complete linked list.
- The function displays every node's data in sequence from the start of the list.
- The function finishes output by using NULL which shows the list termination point.

c. void reverseTraversal(struct Node* head)
- The function uses recursion to display the linked list elements in reverse sequence.
- The base case of recursion defines its stopping point when head equals NULL.
- The recursion process begins to execute its next step through head->next.
- The current node data gets printed when the recursion function starts its return process.

### Explanation of Recursive Calls
- Initial call: `reverseTraversal(head)` → head = 10  
- The function now calls `reverseTraversal(head->next)` with head equal to 20.  
- The next function call occurs through head equal to 20 which calls head equal to 30.  
- The next function call occurs through head equal to 30 which calls head equal to 40.  
- The next function call occurs through head equal to 40 which calls head equal to NULL.  
- The base condition reached its limit when the process started returning through recursion.  
- The process outputs during the return phase output values of 40 followed by 30 and then 20 and finally 10.

## 5. Program Flow in main()
- The system uses `createNode()` to create each node.
- The process establishes connections between nodes through the `next` pointers to create a singly linked list.
- The program showcases:
  - Normal traversal using `display()`
  - Reverse traversal using `reverseTraversal()`

## 6. Sample Output

The normal traversal shows the sequence of 10 which leads to 20 followed by 30 and then 40 and finally ends with NULL.

The reverse traversal shows the sequence of 40 which leads to 30 followed by 20 and then 10 and finally ends with NULL.