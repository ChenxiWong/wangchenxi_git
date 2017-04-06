//pthread_detach函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	int i = 0;
	for(i = 1; i <= 20; i++)
	{
		printf("子线程中：i = %d\n",i);
	}
}

int main(void)
{
	//1.启动一个子线程，打印1~20之间的数
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	//设置子线程为分离的状态
	pthread_detach(tid);
	//2.主线程进行等待，然后打印1~20之间的数
	pthread_join(tid,NULL);
	int i = 0;
	for(i = 1; i <= 20; i++)
	{
		printf("主线程中：i = %d\n",i);
	}
	return 0;
}
