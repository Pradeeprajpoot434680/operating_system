#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>
#include<string.h>
// to execute first parent we can use pipe such that first parent will execute 
// because the parent will write in the pipe but child will wait for it
// so parent will execute first then child will execute
// one pipe only can send data in one direction
// parent to child or child to parent
// to execute first we have to send data from parent to child
int main()
{
  int fd[2];
  char buffer[20];
  //fd[0] is used to read data
  //fd[1] is used to write data
  //so we want that parent will write and chiild will read
  //close fd[0] in parent because parent will write not read
  //close fd[1] at the child end because 
  pid_t pid;
  pid = fork();
  if (pid != 0)
  {
    close(fd[0]);
    char message[] = "child is waiting\n";
    write(fd[1],message,strlen(message)+1);
    close(fd[1]);
    printf("First\n");
   }
  else
  {
     close(fd[1]);
     read(fd[0],buffer,sizeof(buffer));
     close(fd[0]);
    printf("Second\n");
  }
}
