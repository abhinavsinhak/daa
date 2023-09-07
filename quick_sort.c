#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the employee structure
struct Employee {
    char name[50];
    double salary;
};

// Function to partition the array with the first element as pivot
int partition(struct Employee arr[], int low, int high) {
    double pivot = arr[low].salary; // Use the first element as pivot
    int i = low + 1; // Initialize i to low + 1

    for (int j = low + 1; j <= high; j++) {
        if (arr[j].salary < pivot) {
            // Swap arr[i] and arr[j]
            struct Employee temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    // Swap arr[low] and arr[i - 1] (pivot)
    struct Employee temp = arr[low];
    arr[low] = arr[i - 1];
    arr[i - 1] = temp;

    return (i - 1);
}

// Quicksort function
void quicksort(struct Employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    // Create an array of employees
    struct Employee employees[] = {
        {"John", 50000.0},
        {"Alice", 60000.0},
        {"Bob", 45000.0},
        {"Eve", 70000.0},
        {"Charlie", 55000.0}
    };
    int numEmployees = sizeof(employees) / sizeof(employees[0]);

    // Perform quicksort on the array with the first element as pivot
    quicksort(employees, 0, numEmployees - 1);

    // Print the sorted array
    printf("Sorted by Salary:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%s: %.2f\n", employees[i].name, employees[i].salary);
    }

    return 0;
}
