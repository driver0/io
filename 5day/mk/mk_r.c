#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#define N 32

int main(int argc, const char *argv[])
{
	int fd_r;
	char buf[N]={0};

	//创建有名管道
	if(mkfifo("myfifo",0664) < 0)
	{
		//printf("errno = %d \n",errno);
		if(errno == EEXIST)
		{
			printf("already created\n");
		}
		else
		{
			perror("fail to mkfifo");
			exit(1);
		}
	}
	//打开有名管道文件，对它进行读操作
	fd_r = open("mkfifo",O_RDONLY);
	if(fd_r < 0)
	{
		perror("fail to open fd_r");
		exit(1);
	}

	printf("------------------\n");
#if 0
	read(fd_r,buf,10);
	printf("--> %s \n",buf);
#endif
	while(1)
	{
		read(fd_r , buf, N);
		printf("--> %s \n",buf);
	}
	
	close(fd_r);
	//printf("create special file\n");
	return 0;
}
