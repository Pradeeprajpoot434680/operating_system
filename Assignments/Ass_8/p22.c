#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
int main()
{
   pid_t pid;
   int id;
   printf("Enter the id of p1:");
   scanf("%d",&id);
   pid = (pid_t)id;
   kill(pid,SIGINT);
   return 0;
}
