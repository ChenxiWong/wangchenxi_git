//使用wait函数等待子进程结束
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	//1.创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	//2.子进程工作10秒后终止
	if(0 == pid) //子进程
	{
		printf("子进程%d开始运行\n",getpid());
		sleep(10);
		printf("子进程结束\n");
		_exit(100);
	}
	//3.父进程等待子进程结束
	printf("父进程开始等待\n");
	int status = 0;
	int res = wait(&status);
	printf("等待结束,status = %d,res = %d\n",status,res);
	//判断子进程是否正常终止
	if(WIFEXITED(status))
	{
		//获取子进程退出状态信息
		printf("子进程的退出码是：%d\n",WEXITSTATUS(status));
	}
	return 0;
}



