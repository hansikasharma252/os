#include <stdio.h>

int main() {
    int n, i, time = 0, remain, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    while(remain > 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] <= tq) {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                    remain--;
                } else {
                    time += tq;
                    rt[i] -= tq;
                }
            }
        }
    }

    // Turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Output
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    return 0;
}

