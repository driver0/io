#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock1;
void relock(void *arg)
{
	pthread_mutex_unlock(&lock1);
}	

void *pthread_handler(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock1);
		pthread_cleanup_push(relock,0);
		puts("A");
		sleep(5);
		pthread_cleanup_pop(0);
		pthread_mutex_unlock(&lock1);
	}
	pthread_exit("thread exit");
}

void *pthread_handler1(void *arg)
{
	while(1)
	{
		sleep(2);
		pthread_mutex_lock(&lock1);
		puts("B");
		pthread_mutex_unlock(&lock1);
	}
	pthread_exit(0);
}

int main(int argc, const char *argv[])
{
	pthread_t thread,thread1;
	void *retval;

	pthread_mutex_init(&lock1,NULL);
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

	sleep(3);
	pthread_cancel(thread);

	pthread_join(thread1,NULL);
	pthread_join(thread,&retval);

	pthread_mutex_destroy(&lock1);
	return 0;
}
