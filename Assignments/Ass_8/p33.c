#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main()
{
   pid_t pid;
   int id;
   printf("Enter the pid of p1:");
   scanf("%d",&id);
   pid = (pid_t)id;
   kill(pid,SIGTERM);
   return 0;
}
