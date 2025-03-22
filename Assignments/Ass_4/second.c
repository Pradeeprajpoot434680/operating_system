#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
// for zombie process the child will execute without giving signal to parent
int main()
{
  printf("Process executing...\n");
  pid_t pid = fork();
  if(pid == 0)
  {
    printf("Child is executing...\n");
    printf("Child finished\n");
  }
  else if(pid > 0)
  {
    printf("parent is executing...\n");
    sleep(30);
    printf("Parent is finished\n");
  }else
  {
   printf("Fork failed\n");
   }
 return 0;
}
