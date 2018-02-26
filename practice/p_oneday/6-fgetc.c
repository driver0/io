#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp = NULL;
	int ch;
	if((fp = fopen("./6-fgetc.c","r")) == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}

	//ch = fgetc(fp);
	//ch = getc(fp);
	ch = fgetc(stdin); 
	printf("%c\n",ch);
	
	fclose(fp);
	return 0;
}
