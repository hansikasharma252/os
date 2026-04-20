#include <stdio.h>
#include <pthread.h>

int counter = 0;   // shared global variable
int n;             // number of operations (input)

// Thread 1 → increment
void* func1()
{
    for(int i = 0; i < n; i++)
    {
        counter++;
    }
}

// Thread 2 → decrement
void* func2()
{
    for(int i = 0; i < n; i++)
    {
        counter--;
    }
}

int main()
{
    pthread_t t1, t2;

    // Taking input
    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("Initial counter = %d\n", counter);

    // Create threads
    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Final output
    printf("Final counter value = %d\n", counter);

    return 0;
}


