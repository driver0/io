#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp = NULL;
	int ch,count = 0;
	if((fp = fopen(argv[1],"r")) == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}

	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			count++;
		}
	}

	printf("count = %d\n",count);
	fclose(fp);
	return 0;
}
