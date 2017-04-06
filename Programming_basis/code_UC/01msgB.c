//使用消息队列进行进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//定义消息的数据类型
typedef struct
{
	long msgtype;//消息类型
	char buf[20];//消息内容
}Msg;

int main(void)
{
	//1.获取key值,使用ftok函数
	key_t key = ftok(".",100);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.获取消息队列,使用msgget函数
	int msgid = msgget(key,0);
	if(-1 == msgid)
	{
		perror("msgget"),exit(-1);
	}
	printf("msgid = %d\n",msgid);
	//3.接受消息,使用msgrcv函数
	Msg msg = {0};
	//始终接受消息队列中的第一个消息
	//int res = msgrcv(msgid,&msg,sizeof(msg.buf),0,0);
	//接受消息队列中第一个类型为1消息
	//int res = msgrcv(msgid,&msg,sizeof(msg.buf),1,0);
	//接受消息队列中<=2的消息
	int res = msgrcv(msgid,&msg,sizeof(msg.buf),-2,0);
	if(-1 == res)
	{
		perror("msgrcv"),exit(-1);
	}
	printf("接受到的消息是：%ld,%s\n",msg.msgtype,msg.buf);
	return 0;
}
