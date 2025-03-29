#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* thread_handler(void *arg)
{
   printf("Thread started: ID %ld\n", pthread_self());
   sleep(2);
   printf("Thread finished: ID %ld\n", pthread_self());
   return NULL;
}

int main()
{
  pthread_t thread;
  pthread_create(&thread,NULL,thread_handler,NULL);

  pthread_detach(thread);
  printf("\nMain thread doen't wait for child thread\n");
  sleep(3);
  printf("main thread finished\n");
  return 0;
}
