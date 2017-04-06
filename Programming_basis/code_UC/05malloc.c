//使用malloc申请动态内存的规则
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	//获取当前进程的进程号
	printf("进程号是：%d\n",getpid());
	int* pi = (int*)malloc(4);
	printf("pi = %p\n",pi);
	
	//故意越界使用一下内存
	//*(pi + 10000) = 250;
	//printf("越界存放的数据是：%d\n",*(pi+10000)); //250
	//故意超出33个内存页的范围
	//*(pi+ 1025*33) = 250;//error
	//十六进制的21000就是33个内存页，也就是十六进制的1000就是1个内存页
	while(1);
	return 0;
}
