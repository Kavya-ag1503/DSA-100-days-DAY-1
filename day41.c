#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue function
void enqueue(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue function
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'e') {  // enqueue
            scanf("%d", &value);
            enqueue(value);
        } else {             // dequeue
            dequeue();
        }
    }

    return 0;
}