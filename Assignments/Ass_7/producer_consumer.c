#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
int index = 0;//empty buffer;
int *arr;
int n;
pthread_mutex_t lock;
void producer()
{
  while(index==n)
  {
    printf("Buffer is full! wait for consume the items\n");
    sleep(1);
  }
    pthread_mutex_lock(&lock);
     index++;
     printf("Add the items into the buffer:");
     while(true)
     {
       if(index==n)
       {
         printf("Wait for consumer:");
	 sleep(1);
       }
       else
       {
         printf("Enter the item:");
	 scanf("%d",arr[index]);
	 index++;
       }
     }
     pthread_mutex_unlock(&lock);
}

void consumer()
{
   while(index==-1)
   {
     printf("Buffer is empty , wait for producer\n");
     sleep(1);
   }
    pthread_mutex_lock(&lock);
    printf("items is buffer:\n");
    for(int i=0; i<=index; i++)
    {
      printf("%d\n",*arr[i]);
    }
    index = -1;
    pthread_mutex_unlock(&lock);
   
   return ;
}
int main()
{
  printf("Enter the size of buffer:\n");
  scanf("%d",&n);
  pthread_mutex_init(&lock,NULL);
  
  arr = (int *)malloc(sizeof(int)*n);
  
}
