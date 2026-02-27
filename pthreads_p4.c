#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int sum=0;//this data is shared by the thread (s)

void *runner(void *);//threads call this function

int main(){

 pthread_t tid1;//the thread identifier
 pthread_t tid2;
 long num1=1000;
 long num2=1000;
//set the default attributes of the thread
 pthread_create(&tid1, NULL, runner, (void *) &num1);
//wait for the thread to exit
 pthread_join(tid1, NULL);

 pthread_create(&tid2, NULL, runner, (void *) &num2);

//wait for the thread to exit
 pthread_join(tid2, NULL);
}

//the thread will execute in this function

void *runner(void *n1)
{
 int i;
 long *val1=(long *) (n1);
 sum = 0;
 for(i=1; i<=*val1; i++)
  sum +=i;
printf("Sum =  %d\n", sum);
 pthread_exit(0);
}
