#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
  printf("Program A is start executing...\n");
  pid_t pid = fork();
  if(pid<0)
  {
    perror("Fork failed\n");
    exit(1);
  }

  if(pid==0)
  {
    //override child process by program C
    printf("Child process is replaced by program c\n");
    execlp("./prog_c","prog_c",NULL);
    printf("execlp failed\n");
    exit(1);
  }else
  {
    wait(NULL);
    printf("Parent process A\n");

  }
  printf("this is the parent process\n");
  printf("Child process is override by program c\n");
  return 0;
}
