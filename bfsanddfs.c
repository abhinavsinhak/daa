#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Function to perform Depth-First Search
void DFS(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[], int vertices, int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] && !visited[i]) {
            DFS(adjMatrix, visited, vertices, i);
        }
    }
}

// Function to perform Breadth-First Search
void BFS(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[], int vertices, int startVertex) {
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;
    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix (%d x %d):\n", vertices, vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    int visited[MAX_VERTICES] = {0};

    printf("DFS traversal starting from vertex 0: ");
    DFS(adjMatrix, visited, vertices, 0);
    printf("\n");

    // Reset visited array
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("BFS traversal starting from vertex 0: ");
    BFS(adjMatrix, visited, vertices, 0);
    printf("\n");

    return 0;
}
