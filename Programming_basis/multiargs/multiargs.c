// Last Update:2017-04-06 10:15:53
/**
 * @file multiargs.c
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-06
 */
#include "stdio.h"
#include "stdarg.h"

#define make_em_a_string(...) #__VA_ARGS__

void simple_va_fun(const char* start, ...)
{
    va_list arg_ptr;
    const char* nArgValue = start;
    int nArgCout=0;      //可变参数的数目
    va_start(arg_ptr,start); //以固定参数的地址为起点确定变参的内存起始地址。
    do {
        ++nArgCout;
        printf("the %d th arg: %s\n",nArgCout,nArgValue);      //输出各参数的值
        nArgValue = va_arg(arg_ptr, const char*);                     //得到下一个可变参数的值
    } while(nArgValue != NULL);
    return;
}
int main(int argc, char* argv[])
{
    simple_va_fun("100","-1", NULL);
    simple_va_fun("100","200","-1", NULL);
    printf("%s\n",make_em_a_string("string","string1","string2","string3","string4"));
    printf("%s\n",make_em_a_string(a,b,c,e,f,g));
    return 0;
}
