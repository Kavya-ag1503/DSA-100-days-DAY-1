#include <stdio.h>

int main()
{
    int n;
    int queue[100];
    int front = 0;
    int rear = -1;
    int i;

    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        scanf("%d",&queue[++rear]);
    }

    for(i = front; i <= rear; i++)
    {
        printf("%d ",queue[i]);
    }

    return 0;
}