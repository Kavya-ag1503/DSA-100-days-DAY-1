#include <stdio.h>

int main()
{
    int n, i, j;
    int matrix[100][100];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j && matrix[i][j] != 1)
            {
                printf("Not an Identity Matrix");
                return 0;
            }

            if(i != j && matrix[i][j] != 0)
            {
                printf("Not an Identity Matrix");
                return 0;
            }
        }
    }

    printf("Identity Matrix");

    return 0;
}