#include <stdio.h>

int main() {
    int n;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    int idle = 0, busy = 0;
    float avg_tat = 0, avg_wt = 0, avg_bt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Arrival Time & Burst Time
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        avg_bt += bt[i];
    }

    // FCFS Completion Time
    ct[0] = at[0] + bt[0];
    busy += bt[0];

    for (int i = 1; i < n; i++) {
        if (ct[i - 1] < at[i]) {
            idle += at[i] - ct[i - 1];
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }
        busy += bt[i];
    }

    // TAT & WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    // Output Table
    printf("\n------------------------------------------------------\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("------------------------------------------------------\n");

    // Averages
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);
    printf("Average Waiting Time    = %.2f\n", avg_wt / n);
    printf("Average Burst Time      = %.2f\n", avg_bt / n);

    printf("CPU Idle Time = %d\n", idle);
    printf("CPU Busy Time = %d\n", busy);

    return 0;
}




