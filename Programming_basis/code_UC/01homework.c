//使用sbrk函数和brk函数操作内存
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int* pi =(int*)sbrk(sizeof(int));
	*pi = 100;
	double* pd = (double*)sbrk(sizeof(double));
	*pd = 3.1415926;
	char* pc = (char*)sbrk(10*sizeof(char));
	strcpy(pc,"hello");
	
	printf("*pi = %d,*pd = %lf,pc = %s\n",*pi,*pd,pc);
	//释放所有的内存
	brk(pi);
	return 0;
}
