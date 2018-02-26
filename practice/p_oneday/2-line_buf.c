//测试行缓存的大小及拿出缓存数据的条件
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;

	//程序不结束，缓存区不满，没有刷新函数，也没有'\n'
/*	for(i = 0;i < 5 ; i++)
		printf("%d",i);//猜想：应该是每次调用printf都将要
		//输出的数据寄存在输出缓存中，只有程序结束了，或缓存
		//区满了，或有fflush刷新函数，或遇到‘\n’时才调用系统调用
		//中的文件IO输出进行输出，若没有则一直在缓存区里。
	while(1);*/
	//1.程序结束了
	/*for(i = 0;i < 5 ; i++)
		printf("%d",i);*/
	//2.缓存区满了
	for(i = 0;i < 300 ; i++)
		printf("%4d",i);
	while(1);
	//3.遇到刷新函数了
/*	for(i = 0;i < 5 ; i++)
		printf("%d",i);
		fflush(stdout);
	while(1);*/
	//4.遇到'\n'
	/*for(i = 0;i < 5 ; i++)
		printf("%d\n",i);
	while(1);*/
	return 0;
}
