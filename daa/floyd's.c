#include <stdio.h>
#include <limits.h>
#define V 4
int min(int a, int b) {
    return (a < b) ? a : b;
}
void floyd(int graph[V][V], int n) {
    int dist[V][V];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                   dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }   
            }
        }
    }
    printf("All-Pairs Shortest Paths Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
     int graph[V][V] = {{0, 3, 9999, 4},
    {8, 0, 2, 9999},
    {5, 9999, 0, 1},
    {2, 9999, 9999, 0}};
    floyd(graph, V);
    return 0;
}