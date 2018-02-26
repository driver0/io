#include <stdio.h>
#include <pthread.h>


void *pthread_handler(void *arg)
{
	int i = 5;
	while(i > 0)
	{
		sleep(1);
		printf("thread\n");
		i--;
	}

	pthread_exit(0);
}

int main(int argc, const char *argv[])
{
	pthread_t thread;
	if(pthread_create(&thread,NULL,pthread_handler,NULL) != 0)
	{
		perror("pthread_create error");
		return -1;
	}	

	pthread_join(thread,NULL);
	return 0;
}

