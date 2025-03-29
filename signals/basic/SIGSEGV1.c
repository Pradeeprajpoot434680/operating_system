#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler for SIGSEGV
void sigsegv_handler(int sig) {
    printf("Caught segmentation fault (SIGSEGV)\n");
    exit(1);
}

int main() {
    
    signal(SIGSEGV, sigsegv_handler);
     char *str = "Hello"; 
    str[0] = 'M';  

    return 0;
}

