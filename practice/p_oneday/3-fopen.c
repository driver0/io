#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fd = NULL;
	if((fd = fopen("./test.txt","w")) == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}
	return 0;
}
