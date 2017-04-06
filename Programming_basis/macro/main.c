// Last Update:2016-09-12 11:19:30
/**
 * @file main.c
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-09-12
 */
#include<stdio.h>
#define DEBUG

#define PrintForDebug(code)  HereIsDebug(code, __FILE__, __LINE__, __func__, __DATE__, __TIME__)

//调试宏定义
#ifdef DEBUG
#define DBGCODE(code);  code
#else
#define DBGCODE(code);
#endif

void HereIsDebug(const char* strerr, const char* file, int line, const char* func, const char* date, const char* time )
{
    printf("Error occured in file:%s , line:%d .\n", file, line);
    printf("The final compilation of %s happend at %s in %s .\n", file, time, date);
    printf("Author-defined error TIP is \" %s \" .\n", strerr);
}


int main(int argc, char* argv[])
{
    DBGCODE
    (
        printf("__FILE__ = %s \n", __FILE__);
        printf("__LINE__ = %d \n", __LINE__);
        printf("__func__ = %s \n", __func__);
        printf("__DATE__ = %s \n", __DATE__);
        printf("__TIME__ = %s \n", __TIME__);
    );
    PrintForDebug("hello, world!");
}
