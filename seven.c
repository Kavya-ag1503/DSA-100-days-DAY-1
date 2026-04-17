#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int findLoopLength(struct Node* head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            int count = 1;
            struct Node* temp = slow->next;

            while(temp != slow) {
                count++;
                temp = temp->next;
            }

            return count;
        }
    }

    return 0;
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newnode;
    int n, value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp->next = head->next;

    int len = findLoopLength(head);
    if(len > 0)
        printf("%d", len);
    else
        printf("0");

    return 0;
}