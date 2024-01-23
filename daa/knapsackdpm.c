#include <stdio.h>
int knapsackDP(int weights[], int profits[], int capacity, int n) {
    int K[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            K[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] > j) {
                K[i][j] = K[i - 1][j];
            } else {
                int profitWithItem = profits[i - 1] + K[i - 1][j - weights[i - 1]];
                int profitWithoutItem = K[i - 1][j];
                K[i][j] = profitWithItem > profitWithoutItem ? profitWithItem :
                profitWithoutItem;
            }
        }
    }
    return K[n][capacity];
}
int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int weights[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the weight for item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }
    int profits[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the profit for item %d: ", i + 1);
        scanf("%d", &profits[i]);
    }
    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);
    int maxProfit = knapsackDP(weights, profits, capacity, n);
    printf("Maximum profit: %d\n", maxProfit);
    return 0;
}