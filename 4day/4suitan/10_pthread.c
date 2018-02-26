#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count = 0;
int value1 = 0;
int value2 = 0;

sem_t sem1,sem2;

void *pthread_handler(void *arg)
{
	while(1)
	{
		sem_wait(&sem2);
		value1 = count;
		value2 = count;
		count++;
		sem_post(&sem1);
	}
	pthread_exit("thread exit");
}
void *pthread_handler1(void *arg)
{
	while(1)
	{
		sem_wait(&sem1);
		if(value1 == value2)
		{
			sleep(1);
			printf("value1 = %d value2 = %d\n",value1,value2);
		}
		sem_post(&sem2);
	}
	pthread_exit(0);
}
int main(int argc, const char *argv[])
{
	pthread_t thread,thread1;
	void *retval;

	sem_init(&sem1,0,0);
	sem_init(&sem2.0,1);
	if(pthread_create(&thread,NULL,pthread_handler1,NULL) != 0)
	{
		perror("pthread_create error");
		return -1;
	}
	if(pthread_create(&thread1,NULL,pthread_handler1,NULL) != 0)
	{
		perror("pthread_create");
	}
	return 0;
}
