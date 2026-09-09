#include <stdio.h>

int main() {
    int n, tq;
    int at[10], bt[10], rt[10];
    int wt[10], tat[10];
    int time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);
    
    while (completed < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                found = 1;
                if (rt[i] > tq) {
                    time = time + tq;
                    rt[i] = rt[i] - tq;
                }
                else {
                    // Process finishes
                    time = time + rt[i];
                    rt[i] = 0;

                    completed++;

                    tat[i] = time - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }
        if (found == 0) {
            time++;
        }
    }
    printf("\n\nProcess\tAT\tBT\tWT\tTAT\n");

    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], wt[i], tat[i]);

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f",
           totalWT / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           totalTAT / n);

    return 0;
}