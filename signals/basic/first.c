#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void handler_sigint(int sig)
{
  printf("Recieved SIGINT");
}
int main()
{
  signal(SIGINT,handler_sigint);

  while(1)
  {
     printf("Running... press Ctrl + c to send SIGINT\n");
     sleep(2);
  }
  return 0;
}
