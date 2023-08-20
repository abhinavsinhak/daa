#include <stdio.h>
#include <limits.h>

#define MAX_MATRICES 100

int matrixChainOrder(int p[], int n) {
    int m[MAX_MATRICES][MAX_MATRICES];
    int i, j, k, L, q;

    // Initialize the m matrix with zeros
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n];
}

int main() {
    int dimensions[] = {10, 30, 5, 60};
    int n = sizeof(dimensions) / sizeof(dimensions[0]) - 1;

    int minScalarMultiplications = matrixChainOrder(dimensions, n);

    printf("Minimum scalar multiplications: %d\n", minScalarMultiplications);

    return 0;
}
