#include <stdio.h>

int main()
{
    int n;
    int burst[10], arrival[10], remaining[10];
    int waiting[10], turnaround[10];

    int completed = 0;
    int time = 0;
    int i, shortest;

    float avgWT = 0, avgTAT = 0;

    printf("Number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        scanf("%d", &burst[i]);

        remaining[i] = burst[i];
    }

    printf("Enter Arrival Time:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        scanf("%d", &arrival[i]);
    }

    printf("\nGantt Chart:\n");

    while(completed < n)
    {
        shortest = -1;

        // Find process with shortest remaining time
        for(i = 0; i < n; i++)
        {
            if(arrival[i] <= time && remaining[i] > 0)
            {
                if(shortest == -1 ||
                   remaining[i] < remaining[shortest])
                {
                    shortest = i;
                }
            }
        }

        // No process has arrived yet
        if(shortest == -1)
        {
            time++;
            continue;
        }

        printf("P%d ", shortest);

        // Run process for 1 unit
        remaining[shortest]--;
        time++;

        // Process completed
        if(remaining[shortest] == 0)
        {
            completed++;

            turnaround[shortest] =
                time - arrival[shortest];

            waiting[shortest] =
                turnaround[shortest] - burst[shortest];
        }
    }

    printf("\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i,
               arrival[i],
               burst[i],
               waiting[i],
               turnaround[i]);

        avgWT += waiting[i];
        avgTAT += turnaround[i];
    }

    avgWT = avgWT / n;
    avgTAT = avgTAT / n;

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}