#include <stdio.h>

int main()
{
    int n, i, j, count;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], counted[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        counted[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        if(counted[i] == 1)
            continue;

        count = 1;

        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                counted[j] = 1;
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
