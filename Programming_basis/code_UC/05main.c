//main函数原型的使用
#include <stdio.h>

int main(int argc,char* argv[],char* envp[])
{
	printf("argc = %d\n",argc);
	int i = 0;
	for(i = 0; i < argc; i++)
	{
		printf("感谢%s!\n",argv[i]);
	}


	//声明全局变量
	extern char** environ;
	printf("environ = %p,envp = %p\n",environ,envp);
	return 0;
}
