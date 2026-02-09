# Q4: Doubly Linked List (Insert/Delete After a Node)

## 1. Introduction
The program shows how to create a **doubly linked list** using C programming.  
The program includes functions which enable users to:
- Create nodes
- Insert a new node immediately after a specified node
- Delete a node that comes after a given node

The list displays its content from the start to the end so viewers can see all changes which occur between different operations. 

## 2. Data Structure Used
Doubly Linked List Node

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

- `data` holds the value which belongs to the current node
- `prev` establishes a connection to the previous node within the sequence
- `next` establishes a connection to the subsequent node within the sequence

The implementation of a doubly linked list enables users to navigate through both directions while performing insertions and deletions at any position with greater ease. 

## 3. Purpose
- The program shows how to add and remove nodes **after a specific node**.  
- The program needs to keep accurate `prev` and `next` connections throughout every action.  
- The program contains different functions which handle creation of nodes and insertion and deletion processes and list display.


## 4. Functions Implemented

a. struct Node* newNode(int val)
- The function creates a new node which contains the specified value.  
- The system sets both `prev` and `next` to NULL at the beginning. 

b. struct Node* makeList(int vals[], int size)
- The function creates an initial doubly linked list from an array of values.  
- The system establishes correct node connections which enable the doubly linked structure to function properly. 

c. void insAfter(struct Node* node, int val)
- The function inserts a new node directly **after** the specified node.  
- The system changes `prev` and `next` pointers to ensure correct list connections between nodes. 

d. void delAfter(struct Node* node)
- The function eliminates the node which exists directly **after** the specified node.  
- The system updates `prev` and `next` pointers to ensure the list remains unbroken.  
- The system releases all memory which the deleted node occupied. 

e. void showList(struct Node* head)
- The function displays the list through the forward direction.  
- The function shows each node's value with `<->` used to mark connections between nodes.

## 5. Main Method Organization
- The program defines an initial array which contains the values 45 and 50 and 65 and 70 and 90.  
- The program establishes the linked list through the operation of `makeList()`.  
- The initial list is displayed using `showList()`.  
- The program inserts a node with value 60 right after the node which has value 50.  
- The program removes the node which contains the value 70.  
- The program shows the list after each operation to display how the list changes because of the insertion and deletion operations. 

## 6. Sample Output

Initial List:
List: 45 <-> 50 <-> 65 <-> 70 <-> 90 <-> NULL

After inserting 60 after 50:
List: 45 <-> 50 <-> 60 <-> 65 <-> 70 <-> 90 <-> NULL

After deleting 70:
List: 45 <-> 50 <-> 60 <-> 65 <-> 90 <-> NULL