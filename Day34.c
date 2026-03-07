#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main()
{
    char postfix[100];
    int i = 0;

    fgets(postfix, 100, stdin);

    while(postfix[i] != '\0')
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
        {
            int b = pop();
            int a = pop();
            int result;

            if(postfix[i]=='+')
                result = a + b;
            else if(postfix[i]=='-')
                result = a - b;
            else if(postfix[i]=='*')
                result = a * b;
            else
                result = a / b;

            push(result);
        }

        i++;
    }

    printf("%d", pop());

    return 0;
}