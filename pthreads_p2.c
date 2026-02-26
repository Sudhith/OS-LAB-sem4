#include <unistd.h>
#include <stdlib.h>

int sum;//this data is shared by the thread (s)

void *runner(void *);//threads call this function

int main(){

 pthread_t tid;//the thread identifier
 pthread_attr_t attr; //set of thread attribute
 pthread_attr_init(&attr);
 long num1=100000;
//set the default attributes of the thread
 pthread_create(&tid, &attr, runner, (void *) &num1);
//wait for the thread to exit
 pthread_join(tid, NULL);
 printf("sum = %d\n", sum);
}

//the thread will execute in this function

void *runner(void *n1)
{
 int i;
 long *val1=(long *) (n1);
 sum = 0;
 for(i=1; i<=*val1; i++)
  sum +=i;
 pthread_exit(0);
}
