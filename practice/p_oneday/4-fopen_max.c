//1.测试fopen最多能打开或获得多少个文件流
//2.系统默认打开的有stdin、stdout、stderr三个流
//3.经测试fopen一共能打开1021个文件流，因为上述默认打开了3个流
//所以一共能打开1024个流
#include <stdio.h>
int main(int argc, const char *argv[])
{
	int i = 0;
//	fclose(stdin);
//	fclose(stdout);
	fclose(stderr);
	while(fopen("./test.txt","r") != NULL)
	{
		i++;
	}
	printf("%d\n",i);
	return 0;
}
