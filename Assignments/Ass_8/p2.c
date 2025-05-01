#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
  pid_t p;
  int id;
  printf("Enter the pid where you want to send signal:");
  scanf("%d",&id);
  p = (pid_t)id;
  kill(p,SIGINT);
  printf("SIgnal has been sended");
  return 0;
}
