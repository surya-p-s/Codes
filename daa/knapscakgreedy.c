#include <stdio.h>
typedef struct Item {
    float profit;
    float weight;
    float profitToWeightRatio;
}
Item;
void sortItemsByProfitToWeightRatio (Item items [], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            float ratio1 = items[j]. profit / items[j]. weight;
            float ratio2 = items [j + 1]. profit / items [j + 1]. weight;
            if (ratio1 < ratio2) {
                Item temp = items[j];
                items[j] = items [j + 1];
                items [j + 1] = temp;
            }
        }
    }
}
void knapsackGreedy (Item items [], int n, float capacity) {
    float totalProfit = 0.0;
    float remainingCapacity = capacity;
    float fraction = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i]. weight <= remainingCapacity) {
            totalProfit += items[i]. profit;
            remainingCapacity -= items[i]. weight;
        } else {
            fraction = remainingCapacity / items[i]. weight;
            totalProfit += fraction * items[i]. profit;
            remainingCapacity = 0.0;
            break;
        }
    }
    printf ("Maximum profit: %f\n", totalProfit);
}
int main () {
    int n;
    printf ("Enter the number of items: ");
    scanf ("%d", &n);
    Item items[n];
    for (int i = 0; i < n; i++) {
        printf ("Enter profit and weight for item %d: ", i + 1);
        scan ("%f %f", &items[i].profit, &items[i].weight);
        items[i]. profitToWeightRatio = items[i]. profit / items[i]. weight;
    }  
    sortItemsByProfitToWeightRatio (items, n);
    float capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%f", &capacity);
    knapsackGreedy(items, n, capacity);
    return 0;
}