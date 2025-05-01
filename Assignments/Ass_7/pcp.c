#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int b_index = -1;
int *arr;
int n;
pthread_mutex_t lock;
pthread_cond_t not_full, not_empty;

void producer()
{
    while (1)
    {
        pthread_mutex_lock(&lock);

        while (b_index == n - 1)
        {
            pthread_cond_wait(&not_full, &lock);
        }

        b_index++;
        printf("Enter the item to add to the buffer: ");
        scanf("%d", &arr[b_index]);
        printf("Added item: %d at index %d\n", arr[b_index], b_index);

        pthread_cond_signal(&not_empty);

        pthread_mutex_unlock(&lock);
        //sleep(1);
    }
}

void consumer()
{
    while (1)
    {
        pthread_mutex_lock(&lock);

        while (b_index == -1)
        {
            pthread_cond_wait(&not_empty, &lock);
        }

        printf("Consumed items from the buffer:\n");
        for (int i = 0; i <= b_index; i++)
        {
            printf("%d\n", arr[i]);
        }

        b_index = -1;

        pthread_cond_signal(&not_full);

        pthread_mutex_unlock(&lock);
        sleep(3);
    }
}

int main()
{
    printf("Enter the size of the buffer: ");
    scanf("%d", &n);

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, (void *)producer, NULL);
    pthread_create(&consumer_thread, NULL, (void *)consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    free(arr);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    return 0;
}

