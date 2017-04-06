//观察父子进程对信号处理方式的关系
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//设置对信号2进行自定义处理
	signal(SIGINT,fa);
	//设置对信号3进行忽略处理
	//signal(SIGQUIT,SIG_IGN);
	signal(SIGQUIT,SIG_DFL);
	//创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	if(0 == pid) //子进程
	{
		printf("子进程%d开始执行\n",getpid());
		while(1);
	}
	printf("父进程结束\n");
	return 0;
}
