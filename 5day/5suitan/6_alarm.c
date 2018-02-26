#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//strace 查看操作系统中的系统调用
int main(int argc, const char *argv[])
{
	int ret;
	ret = alarm(8);
	printf("ret = %d\n",ret);

	sleep(2);
	ret = alarm(10);
	ret = printf("ret = %d\n",ret);

	while(1);
	return 0;
}
