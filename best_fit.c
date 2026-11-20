
#include <stdio.h>

int main()
{
    int block[5] = {100, 500, 200, 300, 600};
    int process[4] = {212, 100, 50, 300};

    int alloc[4] = {-1, -1, -1, -1};

    int i, j, best;

    for(i = 0; i < 4; i++)
    {
        best = -1;

        for(j = 0; j < 5; j++)
        {
            if(block[j] >= process[i])
            {
                if(best == -1 || block[j] < block[best])
                {
                    best = j;
                }
            }
        }

        if(best != -1)
        {
            alloc[i] = best;
            block[best] -= process[i];
        }
    }

    printf("Process\tSize\tBlock\n");

    for(i = 0; i < 4; i++)
    {
        printf("P%d\t%d\t", i+1, process[i]);

        if(alloc[i] != -1)
            printf("%d\n", alloc[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
