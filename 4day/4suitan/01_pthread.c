#include <stdio.h>
#include <pthread.h>

void *pthread_handler(void *arg)
{
	int i = *((int *)arg);
	while(i > 0)
	{
		sleep(1);
		printf("thread\n");
		i--;
	}
	pthread_exit("thread exit");
}
int main(int argc, const char *argv[])
{
	pthread_t thread;
	int a = 5;
	void *retval;
	if(pthread_create(&thread,NULL,pthread_handler,(void *)(&a)) != 0)
	{
		perror("fail to pthread_create");
		return -1;
	}

	pthread_join(thread,&retval);
	printf("retval:%s\n",(char *)retval);
	return 0;
}
