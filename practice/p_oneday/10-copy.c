#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp_r = NULL,*fp_w = NULL;
	int ch;
	if((fp_r = fopen(argv[1],"r")) == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}
	if((fp_w = fopen(argv[2],"w")) ==NULL)
	{
		printf("fail to  fopen\n");
		return -1;
	}

	while((ch = fgetc(fp_r)) != EOF)
	{
		fputc(ch,fp_w);
	}

	if(feof(fp_r))//判断流是否到文件结尾
	{
		printf("end\n");
	}
	if(ferror(fp_r)) //判断流是否出错
	{
		printf("error\n");
	}
	clearerr(fp_r);	
	fclose(fp_r);
	fclose(fp_w);
	return 0;
}
