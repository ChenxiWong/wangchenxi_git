//查看线程是否共享所在进程的内存
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	// int* pi = p = &num;
	// *pi = *(&num) = num;
	int* pi = p;
	*pi = 200;
}

int main(void)
{
	int num = 100;//局部变量 栈区
	//启动子线程，修改num的值
	pthread_t tid;
	pthread_create(&tid,NULL,task,(void*)&num);
	//主线程打印num的值
	sleep(1);
	printf("主线程中：num = %d\n",num);//200
	return 0;
}


