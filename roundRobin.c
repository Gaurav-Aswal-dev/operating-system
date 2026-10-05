#include <stdio.h>

int main()
{
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];

    for (int i = 0; i < n; i++)
    {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];   // Shuru mein poora bacha hai
    }

    int time = 0, completed = 0;
    int ganttPid[200], ganttTime[200], g = 0;
    while (completed < n)
    {
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                found = 1;

                ganttPid[g] = i + 1;
                ganttTime[g] = time;
                g++;

                if (rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    time += rt[i];
                    rt[i] = 0;
                    completed++;

                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }

        if (found == 0)
            time++;
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAvg WT  = %.2f\n", totalWT / n);
    printf("Avg TAT = %.2f\n", totalTAT / n);

    // Gantt Chart
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < g; i++)
        printf("  P%d  |", ganttPid[i]);
    printf("\n");

    printf("%d", ganttTime[0]);
    for (int i = 1; i < g; i++)
        printf("     %d", ganttTime[i]);
    printf("     %d\n", time);

    return 0;
}