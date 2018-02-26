#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

#define N 32

int main(int argc, const char *argv[])
{
	int fd_r,fd_w;
	char buf[N] = {0};

	//创建有名管道
	if(mkfifo("myfifo",0664) < 0)
	{
		//printf("errno = %d\n",errno);
		if(errno == EEXIST)
	}
	return 0;
}
