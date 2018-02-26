#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
#if 0
	//给某个进程发送信号
	if(kill( atoi(argv[1]) , atoi(argv[2])) < 0)
	{
		perror("fail to kill");
		exit(1);
	}
#endif
//给调用进程发送信号
	if(raise(argv[1] != 0))
	{
		perror("fail to raise");
		exit(1);
	}
	while(1);
	return 0;
}
