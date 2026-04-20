#include <stdio.h>
#include <pthread.h>

// Global variables (easy way)
int a = 5, b = 7, sum;

// Thread function
void* add()
{
    printf("num1 = %d\n", a);
    printf("num2 = %d\n", b);
    sum = a + b;
    printf("Inside Thread: Sum = %d\n", sum);
    return NULL;
}

int main()
{
    pthread_t t1;

    // Create thread
    pthread_create(&t1, NULL, add, NULL);

    // Wait for thread to finish
    pthread_join(t1, NULL);                          // comment this line for diff o/p in lab

    printf("In Main: Sum = %d\n", sum);

    return 0;
}
