#include <stdio.h>

int main() {
    int n;
    int at[10], bt[10], priority[10];
    int remaining[10], wt[10], tat[10];

    int time = 0;
    int completed = 0;

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
        printf("\nExecution Order: ");

    while (completed < n) {

        int selected = -1;
        int highest = 999;
        for (int i = 0; i < n; i++) {

            if (at[i] <= time && remaining[i] > 0) {
                if (priority[i] < highest) {
                    highest = priority[i];
                    selected = i;
                }
            }
        }
        if (selected == -1) {
            time++;
            continue;
        }
        printf("P%d ", selected + 1);
        remaining[selected]--;
        time++;
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

    printf("\nAverage Waiting Time = %.2f",
           totalWT / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           totalTAT / n);

    return 0;
}