//#pragma GCC dependency 的使用
#include <stdio.h>

//当前程序依赖于01print.c文件
#pragma GCC dependency "01print.c"

int main(void)
{
	printf("Good Good Study,Day Day Up!\n");
	return 0;
}


