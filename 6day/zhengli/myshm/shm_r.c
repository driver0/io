#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>

int main(int argc, const char *argv[])
{
	key_t key;
	int shmid;
	char *ptr;

	//创建key值：为了用来标识内核对象
	key = ftok(".",'a');
	if(key < 0)
	{
		perror("fail to ftok");
		exit(1);
	}

//	printf("key = %d\n",key);

//	创建内核对象（共享空间）
 	shmid = shmget(key,128,IPC_CREAT | IPC_EXCL | 0664);
	if(shmid < 0)
	{
		if(errno == EEXIST)
		{
			shmid = shmget(key,128,0664);
		}
		else
		{
			perror("fail to shmget");
			exit(1);
		}
	}
	system("ipcs -m");

	//映射内核空间中的共享内存段到用户空间
	ptr = (char *)shmat(shmid,NULL,0);
	if(ptr == (char *)-1)
	{
		perror("fail to shmat");
		exit(1);
	}

	printf("--> %s \n",ptr);

	system("ipcs -m");

	//解除映射
	if(shmdt(ptr) < 0)
	{
		perror("fail to shmdt");
		exit(1);
	}

	system("ipcs -m");

//删除内核对象（共享空间）

	if(shmctl(shmid,IPC_RMID,0) < 0)
	{
		perror("fail to shmctl");
		exit(1);
	}
	system("ipcs -m");	
	return 0;
}
