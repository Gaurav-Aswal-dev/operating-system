#include <stdio.h>
int main() {
    int pages[] = {1, 2, 3, 1, 4, 5};
    int frames[3] = {-1, -1, -1};
    int time[3] = {0, 0, 0};
    int n = 6, faults = 0;
    printf("Ref\tFrames\t\tStatus\n-------------------------\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        // 1. Check for HIT
        for (int j = 0; j < 3; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                time[j] = i; // Recent use time update karo
                break;
            }
        }
        // 2. Handle FAULT
        if (found == 0) {
            int pos = -1;
            // Pehle khali frame dhundo
            for (int j = 0; j < 3; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }
            // Agar khali frame nahi hai, toh LRU (sabse purana) dhundo
            if (pos == -1) {
                pos = 0;
                for (int j = 1; j < 3; j++) {
                    if (time[j] < time[pos]) {
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            time[pos] = i;
            faults++;
        }
        // 3. Print current state
        printf("%d\t", pages[i]);
        for (int j = 0; j < 3; j++) {
            if (frames[j] == -1) printf("- ");
            else printf("%d ", frames[j]);
        }
        printf("\t\t%s\n", found ? "HIT" : "FAULT");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}