//测试一下加锁的同时是否可以读写
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件
	int fd = open("a.txt",O_RDWR);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	//准备一把锁
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 5;
	lock.l_pid = -1;
	//尝试加锁是否成功
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res)
	{
		printf("加锁失败，不能进行写操作\n");
	}
	else
	{
		//2.写入数据
		res = write(fd,"hello",5);
		if(-1 == res)
		{
			perror("write"),exit(-1);
		}
		printf("写入数据成功，写入的数据大小是：%d\n",res);
	}
	//3.关闭文件
	close(fd);
	return 0;
}
