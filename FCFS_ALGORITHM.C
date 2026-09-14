#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Number of processes : ");
    scanf("%d", &n);

    printf("Burst time : ");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Arrival time : ");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);

    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        if (at[i] > ct[i - 1])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt  += wt[i];
    }

    printf("\n-------------------------------------------\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    printf("-------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("-------------------------------------------\n");

    printf("\nGantt Chart : ");
    for (i = 0; i < n; i++)
        printf("P%d  ", i);
    printf("\n");

    printf("\nAverage waiting time: %.2f\n", avg_wt / n);
    printf("Average turnaround time : %.2f\n", avg_tat / n);

    return 0;
}