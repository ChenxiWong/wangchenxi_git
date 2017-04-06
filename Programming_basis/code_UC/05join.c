//pthread_join函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	//ps指向只读常量区   ps本身在栈区
	char* ps = "hello";
	return ps;
	// str指向栈区  str本身在栈区 局部变量 
	// 永远不要返回一个局部变量的地址
	//char str[] = "hello";
	//return str;
}

int main(void)
{
	//1.启动一个线程
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	//2.主线程等待子线程的处理，并且获取返回值
	char* pc = NULL;
	// pc指针指向了 上面字符串的首地址
	pthread_join(tid,(void**)&pc);
	printf("pc = %s\n",pc);//hello
	return 0;
}


