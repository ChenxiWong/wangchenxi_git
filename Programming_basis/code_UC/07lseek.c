//lseek函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件
	int fd = open("c.txt",O_RDWR);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.使用lseek函数调整读写位置
	char c;
	read(fd,&c,sizeof(char));
	printf("c = %c\n",c);//a
	read(fd,&c,sizeof(char));
	printf("c = %c\n",c);//b
	
	printf("------------------\n");
	//调整文件的读写位置
	lseek(fd,2,SEEK_CUR);
	read(fd,&c,sizeof(char));
	printf("c = %c\n",c);//e

	lseek(fd,-2,SEEK_CUR);
	read(fd,&c,sizeof(char));
	printf("c = %c\n",c);//d
	//3.关闭文件
	close(fd);
	return 0;
}
