#include <stdio.h>
#include <stdlib.h>

typedef struct { int u, v, w; } Edge;
typedef struct { int p, r; } Subset;

int cmp(const void* a, const void* b) { return ((Edge*)a)->w - ((Edge*)b)->w; }
int find(Subset* s, int i) { return s[i].p == i ? i : (s[i].p = find(s, s[i].p)); }
void unite(Subset* s, int x, int y) {
    x = find(s, x), y = find(s, y);
    if (s[x].r < s[y].r) s[x].p = y;
    else s[y].p = x, s[x].r += (s[x].r == s[y].r);
}

void kruskal(Edge* e, int V, int E) {
    Edge r[V]; Subset s[V];
    qsort(e, E, sizeof(Edge), cmp);
    for (int i = 0; i < V; i++) s[i] = (Subset){i, 0};
    int total_weight = 0;
    for (int i = 0, j = 0; j < V - 1 && i < E; i++)
        if (find(s, e[i].u) != find(s, e[i].v))
            r[j] = e[i], unite(s, e[i].u, e[i].v), total_weight += e[i].w, j++;

    printf("MST Edges:\n");
    for (int i = 0; i < V - 1; i++) printf("%d-%d: %d\n", r[i].u, r[i].v, r[i].w);
    printf("Total MST weight: %d\n", total_weight);
}

int main() {
    Edge edges[] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    kruskal(edges, 4, 5);
    return 0;
}
