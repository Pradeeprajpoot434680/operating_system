#include<stdio.h>
#include<unistd.h>//for system calls
#include<sys/types.h>
#include<stdlib.h>//perror
void main(void)
{
printf("Executing ls\n");

execl("/bin/src", "ls", "-1a", (char *)0);

/* If excel returns back, the call has failed... */
perror("execl could not run it");
exit(1);
}
