//waitpid函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	//创建二个子进程
	pid_t pid1,pid2;
	pid1 = fork();
	if(-1 == pid1)
	{
		perror("fork"),exit(-1);
	}
	if(0 != pid1) //父进程
	{
		pid2 = fork();
	}
	//三个进程：1个父进程 + 2个子进程
	//printf("一共有几个进程呢?\n");
	if(0 == pid1) //子进程一
	{
		printf("子进程一%d开始运行\n",getpid());
		sleep(5);
		printf("子进程一终止\n");
		exit(100);
	}
	if(0 == pid2)//子进程二
	{
		printf("子进程二%d开始运行\n",getpid());
		sleep(10);
		printf("子进程二终止\n");
		exit(200);
	}
	printf("父进程开始等待...\n");
	//等待任意一个子进程结束
	int status = 0;
	//int res= waitpid(-1,&status,0);
	//等待进程号为pid2的子进程结束
	int res = waitpid(pid2,&status,0);
	//等待进程号为pid1的子进程结束
	res = waitpid(pid1,&status,0);
	if(-1 == res)
	{
		perror("waitpid"),exit(-1);
	}
	printf("父进程等待结束,");
	//判断进程是否正常终止
	if(WIFEXITED(status))
	{
		//获取退出码
		printf("等到的子进程是：%d,子进程的退出码是：%d\n",res,WEXITSTATUS(status));
	}
	return 0;
}
