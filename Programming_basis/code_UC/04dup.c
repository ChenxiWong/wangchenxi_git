//dup/dup2函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开/创建一个文件
	int fd = open("d.txt",O_RDWR|O_CREAT/*|O_EXCL*/,0644);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("fd = %d\n",fd);//3
	//2.使用dup函数复制文件描述符
	// int fd2 = fd;
	int fd2 = dup(fd);
	if(-1 == fd2)
	{
		perror("dup"),exit(-1);
	}
	printf("fd2 = %d\n",fd2);//4
	//3.针对不同的描述符进行处理
	write(fd,"A",1);
	write(fd2,"a",1);

	//打开/创建一个新文件
	int fd3 = open("e.txt",O_RDWR|O_CREAT|O_EXCL,0644);
	if(-1 == fd3)
	{
		perror("open"),exit(-1);
	}
	printf("fd3 = %d\n",fd3);//5
	
	//使用dup2函数进行描述符的拷贝
	// fd 到 fd3的拷贝 fd3 和 fd4相等
	int fd4 = dup2(fd,fd3);
	printf("fd3 = %d,fd4 = %d\n",fd3,fd4);// 5 5 

	write(fd3,"1",1); //d.txt

	//4.关闭所有描述符
	close(fd);
	close(fd2);
	close(fd3);
	return 0;
}
