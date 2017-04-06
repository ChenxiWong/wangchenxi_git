//使用F_SETLKW进行加锁
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
	//2.准备一把锁
	struct flock lock;
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 5;
	lock.l_pid = -1;
	//3.使用fcntl函数加锁
	int res = fcntl(fd,F_SETLKW,&lock);
	if(-1 == res)
	{
		perror("fcntl"),exit(-1);
	}
	printf("那边总算把锁释放了，加锁成功\n");
	//4.关闭文件
	close(fd);
	return 0;
}

