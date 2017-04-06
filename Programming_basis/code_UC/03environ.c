//打印环境表中所有的信息
#include <stdio.h>
#include <string.h>

int main(void)
{
	//声明全局变量
	extern char** environ;
	//给环境表首地址指定替身
	char** p = environ;
	while(*p != NULL)
	{
		printf("%s\n",*p);
		//指向下一个
		p++;
	}

	printf("--------------------\n");
	//练习：查找名字为SHELL的环境变量，获取SHELL的值存到buf的字符数组中，然后进行打印
	char buf[20] = {0};
	p = environ;
	while(*p != NULL)
	{
		//比较前6个字符是否相等
		if(!strncmp(*p,"SHELL=",6))
		{
			//跳过环境变量名=
			strcpy(buf,*p+6);
			break;
		}
		//比较下一个
		p++;
	}
	printf("buf = %s\n",buf);
	return 0;
}


