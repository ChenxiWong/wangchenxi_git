//圆的周长和面积计算
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	int r = *(int*)p;
	printf("圆的周长是：%lf,圆的面积是：%lf\n",2*3.14*r,3.14*r*r);
}

int main(void)
{
	//1.申请动态内存
	int* pi = (int*)malloc(sizeof(int));
	printf("请输入一个半径：\n");
	scanf("%d",pi);
	//2.启动子线程计算周长和面积
	pthread_t tid;
	pthread_create(&tid,NULL,task,pi);
	//3.主线程等待子线程,并且回收资源
	//sleep(1);
	//usleep(100000);
	//使用pthread_join函数进行等待
	pthread_join(tid,NULL);
	free(pi);
	pi = NULL;
	return 0;
}
