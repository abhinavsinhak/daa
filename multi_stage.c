#include <stdio.h>
#include <limits.h>

#define MAX_STAGES 10
#define MAX_NODES 100

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int multiStageGraph(int graph[MAX_NODES][MAX_NODES], int stages, int nodes)
{
    int cost[MAX_NODES];
    int d[MAX_STAGES][MAX_NODES];

    for (int i = 1; i <= nodes; i++)
    {
        cost[i] = INT_MAX;
    }
    cost[nodes] = 0;

    for (int i = nodes - 1; i >= 1; i--)
    {
        int minCost = INT_MAX;
        for (int j = i + 1; j <= nodes; j++)
        {
            if (graph[i][j] > 0)
            {
                minCost = min(minCost, graph[i][j] + cost[j]);
            }
        }
        cost[i] = minCost;
    }

    for (int i = 0; i <= stages; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            d[i][j] = INT_MAX;
        }
    }

    for (int j = 1; j <= nodes; j++)
    {
        if (graph[1][j] > 0)
        {
            d[1][j] = graph[1][j];
        }
    }

    for (int i = 2; i <= stages; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            for (int k = 1; k <= nodes; k++)
            {
                if (graph[j][k] > 0)
                {
                    d[i][j] = min(d[i][j], graph[j][k] + d[i - 1][k]);
                }
            }
        }
    }

    return d[stages][nodes];
}

int main()
{
    int nodes, edges, stages;
    printf("Enter the number of nodes, edges, and stages: ");
    scanf("%d %d %d", &nodes, &edges, &stages);

    int graph[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the edges (start end weight):\n");
    for (int i = 0; i < edges; i++)
    {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        graph[start][end] = weight;
    }

    int shortestPath = multiStageGraph(graph, stages, nodes);
    printf("Shortest path cost: %d\n", shortestPath);

    return 0;
}
