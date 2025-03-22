#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* task(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Task running in thread: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, task, NULL);
    
    // Main thread continues execution
    for (int i = 0; i < 5; i++) {
        printf("Main thread running: %d\n", i);
        sleep(1);
    }

    pthread_join(thread, NULL);
    printf("Main function finished\n");
    return 0;
}

