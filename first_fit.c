
#include <stdio.h>

int main()
{
    int block[5] = {100, 500, 200, 300, 600};
    int process[4] = {212, 100, 50, 300};

    int alloc[4] = {-1, -1, -1, -1};

    int i, j;

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(block[j] >= process[i])
            {
                alloc[i] = j;
                block[j] -= process[i];
                break;
            }
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
