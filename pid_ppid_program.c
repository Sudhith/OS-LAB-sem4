#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();   // create child process

    if (pid == 0) {
        // Child process
        printf("Child Process\n");
        printf("Child PID  = %d\n", getpid());
        printf("Parent PID = %d\n", getppid());
    } else {
        // Parent process
        printf("Parent Process\n");
        printf("Parent PID = %d\n", getpid());
    }

    return 0;
}