#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], wt[n], tat[n];
    for(int i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                // Swap Burst Time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap Process ID also
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
    wt[0] = 0;

    for(int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    for(int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n",
               pid[i], bt[i], wt[i], tat[i]);
    }
    int time = 0;

    printf("0");

    for(int i = 0; i < n; i++)
    {
        time = time + bt[i];
        printf("    %d", time);
    }

    printf("\n");

    return 0;
}