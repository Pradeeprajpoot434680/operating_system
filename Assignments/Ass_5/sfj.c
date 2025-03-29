#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
   int n;
   printf("Enter the number of processes:");
   scanf("%d",&n);
   int arr[n];
   for(int i=0; i<n; i++)
   {
     arr[i] = rand()%101;
   }
   //sort the arr
   
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
	{
            if (arr[j] > arr[j + 1]) 
	    {
                // swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("sorted array\n");
    for(int i=0; i<n; i++)
    {
      printf("%d   ",arr[i]);
    }
    printf("\n");
   // i have burst time
   int avg_time[n];
   avg_time[0] = 0;
   int time = 0;
   double total_avg_time=0;
   for(int i=1; i<n; i++)
   {
      avg_time[i] = arr[i-1] + time;
      time+= arr[i-1];
      total_avg_time+=time; 
   }
    printf("waiting time for each process\n");
   for(int i=0; i<n; i++)
   {

     printf("%d   ",avg_time[i]);

   }
   printf("\n");
   printf("total avg time : %f",total_avg_time/n);
   return 0;


}
