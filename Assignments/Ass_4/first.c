#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  pid_t pid = fork();
  if(pid==0)
  printf("Child process is running\n");
  else if(pid>0)
  {
    wait(NULL);
     printf("Parent process is running\n");
  }
  else printf("Fork fail\n"); 
  return 0;
}
