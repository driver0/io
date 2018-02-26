#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = NULL;
	char buf[16] = {0};
	int count = 0;

	if((fp = fopen(argv[1],"r")) == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		if(buf[strlen(buf) - 1] == '\n')
			count++;
	}
	printf("count = %d\n",count);
	fclose(fp);

	return 0;
}
