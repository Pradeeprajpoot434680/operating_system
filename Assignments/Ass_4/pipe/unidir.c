#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
//https://chatgpt.com/c/67d2b9df-b500-8004-ad37-ea118021ea5c ->link for notes
int main()
{
  int fd[2];
  char buffer[100];
  // fd[0] → Read end (used to read data)
  // fd[1] → Write end (used to write data)
  // return 0 on success on failed -1
  //pipe(fd); //initialization pipe
   if (pipe(fd) == -1) {  // Create pipe
        printf("Pipe failed!\n");
        return 1;
    }
    pid_t pid = fork();
   // in this parent will write and child will read

   if(pid>0)
   {
     printf("Parent is executing\n");
     close(fd[0]);
     char message[] = "Hello from parent!\n";
     write(fd[1],message,strlen(message)+1);
     close(fd[1]);
     printf("Parent has almost executed\n");
   }
   else if(pid ==0)
   {
     printf("Child start execute\n");
     close(fd[1]);
     read(fd[0],buffer,sizeof(buffer));
     printf("Chlid recevied : %s\n",buffer);
     close(fd[0]);
     printf("child has executed\n");
   }
  return 0;
}
