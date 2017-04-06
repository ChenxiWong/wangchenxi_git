//共享库文件的动态加载
#include <stdio.h>
#include <dlfcn.h>

int main(void)
{
	//1.打开共享库文件
	void* handle = dlopen("./shared/libadd.so",RTLD_NOW/*立即加载*/);
	//2.判断是否出错
	char* error = dlerror();
	if(error != NULL)
	{
		printf("打开共享库文件失败\n");
		return -1;//出错结束
	}
	//3.获取共享库中函数的地址
	int (*add_pint)(int ia,int ib);
	add_pint = dlsym(handle,"add_int");
	//4.判断是否出错
	error = dlerror();
	if(error != NULL)
	{
		printf("获取函数地址失败\n");
		return -1;
	}
	//5.使用共享库中的函数
	int res = add_pint(40,50);
	printf("res = %d\n",res);
	//6.关闭共享库文件
	dlclose(handle);
	return 0;
}
