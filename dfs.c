#include<stdio.h>
#define MAX 100

int n;
int adj[MAX][MAX];
int visited[MAX];

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for(int i = 0; i < n; i++)
        if(adj[v][i] && !visited[i])
            dfs(i);
}

int main() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjecency matrix of the graph:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("\nDFS: ");
    for(i = 0; i < n; i++)
        if(!visited[i])
            dfs(i);

    return 0;
}