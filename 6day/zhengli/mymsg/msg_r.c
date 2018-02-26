#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

#define N 32

struct msgbuf {
				long mtype;     //类型
				char mtext[N];   
};


#define MSG_SIZE (sizeof(struct msgbuf)-sizeof(long))


int main(int argc, const char *argv[])
{
	key_t key;
	int msgid;
	struct msgbuf msg_snd,msg_rcv;

	//创建key值：用来标识内核对象
	key = ftok(".",'c');
	if(key < 0)
	{
		perror("fail to ftok");
		exit(1);
	}

//	printf("key = %d\n",key);

	//创建内核对象（消息队列）
	msgid = msgget(key,IPC_CREAT | IPC_EXCL | 0664);
	if(msgid < 0)
	{
		if(errno == EEXIST)
		{
			msgid = msgget(key,0664);
		}
		else
		{
			perror("fail to msgget");
			exit(1);
		}
	}
	//读取数据操作
    msgrcv(msgid,&msg_rcv,MSG_SIZE,100,0); 

	printf("--> %ld %s \n",msg_rcv.mtype,msg_rcv.mtext);

	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
