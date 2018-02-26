#include <stdio.h>
int main(int argc, const char *argv[])
{
	fputc('a',stdout);
//	fputc('\n',stdout);
//	fputc(10,stdout);
//	sleep(2);
//	fputc('b',stdout);
//	fflush(stdout);
//	while(1);
//	putc(10,stdout);
	
	FILE *fp = NULL;
	if((fp = fopen("test","w")) == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}

	fputc('a',fp);
	fputc('a',fp);
	fputc('\n',fp);
	fputc('a',fp);
	fputc('a',fp);
	fputc('\n',fp);
	fputc('a',fp);
	fclose(fp);
	return 0;

}
