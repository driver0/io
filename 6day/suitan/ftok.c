#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	key_t key;
	//创建key值，为了用来标识内核对象
	key = ftok(".",'a');
	if(key < 0)
	{
		perror("fail to ftok");
		exit(1);
	}

	printf("key = %d\n",key);
	return 0;
}
