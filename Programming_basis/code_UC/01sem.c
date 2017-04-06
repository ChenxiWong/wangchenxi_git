//使用信号量解决多线程抢占资源的问题
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

char* buf[5]; //字符指针数组 全局变量
int pos; //用于指定上面数组的下标

//1.定义互斥量
//pthread_mutex_t mutex;
//1.定义信号量
sem_t sem;

void* task(void* p)
{
	//3.使用互斥量进行加锁
	//pthread_mutex_lock(&mutex);
	//3.获取一个信号量
	sem_wait(&sem);

	buf[pos] = p;
	sleep(1);
	pos++;

	//4.使用互斥量进行解锁
	//pthread_mutex_unlock(&mutex);
	//4.释放一个信号量
	sem_post(&sem);
}

int main(void)
{
	//2.初始化互斥量
	//pthread_mutex_init(&mutex,0);
	//2.初始化信号量
	sem_init(&sem,0/*线程个数*/,1);

	//1.启动一个线程 向数组中存储内容
	pthread_t tid,tid2;
	pthread_create(&tid,NULL,task,"zhangfei");
	pthread_create(&tid2,NULL,task,"guanyu");
	//2.主线程进程等待,并且打印最终的结果
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);

	//5.销毁互斥量
	//pthread_mutex_destroy(&mutex);
	//5.销毁信号量
	sem_destroy(&sem);

	int i = 0;
	printf("字符指针数组中的内容是：");
	for(i = 0; i < pos; i++)
	{
		printf("%s ",buf[i]);
	}
	printf("\n");
	return 0;
}




