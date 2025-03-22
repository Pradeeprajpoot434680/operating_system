#include<stdio.h>
#include<unistd.h>
int main()
{
  printf("Program C is running ! (PID= %d)\n",getpid());
  // this makes infinite loop
  //execlp("./prog_a","prog_a",NULL);
  return 0;
}
