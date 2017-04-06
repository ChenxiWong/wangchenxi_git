//open函数和close函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开/创建文件
	//文件不存在则创建，存在则打开
	//int fd = open("a.txt",O_RDONLY|O_CREAT,0644);
	//文件不存在则创建,存在则创建失败
	//int fd = open("a.txt",O_RDONLY|O_CREAT|O_EXCL,0644);
	//文件存在则清空文件
	int fd = open("a.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
 
	// 1 64 512 进行按位或则对应位置1
	printf("O_WRONLY = %d,O_CREAT = %d,O_TRUNC = %d\n",O_WRONLY,O_CREAT,O_TRUNC);

	//2.关闭文件
	int res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("关闭文件成功\n");
	return 0;
}


