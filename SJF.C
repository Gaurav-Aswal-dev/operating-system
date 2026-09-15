#include <stdio.h>

int main()
{
    int n;

    printf("Number of processes : ");
    scanf("%d", &n);

    int pid[10], bt[10], at[10], wt[10], tat[10], ct[10];
    float avg_wt = 0, avg_tat = 0;

    // ---- Burst Time input ----
    printf("Burst time : ");
    for (int i = 0; i < n; i++)
    {
        pid[i] = i;
        scanf("%d", &bt[i]);
    }

    // ---- Arrival Time input ----
    printf("Arrival time : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &at[i]);

    // ---- Sort by Burst Time (tera wala) ----
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                int temp = bt[i]; 
                bt[i] = bt[j]; 
                bt[j] = temp;

                temp = pid[i];  
                pid[i] = pid[j]; 
                pid[j] = temp;

                temp = at[i]; 
                at[i] = at[j]; 
                at[j] = temp;
            }
        }
    }

    // ---- WT aur TAT (tera wala) ----
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // ---- Table ----
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);

    // ---- Gantt Chart ----
    printf("\nGantt Chart : ");
    for (int i = 0; i < n; i++)
        printf("P%d ", pid[i]);
    printf("\n");

    printf("0");
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        time = time + bt[i];
        printf("    %d", time);
    }
    printf("\n");

    // ---- Average ----
    printf("\nAverage waiting time: %.2f\n", avg_wt / n);
    printf("Average turnaround time : %.2f\n", avg_tat / n);

    return 0;
}