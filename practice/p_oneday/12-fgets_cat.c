#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp = NULL;
	char buf[6] = {0};
	if((fp = fopen(argv[1],"r")) == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}

	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		printf("%s",buf);
	}
	fclose(fp);
	return 0;
}
