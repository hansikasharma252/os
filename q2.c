#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();  // create child process

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        // Child process
        printf("\n\nChild Process:\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else {
        wait(NULL);
        // Parent process
        printf("\nParent Process:\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}

// PID : Process ID
