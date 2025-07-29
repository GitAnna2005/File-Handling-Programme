 #include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void traverse(struct Node* head);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAfter(struct Node* prev_node, int data);
void deleteFromBeginning(struct Node** head);
void deleteFromEnd(struct Node** head);
void deleteByValue(struct Node** head, int key);

// Traverse the list
void traverse(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}

// Insert after a given node
void insertAfter(struct Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete from beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Delete from end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* second_last = *head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    free(second_last->next);
    second_last->next = NULL;
}

// Delete by value
void deleteByValue(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in list\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Main function
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAfter(head->next, 15); // After 10

    traverse(head);

    deleteFromBeginning(&head);
    traverse(head);

    deleteFromEnd(&head);
    traverse(head);

    deleteByValue(&head, 15);
    traverse(head);

    return 0;
}
