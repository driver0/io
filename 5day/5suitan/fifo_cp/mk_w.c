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
	char buf_w[N] = {0};

	//创建有名管道文件，对文件已经存在需要做错误处理
	if(mkfifo("myfifo",0664) < 0)
	{
		printf("errno = %d \n",errno);
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

	//打开一个普通文件，并读取其的内容
	fd_r=open("mk_w.c",O_RDONLY);
	if(fd_r < 0)
	{
		perror("fail to open pt");
		exit(1);
	}
	//打开有名管道文件
	
	fd_w = open("myfifo",O_WRONLY);
	if(fd_w < 0)
	{
		perror("fail to open");
		exit(1);
	}

	ssize_t bytes = 0;

	//从普通文件读取数据，写到管道中去
	while((bytes = read(fd_r,buf_w,N)) >0)
	{
		write(fd_w,buf_w,bytes);
	}

	//关闭管道文件
	close(fd_w);
	close(fd_r);
	return 0;

}
