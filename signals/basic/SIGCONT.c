#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle_sigcont(int sig) {
    printf("\nProcess resumed with SIGCONT!\n");
}
int main()
{
 signal(SIGCONT,handle_sigcont);
 printf("Process running with PID: %d\n", getpid());
  while (1) {
        printf("Waiting... (stop with Ctrl+Z, resume with kill -SIGCONT %d)\n", getpid());
        sleep(3);
    }

 return 0; 
}

