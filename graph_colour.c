#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices

void printSolution(int color[]) {
    printf("Vertex Colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

bool isSafe(int graph[V][V], int vertex, int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int vertex) {
    if (vertex == V) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c)) {
            color[vertex] = c;
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return true;
            }
            color[vertex] = 0; // Backtrack
        }
    }

    return false;
}

bool graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize colors
    }

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("No solution exists.\n");
        return false;
    }

    printSolution(color);
    return true;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    graphColoring(graph, m);

    return 0;
}
