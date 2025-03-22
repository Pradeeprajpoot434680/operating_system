#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
  int fd1[2];// parent read child write
  int fd2[2];// child read parent write
  char buffer1[100];
  char buffer2[100];
  if(pipe(fd1) == -1 || pipe(fd2) == -1)
  {
    printf("Pipe failed!\n");
    return 1;
  }
  pid_t pid = fork();
  if(pid == 0)
  {
    close(fd1[0]);
    close(fd2[1]);
    read(fd2[0],buffer2,sizeof(buffer2));
    printf("child revieved:%s\n",buffer2);
    char message1[] = "message from child to parent!";
    write(fd1[1],message1,strlen(message1)+1);
    close(fd1[1]);
    close(fd2[0]);
    
  }
   else if(pid > 0)
   {
     close(fd1[1]);
     close(fd2[0]);
     char message2[] = "message from parent to child";
     write(fd2[1],message2,strlen(message2)+1);
     close(fd2[1]);
     read(fd1[0],buffer1,sizeof(buffer1));
     printf("Recieved by:%s\n",buffer1);
     close(fd1[0]);
    }
  return 0;
}
