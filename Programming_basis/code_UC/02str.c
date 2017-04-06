//字符串存储形式的比较
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	//pc存储字符串的首地址,不能存内容
	//pc指向只读常量区
	//pc本身在栈区
	char* pc = "hello";
	//str存储字符串的内容，而不是地址
	//str指向栈区
	//str本身在栈区
	// 将字符串内容拷贝一份到字符数组
	char str[] = "hello";

	printf("字符串的首地址：%p\n","hello");
	printf("pc = %p\n",pc);
	printf("&pc = %p\n",&pc);
	printf("str = %p\n",str);
	printf("&str = %p\n",&str);
	
	printf("-------------------\n");
	//修改指向
	pc = "1234"; //ok
	//str = "1234"; //error
	//修改指向的内容
	//*pc = 'A'; // error
	//str[0] = 'A';
	*str = 'A'; // ok
	
	printf("------------------\n");
	//堆区申请的动态内存
	char* ps = (char*)malloc(10);
	//修改指向内容
	strcpy(ps,"hello"); //ok
	//修改指向
	char* p = ps;
	ps = "Good"; // ok 
	//释放动态内存
	free(p);
	p = NULL;
	return 0;
}



