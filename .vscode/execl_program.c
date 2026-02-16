#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
        pid_t pid;
        pid = fork();

        if(pid == 0){
                printf("Child Process Started\n");
                printf("Child PID = %d\n", getpid());
                printf("Parent PID = %d\n", getppid());

                sleep(3);

                printf("Child executin ls command using exec()\n");
                execl("/bin/ls", "ls", "-l", NULL);
                printf("Exec failes\n");
        }
        else{
                printf("Parent waiting for child...\n");
                wait(NULL);
                printf("Parent resumes after child termination]n");
        }
return 0;
}
