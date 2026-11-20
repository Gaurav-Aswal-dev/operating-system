
#include <stdio.h>

int main()
{
    int alloc[3][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {1, 0, 2}
    };
    int max[3][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {3, 2, 2}
    };
    int avail[3] = {3, 3, 2};
    int need[3][3];
    int finish[3] = {0};
    int safe[3];
    int i, j, count = 0;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    while(count < 3)
    {
        int found = 0;
        for(i = 0; i < 3; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < 3; j++)
                {
                    if(need[i][j] > avail[j])
                        break;
                }
                if(j == 3)
                {
                    for(j = 0; j < 3; j++)
                        avail[j] += alloc[i][j];
                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0)
        {
            printf("System is not safe");
            return 0;
        }
    }
    printf("System is safe\n");
    printf("Safe Sequence: ");
    for(i = 0; i < 3; i++)
        printf("P%d ", safe[i]);

    return 0;
}
