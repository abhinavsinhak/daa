#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int jobs[][3], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j][2] < jobs[j + 1][2]) {
                swap(&jobs[j][0], &jobs[j + 1][0]);
                swap(&jobs[j][1], &jobs[j + 1][1]);
                swap(&jobs[j][2], &jobs[j + 1][2]);
            }
        }
    }
}

void scheduleJobs(int jobs[][3], int n) {
    bubbleSort(jobs, n);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i][1] > maxDeadline) {
            maxDeadline = jobs[i][1];
        }
    }

    int schedule[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        schedule[i] = -1;
    }

    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i][1] - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i][0];
                totalProfit += jobs[i][2];
                break;
            }
        }
    }

    printf("Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (schedule[i] != -1) {
            printf("J%d ", schedule[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int jobs[][3] = {
        {1, 4, 50},
        {2, 1, 30},
        {3, 1, 40},
        {4, 2, 60},
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    scheduleJobs(jobs, n);

    return 0;
}
