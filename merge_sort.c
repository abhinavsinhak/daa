#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int s, int mid, int r) {
    int n1 = mid - s + 1;
    int n2 = r - mid;
    int *arr1 = (int *)malloc(sizeof(int) * n1);
    int *arr2 = (int *)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[s + i];
    }
    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
            k++;
        } else {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }

    free(arr1);
    free(arr2);
}

void divide(int arr[], int s, int r) {
    if (s < r) {
        int mid = s + (r - s) / 2;
        divide(arr, s, mid);
        divide(arr, mid + 1, r);
        merge(arr, s, mid, r);
    }
}

int main() {
    int arr[] = { 2, 7, 5, 3, 9, 3, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    divide(arr, 0, len - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
