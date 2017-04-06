//进行简单的测试
#include <stdio.h>

int main(void)
{
	int* pi = (int*)0xbfeeec0c;
	printf("*pi = %d\n",*pi);
	return 0;
}
