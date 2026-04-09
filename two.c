#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int detectLoop(struct Node* head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return 1;
    }

    return 0;
}

int main()
{
    struct Node *head=NULL,*newnode,*temp;
    int n,i,value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
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

    temp->next = head->next;

    if(detectLoop(head))
        printf("Loop Detected");
    else
        printf("No Loop");

    return 0;
}