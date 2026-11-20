
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, head, size, total = 0;
    int req[100], temp;

    printf("Enter number of disk requests : ");
    scanf("%d", &n);

    printf("Enter disk requests : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position : ");
    scanf("%d", &head);

    printf("Enter disk size : ");
    scanf("%d", &size);

    // Sort requests in ascending order
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(req[j] > req[j+1])
            {
                temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }

    // Find requests greater than head
    for(i = 0; i < n; i++)
    {
        if(req[i] >= head)
            break;
    }

    // Move towards higher cylinder numbers
    for(j = i; j < n; j++)
    {
        total += abs(head - req[j]);
        head = req[j];
    }

    // Move to the last cylinder
    total += abs(head - (size - 1));
    head = size - 1;

    // Reverse direction and service remaining requests
    for(j = i-1; j >= 0; j--)
    {
        total += abs(head - req[j]);
        head = req[j];
    }

    printf("\nTotal seek movement : %d\n", total);

    return 0;
}
