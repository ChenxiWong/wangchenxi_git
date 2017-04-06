//使用UC实现向文件中写入数据
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开/创建文件
	int fd = open("num2.dat",O_WRONLY|O_CREAT|O_EXCL,0644);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("fd = %d\n",fd); //3

	//2.写入数据到文件中
	//自定义缓冲区来提高效率
	int buf[10000];
	int i = 0;
	for(i = 1; i <= 1000000; i++)
	{
		if(9999 == (i-1)%10000)
		{
		  //write(fd,&i,sizeof(int));
	      buf[9999] = i;
    	  write(fd,buf,sizeof(buf));
		}
		buf[(i-1)%10000] = i;
	}
	//3.关闭文件
	close(fd);
	return 0;
}
