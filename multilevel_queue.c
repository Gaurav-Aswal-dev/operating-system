#include <stdio.h>

#define MAX 100

// Global arrays
int pid[MAX];
int burst_time[MAX];
int arrival_time[MAX];
int queue_type[MAX];      
int waiting_time[MAX];
int turnaround_time[MAX];
int completion_time[MAX];
int is_completed[MAX];

void multilevelQueueScheduling(int n) {
    int currentTime = 0;
    int completed = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        is_completed[i] = 0;
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
        completion_time[i] = 0;
    }

    printf("\n===== Multilevel Queue Scheduling =====\n");
    printf("System Queue (High Priority) pehle chalega, phir User Queue (Low Priority)\n\n");

    // ===== PEHLE SYSTEM QUEUE (queue_type = 1) =====
    printf("--- System Queue (High Priority) ---\n");
    while (1) {
        int shortest = -1;
        int minArrival = 999999;

        for (i = 0; i < n; i++) {
            if (!is_completed[i] && queue_type[i] == 1) {
                if (arrival_time[i] < minArrival) {
                    minArrival = arrival_time[i];
                    shortest = i;
                }
            }
        }
        if (shortest == -1) break;

        if (currentTime < arrival_time[shortest]) {
            currentTime = arrival_time[shortest];
        }

        waiting_time[shortest] = currentTime - arrival_time[shortest];
        completion_time[shortest] = currentTime + burst_time[shortest];
        turnaround_time[shortest] = completion_time[shortest] - arrival_time[shortest];
        currentTime = completion_time[shortest];
        is_completed[shortest] = 1;
        completed++;

        printf("P%d (System) | Burst: %d | Arrival: %d | Wait: %d | Turnaround: %d | Completion: %d\n",
               pid[shortest], burst_time[shortest], arrival_time[shortest],
               waiting_time[shortest], turnaround_time[shortest], completion_time[shortest]);
    }
    
    printf("\n--- User Queue (Low Priority) ---\n");
    while (1) {
        int shortest = -1;
        int minArrival = 999999;

        for (i = 0; i < n; i++) {
            if (!is_completed[i] && queue_type[i] == 2) {
                if (arrival_time[i] < minArrival) {
                    minArrival = arrival_time[i];
                    shortest = i;
                }
            }
        }

        if (shortest == -1) break;

        if (currentTime < arrival_time[shortest]) {
            currentTime = arrival_time[shortest];
        }

        waiting_time[shortest] = currentTime - arrival_time[shortest];
        completion_time[shortest] = currentTime + burst_time[shortest];
        turnaround_time[shortest] = completion_time[shortest] - arrival_time[shortest];
        currentTime = completion_time[shortest];
        is_completed[shortest] = 1;
        completed++;

        printf("P%d (User) | Burst: %d | Arrival: %d | Wait: %d | Turnaround: %d | Completion: %d\n",
               pid[shortest], burst_time[shortest], arrival_time[shortest],
               waiting_time[shortest], turnaround_time[shortest], completion_time[shortest]);
    }

    float avgWait = 0, avgTurnaround = 0;
    for (i = 0; i < n; i++) {
        avgWait += waiting_time[i];
        avgTurnaround += turnaround_time[i];
    }
    avgWait /= n;
    avgTurnaround /= n;

    printf("\n===== Results =====\n");
    printf("Average Waiting Time: %.2f\n", avgWait);
    printf("Average Turnaround Time: %.2f\n", avgTurnaround);
    printf("Total Time: %d\n", currentTime);
}

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n--- Process %d ---\n", i + 1);

        printf("Enter PID: ");
        scanf("%d", &pid[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &burst_time[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &arrival_time[i]);

        printf("Enter Queue Type (1 = System/High, 2 = User/Low): ");
        scanf("%d", &queue_type[i]);
    }

    multilevelQueueScheduling(n);

    return 0;
}