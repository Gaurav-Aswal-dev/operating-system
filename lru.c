
#include <stdio.h>

int main()
{
    int pages[] = {1, 2, 3, 1, 4, 5};
    int frames[3] = {-1, -1, -1};
    int time[3] = {0, 0, 0};

    int n = 6, i, j, faults = 0, count = 0;
    int found, pos, min;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < 3; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                time[j] = i;
                break;
            }
        }

        if(found == 0)
        {
            if(count < 3)
            {
                pos = count++;
            }
            else
            {
                min = time[0];
                pos = 0;

                for(j = 1; j < 3; j++)
                {
                    if(time[j] < min)
                    {
                        min = time[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            time[pos] = i;
            faults++;
        }
    }

    printf("Total Page Faults = %d", faults);

    return 0;
}
