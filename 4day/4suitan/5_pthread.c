#include <stdio.h>
#include <pthread.h>

int count = 0;
int value1 = 0;
int value2 = 0;

pthread_mutex_t lock;

void *pthread_handler(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		value1 = count;
		sleep(1);
		value2 = count;
		count++;
		pthread_mutex_unlock(&lock);
	}
	pthread_exit("thread exit");
}

void *pthread_handler1(void *arg)
{
	while(1)
	{
	//	pthread_mutex_lock(&lock);
		if(value1 != value2)
		{
			sleep(1);
			printf("value1 = %d value2 = %d\n",value1,value2);
		}
	//	pthread_mutex_unlock(&lock);
	}
	pthread_exit(0);
}

int main(int argc, const char *argv[])
{
	pthread_t thread,thread1;
	void *retval;

	if(pthread_mutex_init(&lock,NULL) != 0)
	{
		perror("pthread_mutex_init error");
		return -1;
	}

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

	pthread_mutex_destroy(&lock);
	return 0;
}
