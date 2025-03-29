#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  printf("Program is running\n");
  sleep(2);
  printf("Something went wrong dueto internal error\n");
  abort();
  return 0;
}



