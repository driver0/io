#include <stdio.h>
#include <pthread.h>

void *pthread_handler(void *arg)
int main(int argc, const char *argv[])
{
	pthread_t thread;
	
	if(pthread_create(&thread,NULL,pthread_handler,NULL))
	return 0;
}
