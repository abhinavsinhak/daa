#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int set[], int n, int target, int subset[], int subsetSize, int index) {
    if (target == 0) {
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return true;
    }

    if (index == n) {
        return false;
    }

    subset[subsetSize] = set[index];
    bool include = isSubsetSum(set, n, target - set[index], subset, subsetSize + 1, index + 1);

    bool exclude = isSubsetSum(set, n, target, subset, subsetSize, index + 1);

    return include || exclude;
}

void subsetSum(int set[], int n, int target) {
    int subset[n];
    bool found = isSubsetSum(set, n, target, subset, 0, 0);

    if (!found) {
        printf("No subset with the given sum exists.\n");
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    int target;
    printf("Enter the target sum: ");
    scanf("%d", &target);

    subsetSum(set, n, target);

    return 0;
}
