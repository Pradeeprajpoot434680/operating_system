#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
  pid_t pid = fork();
  if(pid==0)
  {
    printf("Child process is running\n");
    while(1);// child is running always
    printf("child is terminated using SIGTERM\n");

  }
  else if(pid>0)
  {
    sleep(3);
    printf("parent is sending the SIGTERM to child\n");
    kill(pid,SIGTERM);    
  }
  return 0;
}
