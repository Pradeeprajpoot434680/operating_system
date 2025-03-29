#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t lock;//declear mutex
int shared_var = 0;

void * thread_function(void *arg)
{
  pthread_mutex_lock(&lock);
  printf("\nthread %ld modifies shared var\n",pthread_self());
  shared_var++;
  sleep(4);
  printf("\nmodified %ld shared var %d",pthread_self(),shared_var);
  pthread_mutex_unlock(&lock);
  return NULL;
}
int main()
{
   pthread_t thread1,thread2;

   pthread_mutex_init(&lock,NULL);
   pthread_create(&thread1,NULL,thread_function,NULL);
   pthread_create(&thread2,NULL,thread_function,NULL);

   pthread_join(thread1,NULL);
   pthread_join(thread2,NULL);

   pthread_mutex_destroy(&lock);

   printf("\nshared variable value:%d",shared_var);
   return 0;
}
