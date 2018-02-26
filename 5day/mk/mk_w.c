#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
 
#define N 32

int main(int argc, const char *argv[])
{
	int fd_w;
	char buf_w[N] = {0};

	//创建有名管道
	if(mkfifo("errno",0664) < 0) 
	{
		printf("errno = %d \n",errno);
		if(errno == EEXIST)
		{
			printf("already created");
		}
		else
		{
			perror("fail to mkfifo");
			exit(1);
		}
	}

	//打开有名管道文件，对它进行写操作
	fd_w = open("myfifo",O_WRONLY);
	if(fd_w < 0)
	{
		perror("fail to open fd_w");
		exit(1);
	}
#if 0
	write(fd_w,"helloworld",10);
#endif
	while(1)
	{
		fgets(buf_w,N,stdin);

		write(fd_w,buf_w,N);
	}
	close(fd_w);
	//printf("creat special file\n");

	return 0;
}

