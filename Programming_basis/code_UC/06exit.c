//各种exit函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void show(void)
{
	printf("我就是被注册的函数\n");
}

int main(void)
{
	//使用atexit函数进行注册
	atexit(show);
	printf("main函数开始执行\n");
	//终止进程
	//exit(100);
	//_exit(100); //立即终止
	_Exit(100); //立即终止
	printf("main函数结束\n");
	return 0;
}
