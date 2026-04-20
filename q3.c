#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    int pid = fork();

    if (pid == 0) {
        // Child process
        char msg[50];
        read(fd[0], msg, sizeof(msg));
        printf("Child received message: %s\n", msg);
    } else {
        // Parent process
        char msg[] = "Hello from Parent";
        write(fd[1], msg, sizeof(msg));
    }

    return 0;
}


