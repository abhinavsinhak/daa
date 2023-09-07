#include <stdio.h>

void sort(int b[], int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((double)a[i] / b[i] > (double)a[j] / b[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

void greedy(int a[], int b[], int m, int n, double ans[])
{
    for (int i = 0; i < n; i++)
    {
        ans[i] = 0.0;
    }

    int u = m;
    int i;

    for (i = 0; i < n; i++)
    {
        if (a[i] > u)
        {
            break;
        }
        ans[i] = 1.0;
        u -= a[i];
    }

    if (i < n)
    {
        ans[i] = (double)u / a[i];
    }
}

int main()
{
    int n;
    int b[10], a[10];

    printf("enter the no of item\n");
    scanf("%d", &n);
    printf("enter the value of item");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b);
    }
    printf("enter the weight of item");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
    }
    double ans[n];

    sort(b, a, n);
    greedy(a, b, 50, n, ans);

    for (int i = 0; i < n; i++)
    {
        printf("%d - %d - %.2f\n", b[i], a[i], ans[i]);
    }

    return 0;
}