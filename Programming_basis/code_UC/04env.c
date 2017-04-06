//环境表相关函数的使用
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//1.查找环境变量SHELL的值，打印
	char* pc = getenv("SHELL");
	if(NULL == pc)
	{
		perror("getenv"),exit(-1);
	}
	printf("SHELL = %s\n",pc);
	//2.查找环境变量Mark的值,打印
	/*
	pc = getenv("Mark");
	if(NULL == pc)
	{
		perror("getenv"),exit(-1);
	}
	printf("pc = %s\n",pc);
	*/
	printf("--------------------\n");
	//不会修改环境变量的值
	int res = setenv("SHELL","abc",0);
	if(-1 == res)
	{
		perror("setenv"),exit(-1);
	}
	printf("SHELL = %s\n",getenv("SHELL"));// /bin/bash

	//修改环境变量的值
	setenv("SHELL","abc",1);
	printf("修改之后SHELL = %s\n",getenv("SHELL"));//abc
	
	//增加一个环境变量
	setenv("小马哥","年轻就是任性",0);
	printf("增加之后的环境值是：%s\n",getenv("小马哥"));
	
	printf("--------------------\n");
	//修改环境变量
	res = putenv("SHELL=/bin/bash");
	if(0 != res)
	{
		perror("putenv"),exit(-1);
	}
	printf("修改之后SHELL = %s\n",getenv("SHELL"));// /bin/bash
	//增加一个环境变量
	putenv("abc=123");
	printf("增加的环境值是：%s\n",getenv("abc"));//123

	printf("----------------------\n");
	//删除环境变量
	res = unsetenv("小马哥");
	if(-1 == res)
	{
		perror("unsetenv"),exit(-1);
	}
	printf("删除后的结果是：%s\n",getenv("小马哥"));

	unsetenv("abc");
	printf("删除的结果是：%s\n",getenv("abc"));

	printf("--------------------\n");
	//清空环境表
	res = clearenv();
	if(0 != res)
	{
		perror("clearenv"),exit(-1);
	}
	printf("清空整个环境表结束\n");
	printf("PATH = %s\n",getenv("PATH"));
	return 0;
}


