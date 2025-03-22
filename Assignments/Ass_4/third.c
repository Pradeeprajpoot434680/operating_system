
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
   printf("Main process is start executing\n");
   pid_t pid = fork();

   if(pid==0)
   {
      printf("CHild b is override by program c ls");
      execl("/bin/ls","ls","-la",NULL);
   }
   else if(pid>0)
   {
      sleep(2);
      printf("This is the program A\n");

   }
   return 0;
}
