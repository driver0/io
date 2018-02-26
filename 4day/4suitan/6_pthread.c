#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock1,lock2;
void *pthread_handler(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock1);
		puts("A");
		pthread_mutex_lock(&lock2);
		puts("AA");
		pthread_mutex_unlock(&lock2);
		pthread_mutex_unlock(&lock1);
	}
	pthread_exit("thread exit");
}

void *pthread_handler1(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock2);
		puts("B");
		pthread_mutex_lock(&lock1);
		puts("BB");
		pthread_mutex_unlock(&lock1);
		pthread_mutex_unlock(&lock2);
	}
	pthread_exit(0);
}

int main(int argc, const char *argv[])
{
	pthread_t thread,thread1;
	void *retval;

	pthread_mutex_init(&lock1,NULL);
	pthread_mutex_init(&lock2,NULL);

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

	pthread_mutex_destroy(&lock1);
	pthread_mutex_destroy(&lock2);
	return 0;
}
