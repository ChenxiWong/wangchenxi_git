//设置信号的屏蔽
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void fa(int signo)
{
	//printf("捕获到了信号%d\n",signo);
	printf("捕获到了信号\n");
}

int main(void)
{
	//打印PID,设置信号2 3 50自定义处理
	printf("pid = %d\n",getpid());
	signal(2,fa);
	signal(3,fa);
	signal(50,fa);
	int res = sleep(20);
	if(0 == res)
	{
		printf("虽然没有信号屏蔽，但是没有人打扰到我\n");
	}
	else
	{
		printf("没有信号屏蔽，睡眠被打断，睡了%d秒\n",20-res);
	}
	printf("下面开始屏蔽信号...\n");
	//使用sigprocmask屏蔽信号2 3 50
	sigset_t set,old;
	//清空信号集
	sigemptyset(&set);
	sigemptyset(&old);
	//把信号2 3 50放入set集合中
	sigaddset(&set,2);
	sigaddset(&set,3);
	sigaddset(&set,50);
	res = sigprocmask(SIG_SETMASK,&set,&old);
	if(-1 == res)
	{
		perror("sigprocmask"),exit(-1);
	}
	//查看设置之前默认屏蔽的信号
	printf("old = %ld\n",old);//0
	res = sleep(30);
	if(0 == res)
	{
		printf("设置信号的屏蔽后，美美地睡了一个好觉\n");
	}

	sigset_t pend;
	sigemptyset(&pend);
	//获取在信号屏蔽期间来过的信号
	res = sigpending(&pend);
	if(-1 == res)
	{
		perror("sigpending"),exit(-1);
	}
	printf("pend = %ld\n",pend);
	if(sigismember(&pend,2))
	{
		printf("信号2来过\n");
	}
	if(sigismember(&pend,3))
	{
		printf("信号3来过\n");
	}
	if(sigismember(&pend,50))
	{
		printf("信号50来过\n");
	}
	printf("信号屏蔽被解除\n");
	//恢复系统默认的屏蔽
	sigprocmask(SIG_SETMASK,&old,NULL);
	return 0;
}
