#include <stdio.h>
//#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp_r = NULL,*fp_w = NULL;
	char buf[16] = {0};
	int count = 0;

	if((fp_r = fopen(argv[1],"r")) == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}

	if((fp_w = fopen(argv[2],"w")) == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}

	while(fgets(buf,sizeof(buf),fp_r) != NULL)
	{
		fputs(buf,fp_w);
	}
	fclose(fp_r);
	fclose(fp_w);
	return 0;
}
