#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void handler(int sig)
{
     printf("Received SIGTERM (signal %d). Cleaning up and exiting...\n", sig);
    exit(0);
}
int main()
{
  signal(SIGTERM,handler);
  printf("Process is running with pid %d\n",getpid());
  printf("Waiting for dignal...\n");
  while(1)
  {
    sleep(2);
  }
  return 0;
}
