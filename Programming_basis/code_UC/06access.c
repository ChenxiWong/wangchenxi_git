//access函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if(0 == access(argv[1],F_OK))
	{
		printf("文件存在\n");
	}
	if(0 == access(argv[1],R_OK))
	{
		printf("文件可读\n");
	}
	if(0 == access(argv[1],W_OK))
	{
		printf("文件可写\n");
	}
	if(0 == access(argv[1],X_OK))
	{
		printf("文件可执行\n");
	}
	return 0;
}
