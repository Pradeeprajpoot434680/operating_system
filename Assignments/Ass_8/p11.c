#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void signal_handler(int signum)
{
   printf("signal is handled but irnored\n");
}
int main()
{
  signal(SIGINT,signal_handler);
  for(;;)
  {
    pause();
  }
   return 0;
}
