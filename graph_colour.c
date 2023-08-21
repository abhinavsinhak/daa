#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10 // Maximum number of vertices

void printSolution(int color[], int V) {
    printf("Vertex Colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
    printf("\n");
}

bool isSafe(int graph[MAX_V][MAX_V], int vertex, int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[MAX_V][MAX_V], int m, int color[], int vertex, int V) {
    if (vertex == V) {
        printSolution(color, V);
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c, V)) {
            color[vertex] = c;
            graphColoringUtil(graph, m, color, vertex + 1, V);
            color[vertex] = 0; // Backtrack
        }
    }

    return false;
}

void graphColoring(int graph[MAX_V][MAX_V], int m, int V) {
    int color[MAX_V];
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize colors
    }

    graphColoringUtil(graph, m, color, 0, V);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX_V][MAX_V];
    printf("Enter the adjacency matrix (0/1):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int m;
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);

    return 0;
}
