#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* insertAfterNode(struct Node* head, int prevValue, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != prevValue) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", prevValue);
        return head;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Original List: ");
    printList(head);

    head = insertAtBeginning(head, 5);
    printf("After inserting 5 at beginning: ");
    printList(head);

    head = insertAtEnd(head, 40);
    printf("After inserting 40 at end: ");
    printList(head);

    head = insertAfterNode(head, 10, 15);
    printf("After inserting 15 after 10: ");
    printList(head);

    return 0;
}