#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#define N 128

char buf[]="";
sem_t sem;

void *pthread_handler1(void *arg)
{
	while(1)
	{
		fgets(buf,N,stdin);
		buf[strlen(buf)-1] = '\0';
		sem_post(&sem);
	}
	pthread_exit(0);
}

void *pthread_handler2(void *arg)
{
	while(1)
	{
		sem_wait(&sem);
		printf("buf = %s\n",buf);
	}
	pthread_exit(0);
}

int main(int argc, const char *argv[])
{
	pthread_t thread1,thread2;
	void *retval;

	if(sem_init(&sem,0,0) < 0)
	{
		perror("sem_init error");
		return -1;
	}

	if(pthread_create(&thread1,NULL,pthread_handler1,NULL) != 0)
	{
		perror("pthread_create error");
		return -1;
	}

	if(pthread_create(&thread2,NULL,pthread_handler2,NULL) != 0)
	{
		perror("pthread_create error");
		return -1;
	}

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	sem_destroy(&sem);
	return 0;
}
