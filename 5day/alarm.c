#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int ret = -1;
	ret = alarm(8);
	printf("ret = %d\n",ret);
	sleep(2);
	ret = alarm(10);
	printf("ret = %d \n",ret);
	
	while(1)

	return 0;
}
