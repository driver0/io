#include <stdio.h>
#include <pthread.h>

int count = 0;
int value1 = 0;
int value2 = 0;

void *pthread_handler(void *arg)
{
	while(1)
	{
		value1 = count;
		value2 = count;
		count++;
	}
	pthread_exit("thread exit");
}

void *pthread_handler1(void *arg)
{
	while(1)
	{
		if(value1 == value2)
		{
			sleep(1);
			printf("value1 = %d value2 = %d\n",value1,value2);
		}
	}
	pthread_exit(0);
}

int main(int argc, const char *argv[])
{
	pthread_t thread,thread1;
	void *retval;
	if(pthread_create(&thread,NULL,pthread_handler,NULL) != 0)
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


	return 0;
}
