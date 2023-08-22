#include <stdio.h>
#include <limits.h>

#define MAX 9999

int n;
int distan[20][20];
int completed_visit;
int DP[32][8];
int optimalPath[32][8];

int TSP(int mask, int curCity)
{
    if (mask == completed_visit)
    {
        return distan[curCity][0];
    }
    if (DP[mask][curCity] != -1)
    {
        return DP[mask][curCity];
    }
    int answer = MAX;
    int nextCity = -1;

    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAnswer = distan[curCity][city] + TSP(mask | (1 << city), city);
            if (newAnswer < answer)
            {
                answer = newAnswer;
                nextCity = city;
            }
        }
    }

    optimalPath[mask][curCity] = nextCity;
    return DP[mask][curCity] = answer;
}

void printPath(int mask, int curCity)
{
    if (mask == completed_visit)
        return;

    int nextCity = optimalPath[mask][curCity];
    printf("%d -> ", nextCity + 1);
    printPath(mask | (1 << nextCity), nextCity);
}

int main()
{
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    completed_visit = (1 << n) - 1;

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &distan[i][j]);
        }
    }

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            DP[i][j] = -1;
        }
    }

    int minDistance = TSP(1, 0);
    printf("Minimum Distance Travelled -> %d\n", minDistance);

    printf("Optimal Path: 1 -> ");
    printPath(1, 0);
    printf("1\n");

    return 0;
}
