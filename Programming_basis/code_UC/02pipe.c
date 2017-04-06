//使用无名管道实现父子进程之间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	//1.创建无名管道
	int pipefd[2];
	int res = pipe(pipefd);
	if(-1 == res)
	{
		perror("pipe"),exit(-1);
	}
	//2.创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	//3.子进程接受数据
	if(0 == pid)//子进程
	{
		//关闭写端
		close(pipefd[1]);
		int i = 0;
		for(i = 0; i < 100; i++)
		{
			int x = 0;
			read(pipefd[0],&x,sizeof(int));
			printf("%d ",x);
			//刷新输出缓冲区
			fflush(stdout);
			usleep(100000);
		}
		printf("\n");
		//关闭读端
		close(pipefd[0]);
		//终止
		exit(0);
	}
	//4.父进程发送数据
	//关闭读端
	close(pipefd[0]);
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		write(pipefd[1],&i,sizeof(int));
		usleep(100000);
	}
	//关闭写端
	close(pipefd[1]);
	return 0;
}


