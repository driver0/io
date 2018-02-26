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
	char buf[N]={0};
	//创建有名管道文件，对文件已经存在需要做错误处理
	if(mkfifo("myfifo",0664) < 0)
	{
		if(errno == EEXIST)
		{
			printf("named file exit\n");
		}
		else
		{
			perror("fail to mkfifo");
			exit(1);
		}
	}

//	printf("create mkfifo success \n");

	//打开有名管道文件
	int fd;
	//使用有名管道通信时，只启动一个读程序时，
	//会在open这个地方产生阻塞，只有另外一个写的程序
	//启动时才会进入到read或者write这个位置阻塞等待数据
	
	fd = open("myfifo",O_WRONLY);
	if(fd < 0)
	{
		perror("fail to open");
		exit(1);
	}
	//执行写操作
	while(1)
	{
		//从标准输入读取数据
		fgets(buf,N,stdin);

 		write(fd,buf,N);
	}

	//关闭管道文件
	close(fd);
	return 0;
}
