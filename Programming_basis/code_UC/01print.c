//编程打印任意一句话
#include <stdio.h>

int main(void)
{
	printf("世界那么大，我想去看看\n");
	int i = 2;
	// 永远为真 5 < i && i < 100;
	if(5 < i < 100)
	{
		printf("%d在1到100之间\n",i);
	}

	show();
	//return 0;
}

void show(void)
{
	printf("钱包那么小，哪也去不了\n");
}





