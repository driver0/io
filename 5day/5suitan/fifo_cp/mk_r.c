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
	int fd_w,fd_r;
	char buf[N] = {0};

	//创建有名管道文件，对文件已经存在需要做错误处理
	if(mkfifo("myfifo",0664) < 0)
	{
	//	printf("errno = %d \n",errno);
		if(errno == EEXIST)
		{
			printf("already create\n");
		}
		else
		{
			perror("fail to mkfifo");
			exit(1);
		}
	}

	//打开一个普通文件，对它进行写操作
	fd_W=open("file_cp",O_WRONLY |O_CREAT | O_TRUNC,0664);
	if(fd_W < 0)
	{
		perror("fail to open fd_w");
		exit(1);
	}
	//打开有名管道文件,对它进行读操作
	
	fd_r = open("myfifo",O_RDONLY);
	if(fd_r < 0)
	{
		perror("fail to open fd_r");
		exit(1);
	}

	ssize_t bytes = 0;

	while((bytes = read(fd_r,buf,N)) >0)
	{
		write(fd_w,buf,bytes);
	}

	//关闭管道文件
	close(fd_w);
	close(fd_r);
	return 0;

}
