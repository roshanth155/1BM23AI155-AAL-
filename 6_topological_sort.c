#include <stdio.h>
#include <stdlib.h>
#define MAX 26

int adj[MAX][MAX], visited[MAX], stack[MAX], top = -1;

void dfs(int v, int n) {
    visited[v] = 1;
    int i;  // Declare the loop variable outside the for loop
    for (i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
    stack[++top] = v;
}

void topologicalSort(int n) {
    int i;  // Declare the loop variable outside the for loop
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }
    while (top >= 0) {
        printf("%c ", stack[top--] + 'A');  // Convert to alphabet
    }
    printf("\n");
}

int main() {
    int n = 6;

    // Adjacency matrix representation for nodes A to F
    adj[5][2] = adj[5][0] = adj[4][0] = adj[4][1] = adj[2][3] = adj[3][1] = 1;

    topologicalSort(n);
    return 0;
}
