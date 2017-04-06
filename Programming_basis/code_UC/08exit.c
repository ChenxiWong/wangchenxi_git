//pthread_exit函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	//static int i = 0;
	int i = 0;
	for(i = 1; i < 100; i++)
	{
		if(10 == i)
		{
			//return &i;
			//pthread_exit((void*)&i);
			// 仅供娱乐
			pthread_exit((void*)i);
			//exit(100);//终止整个进程
		}
		printf("子线程中：i = %d\n",i);
	}
}

int main(void)
{
	//1.启动线程打印1~100之间的数
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	//2.等待子线程结束，并且获取返回值
	//int* pi = NULL;
	//pthread_join(tid,(void**)&pi);
	//printf("子线程中变量的值是：%d\n",*pi);
	int res = 0;
	pthread_join(tid,(void**)&res);
	printf("res = %d\n",res);//10
	return 0;
}


