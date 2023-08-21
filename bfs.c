#include <stdio.h>

#define MAX 100

int queue[MAX], visited[MAX];
int adj[MAX][MAX];
int n, front = -1, rear = -1;

// BFS algorithm
void bfs(int start) {
    int i, j;
    printf("BFS Traversal: ");
    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        i = queue[++front];
        printf("%d ", i);

        for (j = 1; j <= n; j++) {
            if (adj[i][j] && !visited[j]) {
                visited[j] = 1;
                queue[++rear] = j;
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}