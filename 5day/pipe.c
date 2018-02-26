#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 32
int main(int argc, const char *argv[])
{
	int fd[2];
	pid_t pid;

	//1.先创建管道
	if(pipe(fd) < 0)
	{
		perror("fail to pipe");
		exit(1);
	}

	//2、创建父子进程
	
	pid = fork();
	if(pid < 0)
	{
		perror("fail to fork");
		exit(1);
	}

	//子进程
	if(pid == 0)
	{
		//从标准输入读取数据，然后写入通道中去
		char buff_child[N] = {0};
		while(1)
		{
			fgets(buff_child,N,stdin);
			write(fd[1],buff_child,N);
			if(strncmp(buff_child,"quit",4) == 0)
			{
				exit(0);
			}
		}
	}
	else
	{
// 
		char buff_child[N] = {0};
		while(1)
		{
			fgets(buff_child,N,stdin);
			write(fd[1],buff_child,N);
			if(strncmp(buff_child,"quit",4) == 0)
			{
				exit(0);
			}
		}
	}
	return 0;
}
