/*
Program to demonstrate a doubly linked list in C.
Includes functions to create nodes, insert after a node, and delete after a node.
Initial nodes are created from an array with unique values.
*/

#include <stdio.h>
#include <stdlib.h>

/* Structure for a doubly linked list node */
struct ListEntry {
    int information;
    struct ListEntry* preceding;
    struct ListEntry* succeeding;
};

/* Function to create a new node */
struct ListEntry* createEntry(int value) {
    struct ListEntry* entry = (struct ListEntry*)malloc(sizeof(struct ListEntry));
    entry->information = value;
    entry->preceding = NULL;
    entry->succeeding = NULL;
    return entry;
}

/* Function to create a linked list from an array */
struct ListEntry* buildList(int elements[], int count) {
    if (count == 0) return NULL;

    struct ListEntry* start = createEntry(elements[0]);
    struct ListEntry* current = start;

    for (int j = 1; j < count; j++) {
        struct ListEntry* temporary = createEntry(elements[j]);
        current->succeeding = temporary;
        temporary->preceding = current;
        current = temporary;
    }

    return start;
}

/* Function to insert a node after a given node */
void insertFollowing(struct ListEntry* position, int value) {
    if (position == NULL) {
        printf("Target node cannot be NULL.\n");
        return;
    }

    struct ListEntry* fresh = createEntry(value);
    fresh->succeeding = position->succeeding;
    fresh->preceding = position;

    if (position->succeeding != NULL) {
        position->succeeding->preceding = fresh;
    }

    position->succeeding = fresh;
}

/* Function to delete a node after a given node */
void removeFollowing(struct ListEntry* position) {
    if (position == NULL || position->succeeding == NULL) {
        printf("No node exists after the specified node for deletion.\n");
        return;
    }

    struct ListEntry* target = position->succeeding;
    position->succeeding = target->succeeding;

    if (target->succeeding != NULL) {
        target->succeeding->preceding = position;
    }

    free(target);
}

/* Function to display the list in forward direction */
void printList(struct ListEntry* start) {
    struct ListEntry* pointer = start;
    printf("Doubly Linked List: ");
    while (pointer != NULL) {
        printf("%d <-> ", pointer->information);
        pointer = pointer->succeeding;
    }
    printf("NULL\n");
}

/* Main function to demonstrate list operations */
int main() {
    // Initial values for the linked list
    int items[] = {45, 50, 65, 70, 90};
    int size = sizeof(items) / sizeof(items[0]);

    // Create the linked list from array
    struct ListEntry* beginning = buildList(items, size);

    printf("Original List:\n");
    printList(beginning);

    // Insert 60 after second node (After 50)
    insertFollowing(beginning->succeeding, 60);
    printf("\nAfter adding 60 following 50:\n");
    printList(beginning);

    // Delete node after fourth node (Removing 70)
    removeFollowing(beginning->succeeding->succeeding->succeeding);
    printf("\nAfter removing 70:\n");
    printList(beginning);

    return 0;
}