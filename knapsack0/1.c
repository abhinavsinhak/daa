#include <stdio.h>

struct Item {
    int weight;
    int value;
};

void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortByValuePerWeight(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)items[j].value / items[j].weight;
            double ratio2 = (double)items[j + 1].value / items[j + 1].weight;
            if (ratio1 < ratio2) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

int knapsackGreedy(int W, struct Item items[], int n) {
    sortByValuePerWeight(items, n);

    int currentWeight = 0;
    int totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }

    return totalValue;
}

int main() {
    int W; // Capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int n; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    int maxValue = knapsackGreedy(W, items, n);
    printf("Maximum value that can be obtained using Greedy method is: %d\n", maxValue);

    return 0;
}
