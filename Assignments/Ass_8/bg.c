#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("Running... %d\n", i);
        fflush(stdout);  // Ensure output is shown immediately
        sleep(1);        // Wait 1 second
    }

    printf("Done!\n");
    return 0;
}

