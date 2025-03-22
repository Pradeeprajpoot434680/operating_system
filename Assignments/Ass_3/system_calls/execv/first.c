#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  printf("Executing process ...");
  execl("/bin/ls","ls","-la",(char *)0);
  perror("execl could not run ls");
  exit(1);
}
