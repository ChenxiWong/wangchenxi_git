//C语言主中的错误处理
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//返回1~10之间的随机数，生成5表示错误
int rand_num(void)
{
	//1.设置随机种子
	srand(time(0));
	//2.生成随机数
	int res = rand()%10+1;
	return 5==res?-1:res;
}
//判断两个参数的大小，返回最大值
int max(int i,int j,int* pi)
{
	if(i == j)
	{
		return -1;
	}
	*pi = i>j?i:j;
	return 0;
}
//判断传入的字符串，进行错误处理
char* judge(char* pc)
{
	if(!strcmp(pc,"error"))
	{
		return NULL;
	}
	return "ok";
}
//打印传入的字符串
void print(char* pc)
{
	printf("传入的字符串是：%s\n",pc);
}

int main(void)
{
	printf("生成的随机数是：%d\n",rand_num());
	int res = 0;
	max(-1,-2,&res);
	printf("最大值是：%d\n",res);
	printf("返回的字符串是：%s\n",judge("let me give you some color to see see"));
	print("我们的口号是：没有蛀牙");
	return 0;
}

