#include<stdio.h>
#include<unistd.h>

void task()
{
  for(int i=0; i<5; i++)
  {
    printf("Task runnung: %d\n",i);
    sleep(1);
  }

}

int main()
{
  task();
  printf("Main function finished\n");
  return 0;
}
