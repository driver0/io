#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 32

int main(int argc, const char *argv[])
{
	int pipefd[2];
	pid_t pid;
	char buf[N];
	//pipe先创建无名管道
	if(pipe(pipefd) < 0)
	{
		perror("fail to pipe");
		exit(1);
	}
	//fork函数创建进程，实现进程间通讯
	pid = fork();
	if(pid < 0)
	{
		perror("fail to fork");
		exit(1);
	}
	//实现进程之间真正的数据传输
	if(pid == 0)
	{
		//向无名管道写入数据
		while(1)
		{
			fgets(buf,N,stdin);
			write(pipefd[1],buf,N);
		}
	}
	else
	{
		//从无名管道中读出数据
		while(1)
		{
			read(pipefd[0],buf,N);
			printf("--> %s\n",buf);
		}
	}
	return 0;
}
