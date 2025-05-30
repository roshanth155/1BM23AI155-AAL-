#include <stdio.h>
#define nV 4
#define INF 999

void printMatrix(int matrix[][nV]);

void floydWarshall(int graph[][nV]) {
    int matrix[nV][nV];  // Declare matrix outside the loop
    int i, j, k;         // Declare i, j, k outside the loops

    // Copy the graph to the matrix
    for (i = 0; i < nV; i++) {
        for (j = 0; j < nV; j++) {
            matrix[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (k = 0; k < nV; k++) {
        for (i = 0; i < nV; i++) {
            for (j = 0; j < nV; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    // Print the resulting matrix
    printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
    int i, j;  // Declare variables outside of the loop (for C89 compatibility)

    for (i = 0; i < nV; i++) {
        for (j = 0; j < nV; j++) {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[nV][nV] = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    floydWarshall(graph);
}
