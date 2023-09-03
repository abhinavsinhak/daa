#include<stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int i, j;
    int temp[n];
    
    // Copy the burst time into another array
    for (i = 0; i < n; i++)
        temp[i] = bt[i];
    
    int complete = 0, t = 0, minm = 9999;
    int shortest = 0, finish_time;
    int check = 0;
    
    // Loop until all processes are completed
    while (complete != n) {
        // Find the process with the minimum burst time
        for (j = 0; j < n; j++) {
            if ((temp[j] <= t) && (temp[j] < minm)) {
                minm = temp[j];
                shortest = j;
                check = 1;
            }
        }
        
        // If no process is found, increase the time
        if (check == 0) {
            t++;
            continue;
        }
        
        // Update the finish time
        finish_time = t + minm;
        
        // Update waiting time for the current process
        wt[shortest] = finish_time - bt[shortest];
        
        // Update the remaining burst time
        temp[shortest] = 9999;
        
        // Increment the complete process count
        complete++;
        
        // Update the current time
        t = finish_time;
        
        // Reset the minimum value
        minm = 9999;
        check = 0;
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    int i;
    
    // Calculate turnaround time by adding burst time and waiting time
    for (i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    
    // Calculate waiting time for all processes
    findWaitingTime(processes, n, bt, wt);
    
    // Calculate turnaround time for all processes
    findTurnaroundTime(processes, n, bt, wt, tat);
    
    // Display the header
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        
        // Display each process details
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    
    // Calculate average waiting time and average turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    
    // Display the average times
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int n, i;
    
    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processes[n], burst_time[n];
    
    // Get the burst time for each process
    printf("\nEnter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &burst_time[i]);
        processes[i] = i+1;
    }
    
    // Call the function to find average waiting and turnaround time
    findAverageTime(processes, n, burst_time);
    
    return 0;
}
