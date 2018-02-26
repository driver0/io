#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp = NULL;
	if((fp = fopen("./test","w")) == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}
	fclose(fp);
	//fclose(fp);//不能重复关闭流

	return 0;
}
