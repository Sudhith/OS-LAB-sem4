#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int sum;//this global variable)
void *runner(void *param);
int main(int argc, char *argv[])
{
runner(argv[1]);
printf("sum = %d\n", sum);
}

void *runner(void *param)
{
 int i, upper = atoi(param);
sum = 0;
 for(i=1; i<=upper; i++)
       sum +=i;
}

