
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void sigtstp_handler(int sig)
{
  printf("process paused. SIGTSTP(ctrl + z)\n");
  exit(1);
}
int main()
{
  signal(SIGTSTP,sigtstp_handler);
  printf("process is running...\n");
  printf("press ctrl + z to send signal for SIGTSTP\n");
  while(1); 
 return 0;
}
