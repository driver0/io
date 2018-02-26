#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp = NULL;
	int ch;
	if((fp = fopen(argv[1],"r")) == NULL) //argv[]是命令行参数的数组
	{
		printf("fail to fopen\n");
		return -1;
	}

	while((ch = fgetc(fp)) != EOF)
	{
		printf("%c",ch);
	}
	fclose(fp);
	return 0;
}
