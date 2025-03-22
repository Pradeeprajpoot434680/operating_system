#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void sigabrt_handler(int sig)
{
	printf("SIGABRT is recived\n");
	exit(1);
}

int main()
{
	signal(SIGABRT,sigabrt_handler);
	printf("Program start\n");
	printf("Something went wrong! Sending SIGABRT...\n");
        abort();
	printf("This will not be printed.\n");
	return 0;
}

