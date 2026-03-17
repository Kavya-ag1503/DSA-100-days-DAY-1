#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = arr[0] + arr[1];
    int min_sum;

    if(sum < 0)
        min_sum = -sum;
    else
        min_sum = sum;

    int a = arr[0], b = arr[1];

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {

            sum = arr[i] + arr[j];

            int temp;
            if(sum < 0)
                temp = -sum;
            else
                temp = sum;

            if(temp < min_sum) {
                min_sum = temp;
                a = arr[i];
                b = arr[j];
            }
        }
    }

    printf("%d %d", a, b);

    return 0;
}