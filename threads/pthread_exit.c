#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
void * thread_handler()
{
  printf("thread is running thread id:%ld",pthread_self());
  pthread_exit("thread completed successfully\n");
}
int main()
{
  pthread_t thread;
  void * thread_result;

  if(pthread_create(&thread,NULL,thread_handler,NULL) != 0)
  {
  	printf("thread creation failed\n");
	return 1;
  }
  pthread_join(thread,&thread_result);
  printf("\nthread return: %s\n",(char *)thread_result);
  return 0;
}
