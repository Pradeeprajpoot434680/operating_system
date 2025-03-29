#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void sigsegv_handler(int sig)
{
  printf("catching SIGSEGV,invalid memory access\n");
  exit(1);
}
int main()
{
  signal(SIGSEGV,sigsegv_handler);
  int *ptr = NULL;
  printf("attempting to access NULL pointer\n");
  *ptr = 42;

  return 0;
}
