#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
void * handler1(void *arg)
{
  int num = *(int *)arg;
  printf("thread %d is strat executing\n",num);
  sleep(8);
  printf("Execution of the thread %d is complete\n",num);
  return NULL;
}

void * handler2(void *arg)
{                                                                                                                                                                            int num = *(int *)arg;
  printf("thread %d is strat executing\n",num);
  sleep(4);
  printf("Execution of the thread %d is complete\n",num);
  return NULL;                                                                                                                                                             }


void * handler3(void *arg)
{                                                                                                                                                                            int num = *(int *)arg;
  printf("thread %d is strat executing\n",num);
  sleep(1);
  printf("Execution of the thread %d is complete\n",num);
 
  return NULL;  

}

int main()
{
  pthread_t thread[3];
  int ids[3]={1,2,3};
  pthread_create(&thread[0],NULL,handler1,&ids[0]);
  pthread_create(&thread[1],NULL,handler2,&ids[1]);
  pthread_create(&thread[2],NULL,handler3,&ids[2]);

  pthread_join(thread[0],NULL);
  pthread_join(thread[1],NULL);
  pthread_join(thread[2],NULL);
  printf("all threads completed\n");
  return 0;
}
