#include <stdio.h>

int maxProfit(int prices[], int n) {
    int minPrice = prices[0];   // best price to buy
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {
        // If today's price is cheaper, update minPrice
        if(prices[i] < minPrice) {
            minPrice = prices[i];
        }
        // Otherwise calculate profit
        else if(prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

int main() {
    int n;
    scanf("%d", &n);

    int prices[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int result = maxProfit(prices, n);
    printf("%d", result);

    return 0;
}
