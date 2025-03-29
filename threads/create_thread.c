#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function executed by the new thread
void* thread_function(void* arg) {
    printf("Hello from thread! Thread ID: %ld\n", pthread_self());
    sleep(1);
    return NULL;
}

int main() {
    pthread_t thread;

    // Creating a new thread
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        printf("Failed to create thread\n");
        return 1;
    }

    printf("Main thread is waiting for the child thread...\n");

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    printf("Child thread finished execution\n");

    return 0;
}

