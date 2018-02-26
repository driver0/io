#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	//在当前程序利用kill函数给某一个进程发信号
	//先执行信号的默认操作
#if 0	
	if(kill(atoi(argv[1]),atoi(argv[2])) < 0)
	{
		perror("fail to kill");
		exit(1);
	}
#endif
	if(raise(atoi(argv[1])) != 0)
	{
		perror("fail to raise");
		exit(1);
	}
	while(1);
	return 0;
}
