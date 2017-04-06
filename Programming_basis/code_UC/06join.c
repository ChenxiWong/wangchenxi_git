//使用pthread_join函数获取线程的返回值
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	int i = 0;
	//静态局部变量，生命周期变长
	static int sum = 0;
	for(i = 1; i <= 100; i ++)
	{
		sum += i;
	}
	return (void*)&sum;
}

int main(void)
{
	//1.启动一个线程
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	//2.主线程进行等待,获取返回值
	int* pi = NULL;
	pthread_join(tid,(void**)&pi);
	printf("子线程返回的数据是：%d\n",*pi);
	return 0;
}



