#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list in reverse order using a stack
void printReverse(struct Node* head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    struct Node** stack = NULL;
    int size = 0;

    // Push elements onto the stack
    while (current != NULL) {
        stack = realloc(stack, (size + 1) * sizeof(struct Node*));
        stack[size++] = current;
        current = current->next;
    }

    int tmp_size = 0;

    // Pop elements off the stack and print them
    while (tmp_size < size) {
        printf("%d ", stack[tmp_size]->data);
        tmp_size++;
    }

    // Free the dynamically allocated stack
    free(stack);
}

// Function to free the allocated memory for the linked list
void freeList(struct Node* head) {
    struct Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 5);
    insertNode(&head, 2);
    insertNode(&head, 8);
    insertNode(&head, 1);
    insertNode(&head, 7);

    printf("Original linked list: ");
    // Print the linked list in reverse order
    printReverse(head);
    printf("\n");

    // Free allocated memory
    freeList(head);

    return 0;
}
