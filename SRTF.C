#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int arrival[n], burst[n], remaining[n];
    int turnaround[n], waiting[n];
    
    for(i = 0; i < n; i++)
    {
        printf("Enter arrival time of P%d: ", i);
        scanf("%d", &arrival[i]);
        printf("Enter burst time of P%d: ", i);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }
    
    int time = 0, completed = 0, shortest;
    printf("\nGantt Chart: ");
    
    while(completed < n)
    {
        shortest = -1;
        
        for(i = 0; i < n; i++)
        {
            if(arrival[i] <= time && remaining[i] > 0)
            {
                if(shortest == -1 || remaining[i] < remaining[shortest])
                    shortest = i;
            }
        }
        
        if(shortest == -1) { time++; continue; }
        
        printf("P%d ", shortest);
        remaining[shortest]--;
        time++;
        
        if(remaining[shortest] == 0)
        {
            completed++;
            turnaround[shortest] = time - arrival[shortest];
            waiting[shortest] = turnaround[shortest] - burst[shortest];
        }
    }
    
    printf("\n\nProcess\tArrival\tBurst\tTAT\tWT\n");
    float totalTAT = 0, totalWT = 0;
    
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i, arrival[i], burst[i], turnaround[i], waiting[i]);
        totalTAT += turnaround[i];
        totalWT += waiting[i];
    }
    
    printf("\nAvg TAT = %.2f", totalTAT/n);
    printf("\nAvg WT  = %.2f\n", totalWT/n);
    
    return 0;
}