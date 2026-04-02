#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* head = NULL;

// Insert at head (O(1))
void insert(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = head;
    head = newNode;
}

// Delete highest priority (O(n))
int delete_max() {
    if (head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    Node *temp = head, *maxNode = head;
    Node *prev = NULL, *maxPrev = NULL;

    while (temp != NULL) {
        if (temp->priority > maxNode->priority) {
            maxNode = temp;
            maxPrev = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    if (maxPrev == NULL)
        head = head->next;
    else
        maxPrev->next = maxNode->next;

    int value = maxNode->data;
    free(maxNode);
    return value;
}

// Peek max priority
void peek() {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = head;
    Node* maxNode = head;

    while (temp != NULL) {
        if (temp->priority > maxNode->priority)
            maxNode = temp;
        temp = temp->next;
    }

    printf("Highest Priority: %d (Priority: %d)\n",
           maxNode->data, maxNode->priority);
}

// Display
void display() {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("Data: %d | Priority: %d\n",
               temp->data, temp->priority);
        temp = temp->next;
    }
}

// Main function
int main() {
    insert(10, 2);
    insert(20, 5);
    insert(30, 1);

    display();

    printf("\nDeleted: %d\n", delete_max());

    peek();

    display();

    return 0;
}
