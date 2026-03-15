#include <stdio.h>

int main() {
    int n, m, i;
    
    scanf("%d", &n);
    int q[n];

    for(i = 0; i < n; i++)
        scanf("%d", &q[i]);

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

    for(i = 0; i < m; i++) {
        rear = (rear + 1) % n;
        q[rear] = q[front];
        front = (front + 1) % n;
    }

    int count = n;
    i = front;

    while(count--) {
        printf("%d ", q[i]);
        i = (i + 1) % n;
    }

    return 0;
}