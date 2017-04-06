//使用标C文件函数实现数据的写入
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//1.打开/创建文件
	FILE* fp = fopen("num.dat","wb");
	if(NULL == fp)
	{
		perror("fopen"),exit(-1);
	}
	//2.写入数据
	int i = 0;
	for(i = 1; i <= 1000000; i++)
	{
		fwrite(&i,sizeof(int),1,fp);
	}
	//3.关闭文件
	fclose(fp);
	return 0;
}
