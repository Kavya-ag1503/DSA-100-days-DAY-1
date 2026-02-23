#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *last = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }
    return head;
}

struct Node* mergeList(struct Node* list1, struct Node* list2)
{
    struct Node *head = NULL, *last = NULL, *newNode;

    while(list1 != NULL && list2 != NULL)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;

        if(list1->data < list2->data)
        {
            newNode->data = list1->data;
            list1 = list1->next;
        }
        else
        {
            newNode->data = list2->data;
            list2 = list2->next;
        }

        if(head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }

    while(list1 != NULL)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = list1->data;
        newNode->next = NULL;

        last->next = newNode;
        last = newNode;
        list1 = list1->next;
    }

    while(list2 != NULL)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = list2->data;
        newNode->next = NULL;

        last->next = newNode;
        last = newNode;
        list2 = list2->next;
    }

    return head;
}

void display(struct Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    struct Node* merged = mergeList(list1, list2);

    display(merged);

    return 0;
}