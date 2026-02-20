#include <stdio.h>

int main()
{
    int m, n, i, j, sum = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int arr[m][n];

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
            {
                sum = sum + arr[i][j];
            }
        }
    }

    printf("Sum of primary diagonal = %d", sum);

    return 0;
}
