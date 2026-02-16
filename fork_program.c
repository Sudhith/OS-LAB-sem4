#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    int status;

    printf("Before fork: Parent PID = %d\n", getpid());
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        printf("\nChild process:\n");
        printf("My PID is %d\n", getpid()); // Get current process ID
        printf("My Parent's PID is %d\n", getppid()); // Get parent process ID
        printf("Child is sleeping for 3 seconds...\n");
        sleep(3); // Sleep for 3 seconds
        printf("Child finished sleeping and is exiting.\n");
        exit(0); // Child terminates
    } else {
        // Parent process
        printf("\nParent process:\n");
        printf("My PID is %d\n", getpid());
        printf("My Child's PID is %d\n", pid); // The value returned by fork()
        printf("Parent is waiting for child to terminate...\n");
        wait(&status); // Parent waits for child
        printf("Child terminated. End of parent process.\n");
    }

    return 0;
}
