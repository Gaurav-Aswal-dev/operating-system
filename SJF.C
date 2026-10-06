#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[20], at[20], bt[20], ct[20], tat[20], wt[20];
    int done[20] = {0};
    int time = 0, complete = 0;
    float avg_wt = 0, avg_tat = 0;

    int ganttPid[50];     
    int ganttTime[50];     
    int g = 0;            
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }
    while (complete < n)
    {
        int idx = -1, min_bt = 9999;

        for (int i = 0; i < n; i++)
        {
            if (done[i] == 0 && at[i] <= time && bt[i] < min_bt)
            {
                min_bt = bt[i];
                idx = i;
            }
        }

        if (idx == -1)
        {
            time++;
            continue;
        }

        ganttPid[g] = pid[idx];
        ganttTime[g] = time;
        g++;
        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        done[idx] = 1;
        complete++;
    }

    printf("\nGantt Chart:\n|");
    for (int i = 0; i < g; i++)
        printf("  P%d  |", ganttPid[i]);
    printf("\n");

    for (int i = 0; i < g; i++)
        printf("%d     ", ganttTime[i]);
    printf("%d\n", time);

    // Output Table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAvg WT  = %.2f\n", avg_wt / n);
    printf("Avg TAT = %.2f\n", avg_tat / n);

    return 0;
}