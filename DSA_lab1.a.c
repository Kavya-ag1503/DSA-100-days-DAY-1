#include <stdio.h>
#include <time.h>

void constant() {
    printf("\nO(1): Hello World\n");
}

void logFun(int n) {
    printf("\nO(log n): ");
    while(n > 1) {
        printf("%d ", n);
        n = n / 2;
    }
    printf("\n");
}

void linear(int n) {
    int i;
    printf("\nO(n): ");
    for(i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void quadratic(int n) {
    int i, j;
    printf("\nO(n^2):\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    clock_t start, end;

    printf("Enter a number: ");
    scanf("%d", &n);

    start = clock();   

    constant();       
    logFun(n);        
    linear(n);        
    quadratic(n);     

    end = clock();    

    printf("\nTime taken: %lf seconds",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
