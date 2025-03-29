//genereate random number 50-100

#include<stdio.h>
#include<stdlib.h>
int main()
{
   int l = 50;
   int u=100;
   for(int i=0; i<10; i++)
   {
   	int val = rand() % (u-l+1) + l;
	printf("Random value : %d\n",val);

   }
   return 0;
}
