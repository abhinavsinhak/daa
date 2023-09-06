#include <stdio.h>

void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(double valuePerWeight[], int weight[], int value[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (valuePerWeight[j] < valuePerWeight[j + 1]) {
                swap(&valuePerWeight[j], &valuePerWeight[j + 1]);
                swap(&weight[j], &weight[j + 1]);
                swap(&value[j], &value[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(int W, int weight[], int value[], int n) {
    double valuePerWeight[n];
    for (int i = 0; i < n; i++) {
        valuePerWeight[i] = (double)value[i] / weight[i];
    }

    bubbleSort(valuePerWeight, weight, value, n);

    int currentWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= W) {
            currentWeight += weight[i];
            finalValue += value[i];
        } else {
            int remainingWeight = W - currentWeight;
            finalValue += (double)remainingWeight * valuePerWeight[i];
            break;
        }
    }

    return finalValue;
}

int main() {
    int W;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weight[n];
    int value[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &value[i]);
    }

    double maxValue = fractionalKnapsack(W, weight, value, n);
    printf("Maximum value that can be obtained is: %.2lf\n", maxValue);

    return 0;
}
