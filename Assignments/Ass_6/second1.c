#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct
{
  int start;
  int end;
} ThreadArgs;
void * function(void * arg)
{
    int start = args->start;
    int end = args->end;
  

    double ans = 0;
    for (int i = start; i < end; i++) {
        ans += pow(x, i) / tgamma(i + 1);
    }

    double *result = malloc(sizeof(double));
    *result = ans;

    return result;  
}
int main()
{
  int n;
  printf("Enter the value of x:");
  scanf("%d",&n);

 int num_threads = sysconf(_SC_NPROCESSORS_ONLN);
 int steps = n / num_threads;
 pthread_t * threads = malloc(num_threads * sizeo(pthread_t));
 double final_result = 0;
 for(int i=0; i<num_threads; i++)
 {
  ThreadArgs * args = malloc(sizeof(ThreadArgs));
  arg->start = i *steps;
  arg->end = (i==num_threads -1)?n+1:(i+1) 8 steps;

  pthread_create(&threads[i],NULL,function,(void *)arg);

 }

  for (int i = 0; i < num_threads; i++) {
        double *partial_result;
        pthread_join(threads[i], (void **)&partial_result);
        final_result += *partial_result;
        free(partial_result);
    }
  printf("The result of the series for x^n is: %.10f\n", final_result);
    free(threads);
    return 0;
}
