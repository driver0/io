#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <errno.h>

union semun {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO
								(Linux-specific) */
};

int main(int argc, const char *argv[])
{
	key_t key;
	int semid;
	union semun sem_val;

	//创建key值，为了用来标识内核对象
	key = ftok(".",'d');
	if(key < 0)
	{
		perror("fail to ftok");
		exit(1);
	}

//	printf("key = %d\n",key);
	
	//创建信号量集
	semid = semget(key,1,IPC_CREAT | IPC_EXCL | 0664);
	if(semid < 0)
	{
		if(errno == EEXIST)
		{
			semid = semget(key,1,0664);
		}
		else
		{
			perror("fail to semget");
			exit(1);
		}
	}
    else//初始化一次
	{
		sem_val.val=1;
    	semctl(semid,0,SETVAL,sem_val);
	}
	system("ipcs -s");

	struct sembuf mysembuf,my[2];
	//mysembuf.sem_num = 0;
	//mysembuf.sem_op = -5;
	//mysembuf.flg = 0;
	
	my[0].sem_num = 0;
	my[0].sem_op = -1;
	my[0].sem_flg = 0;
	
	my[1].sem_num = 2;
	my[1].sem_op = -5;
	my[1].sem_flg = IPC_NOWAIT;
	semop(semid,&mysembuf,1);
	
	return 0;
}
