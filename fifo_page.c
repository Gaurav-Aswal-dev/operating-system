
#include <stdio.h>

int main()
{
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};

    int frames[3] = {-1, -1, -1};

    int n = 12, i, j;
    int index = 0, faults = 0, found;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < 3; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            frames[index] = pages[i];

            index = (index + 1) % 3;

            faults++;
        }
    }

    printf("Total Page Faults = %d", faults);

    return 0;
}
