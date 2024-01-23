#include <stdio.h>
#include <limits.h>
#define INF 99999
int n;
int graph[10][10];
int min(int a, int b) {
    return (a < b) ? a : b;
}
int dp[1 << 10][10];
int tsp(int visited, int currentCity) {
    if (visited == (1 << n) - 1) {
        return graph[currentCity][0];
    }
    if (dp[visited][currentCity] != -1) {
        return dp[visited][currentCity];
    }
    int minDistance = INF;
    for (int nextCity = 0; nextCity < n; nextCity++) {
        if ((visited & (1 << nextCity)) == 0) {
            int tempDistance = graph[currentCity][nextCity] + tsp(visited | (1<< nextCity), nextCity);
            minDistance = min(minDistance, tempDistance);
        }
    }
    dp[visited][currentCity] = minDistance;
    return minDistance;
}
int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter distance between city %d and city %d: ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    int minDistance = tsp(1, 0);
    printf("Minimum distance TSP tour: %d\n", minDistance);
    return 0;
}