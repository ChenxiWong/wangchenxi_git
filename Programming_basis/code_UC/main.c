#include "circle.h"

int main(void)
{
	double r = 0;
	printf("请输入一个半径：\n");
	scanf("%lf",&r);
	printf("圆的周长是：%lf,圆的面积是：%lf\n",length(r),area(r));
	return 0;
}



