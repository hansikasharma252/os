#include <stdio.h>
#include <pthread.h>

void* fun() {
    for(int i = 1; i <= 5; i++)
        printf("%d\n", i);
}

int main() {
    pthread_t t;

    pthread_create(&t, NULL, fun, NULL);

    for(int i = 21; i <= 25; i++)
        printf("%d\n", i);

    pthread_join(t, NULL);

    return 0;
}

