#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int order = 1;
sem_t s;

void* fun(void* arg)
{
    sem_wait(&s);

    if(order == 1)
        printf("Thread %ld is first\n", (long)arg);
    else
        printf("Thread %ld is second\n", (long)arg);

    order++;

    sem_post(&s);
}

int main()
{
    pthread_t t1, t2;

    sem_init(&s, 0, 1);

    pthread_create(&t1, NULL, fun, (void*)1);
    pthread_create(&t2, NULL, fun, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
