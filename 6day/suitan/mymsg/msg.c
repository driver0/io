#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/msg.h>
#include <string.h>

#define N 32

struct msgbuf
{
	long mtype;//类型
	char mtext[N];
};
#define MSG_SIZE (sizeof(struct msgbuf) - sizeof(long))

int main(int argc, const char *argv[])
{
	key_t key;
	int msgid;
	struct msgbuf msg_snd,msg_rcv;

	//创建key值，为了用来标识内核对象
	key = ftok(".",'a');
	if(key < 0)
	{
		perror("fail to ftok");
		exit(1);
	}

//	printf("key = %d\n",key);
//	创建消息队列
	msgid = msgget(key,IPC_CREAT | IPC_EXCL | 0664);
	if(msgid < 0)
	{
//		system("ipcs -m");
		if(errno == EEXIST)
		{
			msgid = msgget(key, 0664);
		}
		else
		{
			perror("fail to msgget");
			exit(1);
		}
	}
	system("ipcs -q");

#if 0
	msg_snd.mtype = 100;
	strcpy(msg_snd.mtext,"helloword");

//	system("ipcs -q");
	//发送信息
	msgsnd(msgid,&msg_snd,MSG_SIZE,0);
		
	system("ipcs -q");
#endif

	msgrcv(msgid,&msg_rcv,MSG_SIZE,100,0);
	
	printf("  %ld  %s  \n",msg_rcv.mtype,msg_rcv.mtext);
	system("ipcs -q");

	msgctl(msgid,IPC_RMID,NULL);
	system("ipcs -q");
	return 0;
}
