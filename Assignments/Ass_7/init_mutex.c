#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

pthread_mutex_t mutex;// mutex variable
int shared_var = 0;
void* thread_handler(void * arg)
{
  int id = *(int*)arg;
  printf("thread %d is changing the shared_var\n",id);
  int res = pthread_mutex_lock(&mutex);
  if(res != 0)
  {
    printf("lock failed\n");
    return NULL;
  }
  for(int i=0; i<5; i++)
  {
     shared_var+= id;
     printf("%d\n",shared_var);
  }
  sleep(1);
  pthread_mutex_unlock(&mutex);
  printf("thread %d end\n",id);
  return NULL;
}
int main()
{
  pthread_t t1,t2;
  int id1 = 10,id2 = 20;
  // initalizes the mutex;
  int res = pthread_mutex_init(&mutex,NULL);//takes two arguments first is ref of mutex var and second is attributes you want to pass
  //return 0 on success and nonzero on failure
  if(res != 0)
  {
    printf("mutex init fail\n");
    return 0;
  }
  pthread_create(&t1,NULL,thread_handler,&id1);
  pthread_create(&t2,NULL,thread_handler,&id2);

   pthread_join(t1, NULL);
    pthread_join(t2, NULL);

     pthread_mutex_destroy(&mutex);

    printf("Main: Final shared_data = %d\n", shared_var);
    return 0;

}
