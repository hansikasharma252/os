#include <stdio.h>

int main() {
    int a[50], n, i, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter initial head position: ");
    scanf("%d", &a[0]);   // head stored at first position

    printf("Enter request queue:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++) {
        if(a[i] > a[i+1])
            total += a[i] - a[i+1];
        else
            total += a[i+1] - a[i];
    }

    printf("Total seek time = %d\n", total);
    return 0;
}
