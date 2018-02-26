#include <stdio.h>

int main(int argc, const char *argv[])
{
	char buf[8] = {0};
	fgets(buf,8,stdin);
	printf("%s\n",buf);
	return 0;
}
