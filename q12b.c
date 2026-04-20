#include <stdio.h>

int main() {
    int a[50], visited[50] = {0};
    int n, i, j, total = 0;
    int min, index, diff;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter initial head position: ");
    scanf("%d", &a[0]);   // head stored here

    printf("Enter request queue:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    visited[0] = 1; // head already used

    for(i = 0; i < n; i++) {
        min = 9999;

        for(j = 1; j <= n; j++) {
            if(visited[j] == 0) {
                diff = a[j] - a[0];

                // manual absolute
                if(diff < 0)
                    diff = -diff;

                if(diff < min) {
                    min = diff;
                    index = j;
                }
            }
        }

        total += min;

        // move head to selected request
        a[0] = a[index];
        visited[index] = 1;
    }

    printf("Total seek time = %d\n", total);
    return 0;
}
