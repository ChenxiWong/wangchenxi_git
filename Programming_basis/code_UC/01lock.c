//使用fcntl函数给文件加锁
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	printf("pid = %d\n",getpid());
	//1.打开文件
	int fd = open("a.txt",O_RDWR);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	//2.准备一把锁
	struct flock lock;
	//lock.l_type = F_RDLCK;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 5;
	lock.l_pid = -1;
	//3.使用fcntl加锁，占用20秒
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res)
	{
		perror("fcntl"),exit(-1);
	}
	printf("加锁成功，正在使用文件...\n");
	sleep(20);
	printf("使用文件结束，进程结束\n");
	//4.关闭文件
	close(fd);
	return 0;
}


