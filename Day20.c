#include <stdio.h>

int main()
{
    int n,i,j;
    int arr[100];
    int sum,count=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<n;i++)
    {
        sum=0;

        for(j=i;j<n;j++)
        {
            sum=sum+arr[j];

            if(sum==0)
                count++;
        }
    }

    printf("%d",count);

    return 0;
}