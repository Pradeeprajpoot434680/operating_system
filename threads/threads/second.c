#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * task(void * arg)
{
  for(int i=0; i<5; i++)
  {
    printf("Task is runnung in thread:%d\n",i);
    sleep(1);
  }
  return NULL;
}

int main()
{
  pthread_t thread;
  pthread_create(&thread,NULL,task,NULL);
  for (int i = 0; i < 5; i++) 
  {
     printf("Main thread running: %d\n", i);
     sleep(1);
  }
  pthread_join(thread,NULL);
  printf("Main function is finished\n");

  return 0;
 
}
