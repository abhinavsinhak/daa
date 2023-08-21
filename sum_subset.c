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
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 35;

    subsetSum(set, n, target);

    return 0;
}
