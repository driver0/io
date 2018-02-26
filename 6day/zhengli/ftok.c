#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
	key_t key;
	
	key = ftok(".",'a');
	if(key < 0)
	{
		perror("fail to ftok");
		exit(1);
	}

	printf("key = %d\n",key);
	return 0;
}
