#include <stdio.h>
#include <limits.h>

#define V 4

int tsp(int graph[V][V], int visited[], int pos, int count, int cost, int start, int min_cost) {
    if (count == V && graph[pos][start]) {
        return cost + graph[pos][start] < min_cost ? cost + graph[pos][start] : min_cost;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            min_cost = tsp(graph, visited, i, count + 1, cost + graph[pos][i], start, min_cost);
            visited[i] = 0;
        }
    }
    return min_cost;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int visited[V] = {0};
    visited[0] = 1;

    printf("Minimum cost: %d\n", tsp(graph, visited, 0, 1, 0, 0, INT_MAX));
    return 0;
}
