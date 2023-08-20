#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int vertices, edges;

void bfs(int startVertex) {
    bool queue[MAX_VERTICES] = {false};
    int front = 0, rear = 0;
    queue[rear] = startVertex;
    visited[startVertex] = true;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int currentVertex = queue[front];
        printf("%d ", currentVertex);
        front++;

        for (int i = 0; i < vertices; i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    // Initialize the adjacency matrix and visited array
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
        for (int j = 0; j < MAX_VERTICES; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    // Read the edges of the graph
    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        adjacencyMatrix[vertex1][vertex2] = 1;
        adjacencyMatrix[vertex2][vertex1] = 1; // Assuming an undirected graph
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Reset visited array for BFS
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    bfs(startVertex);
    printf("\n");

    return 0;
}
