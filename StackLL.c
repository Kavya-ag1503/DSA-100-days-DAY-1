#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Overflow\n");
        return;
    }

    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL) {
        printf("Underflow\n");
        return;
    }

    struct Node* temp = top;
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void display() {
    struct Node* temp = top;

    if (temp == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();
    
    display();

    return 0;
}