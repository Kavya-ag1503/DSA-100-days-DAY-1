#include <stdio.h>

int main() {
    int n, target;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    // Input array
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Input target
    printf("Enter target: ");
    scanf("%d", &target);

    // Find two sum
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("Output: [%d, %d]\n", i, j);
                return 0;
            }
        }
    }

    printf("No two sum solution found.\n");
    return 0;
}
