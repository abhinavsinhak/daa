#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee {
    char name[50];
    double salary;
};

void swap(struct Employee *a, struct Employee *b) {
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Employee arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].salary > arr[largest].salary)
        largest = left;

    if (right < n && arr[right].salary > arr[largest].salary)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(struct Employee arr[], int n) {
   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i > 0; i--) {
        
        swap(&arr[0], &arr[i]);

      
        heapify(arr, i, 0);
    }
}

int main() {

    struct Employee employees[] = {
        {"John", 50000.0},
        {"Alice", 60000.0},
        {"Bob", 45000.0},
        {"Eve", 70000.0},
        {"Charlie", 55000.0}
    };
    int numEmployees = sizeof(employees) / sizeof(employees[0]);

    heapSort(employees, numEmployees);
    
    printf("Sorted by Salary:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%s: %.2f\n", employees[i].name, employees[i].salary);
    }

    return 0;
}
