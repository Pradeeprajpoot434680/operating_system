#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void signal_handler(int signum)
{
  printf("Dont divide by zero\n");
  exit(1);
}
int main()
{
  signal(SIGFPE,signal_handler);
  int numerator;
  int denominator;
  numerator = 5;
  denominator = 0;
  printf("%d",numerator/denominator);
  return 0;
}
