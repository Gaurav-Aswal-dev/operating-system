#include <stdio.h>

int main() {
    int n, tq;
    int at[10], bt[10], rt[10];
    int wt[10], tat[10];

    int time = 0;
    int completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for (int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);   // ← i+1 se P1, P2, P3

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("\nExecution Order: ");

    while (completed < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                found = 1;

                if (rt[i] > tq) {
                    printf("P%d ", i + 1);   // ← i+1 se print
                    time = time + tq;
                    rt[i] = rt[i] - tq;
                }
                else {
                    printf("P%d ", i + 1);   // ← i+1 se print
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
               i + 1, at[i], bt[i], wt[i], tat[i]);   // ← i+1

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}