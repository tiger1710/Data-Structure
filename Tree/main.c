#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 100

int parent[MAX_VERTICES];

void set_init(int n) {
    for (int i = 0; i < MAX_VERTICES; i++)
        parent[i] = -1;
}
int set_find(int curr) {
    if (parent[curr] == -1) return curr;

    while (parent[curr] != -1)
        curr = parent[curr];
    
    return curr;
}

void set_union(int a, int b) {
    int set1 = set_find(a);
    int set2 = set_find(b);

    if (set1 != set2)
        parent[set1] = set2;
}

typedef struct Edge {
    int start, end, weight;
} Edge;

typedef struct GraphType {
    int n;
    Edge edges[2* MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g) {
    g->n = 0;
    for (int i = 0; i < 2 * MAX_VERTICES; i++) {
        g->edges[i].end = g->edges[i].start = 0;
        g->edges[i].weight = INF;
    }
}

void insert_edge(GraphType* g, int start, int end, int weight) {
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = weight;
    g->n++;
}

int compare(const void* a, const void* b) {
    Edge* x = (Edge*)a;
    Edge* y = (Edge*)b;
    return x->weight - y->weight;
}

void kruscal(GraphType* g) {
    int edge_accepted = 0;
    set_init(g->n);
    qsort(g->edges, g->n, sizeof(Edge), compare);

    int i = 0;
    while (i < (g->n)) {
        Edge e = g->edges[i++];
        int uset = set_find(e.start);
        int vset = set_find(e.end);
        if (uset != vset) {
            printf("(%d, %d) %d\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset);
        }
    }
}

int main(void) {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);

    insert_edge(g, 0, 1, 29);
    insert_edge(g, 1, 2, 16);
    insert_edge(g, 2, 3, 12);
    insert_edge(g, 3, 4, 22);
    insert_edge(g, 4, 5, 27);
    insert_edge(g, 5, 0, 10);
    insert_edge(g, 6, 1, 15);
    insert_edge(g, 6, 3, 18);
    insert_edge(g, 6, 4, 25);

    kruscal(g);
    free(g);

    return 0;
}