#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
int main()
{
  printf("process is running with pid : %d",getpid());
  sleep(2);
  printf("Stop process uning SIGSTOP\n");
  kill(getpid(),SIGSTOP);
  printf("this line will not print\n");
  return 0;
}

