/*
Program to demonstrate reverse traversal of a singly linked list.
Uses recursion to print the list in reverse order.
*/

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct ListElement {
    int value;
    struct ListElement* following;
};

/* Create a new node */
struct ListElement* generateNode(int item) {
    struct ListElement* freshNode = (struct ListElement*)malloc(sizeof(struct ListElement));
    freshNode->value = item;
    freshNode->following = NULL;
    return freshNode;
}

/* Display list in normal order */
void showList(struct ListElement* start) {
    struct ListElement* current = start;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->following;
    }
    printf("NULL\n");
}

/* Reverse traversal using recursion */
void backwardDisplay(struct ListElement* start) {
    if (start == NULL) return;
    backwardDisplay(start->following);
    printf("%d -> ", start->value);
}

/* Main function to demonstrate reverse traversal */
int main() {
    // Manually create nodes
    struct ListElement* first = generateNode(10);
    first->following = generateNode(20);
    first->following->following = generateNode(30);
    first->following->following->following = generateNode(40);

    printf("Normal Traversal:\n");
    showList(first);

    printf("\nReverse Traversal:\n");
    backwardDisplay(first);
    printf("NULL\n");

    return 0;
}