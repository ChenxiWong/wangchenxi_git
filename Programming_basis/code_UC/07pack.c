//设置结构体的对齐和补齐方式
#include <stdio.h>

//设置结构体按照2的整数倍进行对齐补齐
//#pragma pack(2) //8
//#pragma pack(1) //6 
//#pragma pack(3) //error 
//char short int long int  long long

int main(void)
{
	struct S
	{
		char c1;
		int i;
		char c2;
	};
	printf("sizeof(struct S) = %d\n",sizeof(struct S));//12
	return 0;
}
