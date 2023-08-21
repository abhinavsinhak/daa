#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int tsp(int graph[MAX_CITIES][MAX_CITIES], int n, int start)
{
    int mask = (1 << n) - 1; 
    int dp[MAX_CITIES][1 << MAX_CITIES];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            dp[i][j] = INT_MAX;
        }
    }

    dp[start][mask] = 0;

    for (int maskSubset = mask; maskSubset >= 0; maskSubset--)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (!(maskSubset & (1 << v)))
                {
                    dp[u][maskSubset] = min(dp[u][maskSubset], graph[u][v] + dp[v][maskSubset | (1 << v)]);
                }
            }
        }
    }

    int minCost = INT_MAX;
    for (int v = 0; v < n; v++)
    {
        if (v != start)
        {
            minCost = min(minCost, graph[start][v] + dp[v][1 << v]);
        }
    }

    return minCost;
}

int main()
{
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int graph[MAX_CITIES][MAX_CITIES];

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int startCity;
    printf("Enter the starting city (0 to %d): ", n - 1);
    scanf("%d", &startCity);

    int minDistance = tsp(graph, n, startCity);
    printf("Minimum distance: %d\n", minDistance);

    return 0;
}
