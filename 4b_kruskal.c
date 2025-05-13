#include <stdio.h>
#include <stdlib.h>

// Structure to represent a weighted edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    int *parent, *rank;
    int n;
};

// Function to create a disjoint set for the nodes
struct DisjointSet* createSet(int n) {
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->n = n;
    set->parent = (int*)malloc(n * sizeof(int));
    set->rank = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        set->parent[i] = i;  // Initially, each node is its own parent
        set->rank[i] = 0;     // Initially, the rank is 0
    }

    return set;
}

// Function to find the representative of the set of an element
int find(struct DisjointSet* set, int i) {
    if (set->parent[i] != i)
        set->parent[i] = find(set, set->parent[i]);  // Path compression
    return set->parent[i];
}

// Function to perform the union of two sets
void unionSets(struct DisjointSet* set, int x, int y) {
    int xroot = find(set, x);
    int yroot = find(set, y);

    // Union by rank
    if (set->rank[xroot] < set->rank[yroot]) {
        set->parent[xroot] = yroot;
    } else if (set->rank[xroot] > set->rank[yroot]) {
        set->parent[yroot] = xroot;
    } else {
        set->parent[yroot] = xroot;
        set->rank[xroot]++;
    }
}

// Function to compare edges by weight (for sorting edges)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskal(struct Edge edges[], int E, int V) {
    struct DisjointSet* set = createSet(V);

    // Sort all edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    printf("Edges in the Minimum Spanning Tree (MST):\n");

    int mstWeight = 0;
    int i, u, v, setU, setV;  // Declare all variables outside of the loop
    
    // Loop through all edges and apply Kruskal's algorithm
    for (i = 0; i < E; i++) {
        u = edges[i].src;
        v = edges[i].dest;

        // Find the sets of the vertices u and v
        setU = find(set, u);
        setV = find(set, v);

        // If including this edge does not form a cycle, include it in the result
        if (setU != setV) {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(set, setU, setV);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

// Driver function
int main() {
    int V = 4; // Number of vertices in the graph
    int E = 5; // Number of edges in the graph

    // Create an array of edges
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Run Kruskal's algorithm
    kruskal(edges, E, V);

    return 0;
}
