//写入员工信息到文件中
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//员工信息结构体定义
typedef struct
{
	int id;//员工编号
	char name[20];//员工姓名
	double salary;//员工薪水
}Emp;

int main(void)
{
	//1.打开/创建文件
	int fd = open("emp.dat",O_WRONLY|O_CREAT|O_EXCL,0644);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.写入员工信息到文件中
	Emp emp = {1001,"zhangfei",3000};
	//格式化写入字符串
	char buf[100] = {0};
	sprintf(buf,"%d%s%lf",emp.id,emp.name,emp.salary);
	//int res = write(fd,buf,sizeof(buf));
	int res = write(fd,buf,strlen(buf));
	if(-1 == res)
	{
		perror("write"),exit(-1);
	}
	printf("写入数据成功，数据的大小是:%d\n",res);
	//3.关闭文件
	close(fd);
	return 0;
}
