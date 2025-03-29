#include<stdio.h>
#include<stdlib.h>//for rand ()or srand()
int main()
{
  for(int i=0; i<10; i++)
  {
     int val = rand() % 100;
  printf("random value is:%d\n",val);
  }
  return 0;
}
