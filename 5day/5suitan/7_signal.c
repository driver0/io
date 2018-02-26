#include <stdio.h>
#include <signal.h>

//signo 表示内核向你进程传递的信号是哪一个？
void handler(int signo)
{
	printf("ctrl+c\n");
}
int main(int argc, const char *argv[])
{
	//kill -l 查看信号种类
//	signal(SIGINT,SIG_DFL);

   //忽略方式
//	signal(SIGINT,SIG_IGN);

  //捕捉方式
	signal(SIGINT,handler);	
	while(1);
	return 0;
}
