#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int fd[2];
  char buffer[100];
  if(pipe(fd) == -1)
  { 
    printf("Pipe failed");
    return 1;
  }
  pid_t pid = fork();
  
  // first child write or execute then parent
  if(pid == 0)
  {
    printf("child start executing...");
    close(fd[0]); // close for read
    char message[] = "Hello from child\n";
    write(fd[1],message,strlen(message) + 1);
    close(fd[1]);
    printf("Child has finished\n");
  }else if(pid>0)
  {
    printf("Parent start executing...");
    close(fd[1]);
    read(fd[0],buffer,sizeof(buffer));
    printf("Parent recieved:%s\n",buffer);
    close(fd[0]);
    printf("parent has finished\n");
  }
  return 0;
}
