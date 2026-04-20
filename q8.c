#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    // Input burst time
    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Waiting time
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Output
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    return 0;
}
