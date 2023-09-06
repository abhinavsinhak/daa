#include <stdio.h>
#include <stdbool.h>

#define MAX_EDGES 100

struct Edge {
    int src;
    int dest;
    int weight;
};

void heapify(struct Edge edges[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && edges[left].weight < edges[smallest].weight) {
        smallest = left;
    }

    if (right < n && edges[right].weight < edges[smallest].weight) {
        smallest = right;
    }

    if (smallest != i) {
        struct Edge temp = edges[i];
        edges[i] = edges[smallest];
        edges[smallest] = temp;
        heapify(edges, n, smallest);
    }
}

void buildHeap(struct Edge edges[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(edges, n, i);
    }
}

void heapSort(struct Edge edges[], int n) {
    buildHeap(edges, n);

    for (int i = n - 1; i >= 0; i--) {
        struct Edge temp = edges[0];
        edges[0] = edges[i];
        edges[i] = temp;

        heapify(edges, i, 0);
    }
}

int findParent(int parent[], int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent, parent[node]);
    }
    return parent[node];
}

void unionSets(int parent[], int x, int y) {
    int xParent = findParent(parent, x);
    int yParent = findParent(parent, y);
    parent[xParent] = yParent;
}

void kruskalMST(struct Edge edges[], int n, int m) {
    sortEdges(edges, m);

    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    struct Edge mst[MAX_EDGES];
    int mstSize = 0;

    for (int i = 0; i < m; i++) {
        int srcParent = findParent(parent, edges[i].src);
        int destParent = findParent(parent, edges[i].dest);

        if (srcParent != destParent) {
            mst[mstSize++] = edges[i];
            unionSets(parent, srcParent, destParent);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < mstSize; i++) {
        printf("(%d, %d) weight: %d\n", mst[i].src, mst[i].dest, mst[i].weight);
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes and edges in the graph: ");
    scanf("%d %d", &n, &m);

    struct Edge edges[MAX_EDGES];
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    heapSort(edges, m);
    kruskalMST(edges, n, m);

    return 0;
}
