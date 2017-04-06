//使用sigaction函数处理信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
	sleep(5);
	printf("信号处理完毕\n");
}

int main(void)
{
	//定义结构体变量并且进行初始化
	struct sigaction action = {};
	//指定函数指针的初始值
	action.sa_handler = fa;
	//清空信号集，然后放入信号3
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask,3);
	//设置处理信号的标志
	//解除对相同信号的屏蔽,信号2
	//action.sa_flags = SA_NODEFER;
	//自定义处理后恢复默认处理方式
	action.sa_flags = SA_RESETHAND;

	//使用sigaction对信号2自定义处理
	sigaction(2,&action,NULL);
	while(1);
	return 0;
}
