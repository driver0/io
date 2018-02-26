#include <stdio.h>
int main(int argc, const char *argv[])
{
	int i = 9;
	FILE *fp;
	if((fp = fopen("./test","w+")) == NULL)
	{
		fprintf(stdout,"fail to fopen\n");
		return -1;
	}
	fprintf(fp,"hello world %d\n",i);

	return 0;
}
