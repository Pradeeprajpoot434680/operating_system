#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int x;
    int n;
} ThreadArgs;

void *calculate(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    int start = args->start;
    int end = args->end;
    int x = args->x;
    int n = args->n;
    
    double ans = 0;
    for (int i = start; i < end; i++) {
        ans += pow(x, i) / tgamma(i + 1);
    }

    double *result = malloc(sizeof(double));
    *result = ans;

    return result;
}

int main() {
    int x, n;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int num_threads = sysconf(_SC_NPROCESSORS_ONLN);
    int steps = n / num_threads;

    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
    double final_result = 0;

    for (int i = 0; i < num_threads; i++) {
        ThreadArgs *args = malloc(sizeof(ThreadArgs));
        args->start = i * steps;
        args->end = (i == num_threads - 1) ? n + 1 : (i + 1) * steps;
        args->x = x;
        args->n = n;

        pthread_create(&threads[i], NULL, calculate, (void *)args);
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

