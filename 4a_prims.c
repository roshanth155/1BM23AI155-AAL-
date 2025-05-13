#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;

    int v;  // Declare v outside of the loop
    for (v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Prim's MST algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick the minimum weight edge
    int mstSet[V];  // Boolean array to represent vertices not yet included in MST

    // Initialize all keys as INFINITE
    int i;  // Declare i outside of the loop
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start from the first vertex
    key[0] = 0;  // Make key[0] as 0 so that this vertex is picked first
    parent[0] = -1;  // The first node is the root of the MST

    // The MST will have V vertices
    int count;  // Declare count outside of the loop
    for (count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        
        // Add the picked vertex to the MST set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        int v;
        for (v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false if v is not yet included in MST
            // Update the key only if the current weight is smaller than the previous key value
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    // Example graph with 5 vertices
    // The adjacency matrix represents the weighted graph
    int graph[V][V] = { {0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0} };

    primMST(graph);  // Call Prim's algorithm
    return 0;
}
