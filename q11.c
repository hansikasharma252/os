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

    // initialize frames and time
    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

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

        // if page not found
        if(flag == 0) {

            // check for empty frame first
            pos = -1;
            for(j = 0; j < f; j++) {
                if(frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // if empty frame found
            if(pos != -1) {
                frame[pos] = pages[i];
                t++;
                time[pos] = t;
            }
            else {
                // apply LRU
                pos = 0;
                for(j = 1; j < f; j++) {
                    if(time[j] < time[pos])
                        pos = j;
                }

                frame[pos] = pages[i];
                t++;
                time[pos] = t;
            }

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
