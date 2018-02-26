#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 1024
int main(int argc, const char *argv[])
{
	int fd[2];
	int line = 0;
	char buf[N];
	//创建无名管道
	if(pipe(fd) < 0)
	{
		perror("fail to pipe");
		exit(1);
	}
#if 0
	read(fd[0],buf,32);
#endif
	while(1)
	{

		write(fd[1],buf,1024);
		line++;
		printf("size = %dk\n",line);
		if(line == 64)
		{
			read(fd[0],buf,1024);
			read(fd[0],buf,1024);
			
		    read(fd[0],buf,1024);
			read(fd[0],buf,1024);
		}
	}
	return 0;
}
