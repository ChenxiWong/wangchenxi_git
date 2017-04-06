//使用fcntl函数给文件进行加锁
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
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 5;
	lock.l_pid = -1;
	//3.给文件加锁，占用20秒
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res)
	{
		perror("fcntl"),exit(-1);
	}
	printf("加锁成功，开始占用文件...\n");
	sleep(20);
	printf("占用文件结束，开始释放锁\n");
	//4.给文件解锁，占用20秒
	lock.l_type = F_UNLCK;
	res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res)
	{
		perror("fcntl"),exit(-1);
	}
	printf("解锁成功，20秒之后进程结束\n");
	sleep(20);
	printf("进程结束\n");
	//5.关闭文件
	close(fd);
	return 0;
}

