#include <stdio.h>

int main() {
    int pages[50], frame[10], time[10];
    int n, f, i, j, pos, faults = 0, t = 0, flag;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // initialize frames
    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++) {
        flag = 0;

        // check if page already present
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                t++;
                time[j] = t;
                flag = 1;
                break;
            }
        }

        // if page fault
        if(flag == 0) {
            pos = 0;

            // find least recently used
            for(j = 1; j < f; j++) {
                if(time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];
            t++;
            time[pos] = t;
            faults++;
        }

        // display frames
        printf("Frames: ");
        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
