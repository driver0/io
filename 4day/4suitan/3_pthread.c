#include <stdio.h>
#include <pthread.h>

void *pthread_handler(void *arg)
{
//	int i = 5;
	int i = *((int *)arg);
	while(i > 0)
	{
		sleep(1);
		printf("thread\n");
		i--;
	}
	pthread_exit("thread exit");
}

void *pthread_handler1(void *arg)
{
	int i = 5;
	while(i > 0)
	{
		sleep(1);
		printf("thread1\n");
		i--;
	}
	pthread_exit(0);
}

int main(int argc, const char *argv[])
{
	pthread_t thread,thread1;
	void *retval;
	int a = 3;
	if(pthread_create(&thread,NULL,pthread_handler,(void *)(&a)) != 0)
	{
		perror("pthread_create error");
		return -1;
	}

	if(pthread_create(&thread1,NULL,pthread_handler1,NULL) != 0)
	{
		perror("pthread_create error");
		return -1;
	}

	pthread_join(thread1,NULL);
	pthread_join(thread,&retval);

	printf("retval:%s\n",(char *)retval);
	return 0;
}
