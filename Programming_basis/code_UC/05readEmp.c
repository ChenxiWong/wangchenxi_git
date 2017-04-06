//读取文件中的员工信息
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//定义员工的数据类型
typedef struct
{
	int id;
	char name[20];
	double salary;
}Emp;

int main(void)
{
	//1.打开文件
	int fd = open("emp.dat",O_RDONLY);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.读取文件中的内容，进行打印
	Emp emp = {0};
	int res = read(fd,&emp,sizeof(emp));
	if(-1 == res)
	{
		perror("read"),exit(-1);
	}
	printf("读取到的员工信息：%d,%s,%lf\n",emp.id,emp.name,emp.salary);
	//3.关闭文件
	close(fd);
	return 0;
}
