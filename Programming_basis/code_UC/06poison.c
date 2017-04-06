//毒药的设置
#include <stdio.h>

//头摸使用goto
#define GOTO goto
//将goto设置为毒药
#pragma GCC poison goto
//#pragma GCC poison int

int main(void)
{
	GOTO ok;
		printf("main函数开始\n");
	ok:
		printf("main函数结束\n");
	return 0;
}


