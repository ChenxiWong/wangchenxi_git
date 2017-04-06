//错误编号和错误信息的使用
#include <stdio.h>
#include <errno.h>
#include <string.h>

//声明errno变量
//extern int errno;

int main(void)
{
	//出错之前打印errno
	printf("errno = %d\n",errno);
	printf("%d对应的错误信息是：%s\n",errno,strerror(errno));
	perror("没有错误");
	printf("%m\n");

	FILE* fp = fopen("/etc/passwdd","r");
	if(NULL == fp)
	{
		//出错之后打印error
		printf("打开文件失败\n");
		printf("errno = %d\n",errno);
		printf("%d对应的错误信息是：%s\n",errno,strerror(errno));
		perror("出错了");
		printf("%m\n");
		//return -1;
	}
	
	printf("---------------------\n");
	//以"w"方式打开文件/etc/passwd,使用三种方法打印错误信息
	fp = fopen("/etc/passwd","w");
	if(NULL == fp)
	{
		printf("errno = %d\n",errno);
		printf("strerror:%s\n",strerror(errno));
		perror("fopen");
		printf("%m\n");
	}
	return 0;
}
