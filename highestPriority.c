#include <stdio.h>

int main() {
    int n;
    int at[10], bt[10], priority[10];
    int remaining[10], wt[10], tat[10];

    int time = 0;
    int completed = 0;
    int ganttPid[200];
    int ganttStart[200];
    int ganttEnd[200];
    int g = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &priority[i]);

        remaining[i] = bt[i];
    }
    while (completed < n) {
        int selected = -1;
        int highest = 999;

        // Available processes mein se highest priority wali dhoondo
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && remaining[i] > 0) {
                if (priority[i] < highest) {
                    highest = priority[i];
                    selected = i;
                }
            }
        }

        // Agar koi process available nahi
        if (selected == -1) {
            time++;
            continue;
        }
        ganttPid[g] = selected + 1;
        ganttStart[g] = time;

        remaining[selected]--;
        time++;

        ganttEnd[g] = time;
        g++;

        // Agar process khatam ho gayi
        if (remaining[selected] == 0) {
            completed++;
            tat[selected] = time - at[selected];
            wt[selected] = tat[selected] - bt[selected];
        }
    }
    printf("\n\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");

    float totalWT = 0;
    float totalTAT = 0;

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               priority[i],
               wt[i],
               tat[i]);

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < g; i++)
        printf("  P%d  |", ganttPid[i]);
    printf("\n");

    printf("%d", ganttStart[0]);
    for (int i = 0; i < g; i++)
        printf("     %d", ganttEnd[i]);
    printf("\n");

    return 0;
}