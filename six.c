#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int isCircular(struct Node* head)
{
    if(head == NULL) 
        return 0;

    struct Node* temp = head->next;

    while(temp != NULL && temp != head)
        temp = temp->next;

    if(temp == head)
        return 1; // circular
    else
        return 0; // not circular
}

int main()
{
    struct Node *head=NULL, *newnode, *temp;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d",&value);

        newnode->data=value;
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    // Make the list circular for testing
    temp->next = head; 

    if(isCircular(head))
        printf("The linked list is circular");
    else
        printf("The linked list is not circular");

    return 0;
}