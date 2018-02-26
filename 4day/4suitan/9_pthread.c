#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


int main(int argc, const char *argv[])
{
	sem_t sem;
	int val;
	sem_init(&sem,0,5);

	sem_wait(&sem);
	sem_getvalue(&sem,&val);
	printf("val:%d\n",val);

	sem_post(&sem);
	sem_getvalue(&sem,&val);
	printf("val:%d\n",val);

	return 0;
}
