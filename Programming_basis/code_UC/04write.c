//write函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开/创建文件
	int fd = open("b.txt",O_WRONLY|O_CREAT|O_EXCL,0644);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.向文件中写入数据
	int res = write(fd,"hello",6);
	if(-1 == res)
	{
		perror("write"),exit(-1);
	}
	printf("写入数据成功，写入的数据大小是：%d\n",res);
	//3.关闭文件
	res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("关闭文件成功\n");
	//练习：vi 04read.c文件,把b.txt中文件内容读取出来，然后打印
	return 0;
}


