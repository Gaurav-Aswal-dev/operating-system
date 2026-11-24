#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACK 199 // Disk range 0 se 199 tak maan liya

int main()
{
    int n, i, head, total = 0;
    int req[100];

    printf("Enter number of disk requests : ");
    scanf("%d", &n);

    printf("Enter disk requests : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position : ");
    scanf("%d", &head);

    printf("\nOrder of Service:\n");
    printf("Request\tSeek Distance\n");
    printf("------------------------\n");

    for(i = 0; i < n; i++)
    {
        // 1. Range Check (Invalid request reject karo)
        if(req[i] < 0 || req[i] > MAX_TRACK)
        {
            printf("%d\tREJECTED (Out of range)\n", req[i]);
            continue;
        }

        // 2. Seek Distance Calculate karo
        int dist = abs(head - req[i]);
        total += dist;

        // 3. Print Order & Distance
        printf("%d\t%d\n", req[i], dist);
        
        // Head ko naye position pe le jao
        head = req[i]; 
    }

    printf("\nTotal seek movement : %d\n", total);

    return 0;
}