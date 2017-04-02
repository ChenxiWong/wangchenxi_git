// Last Update:2017-04-01 18:39:32
/**
 * @file wyxstd.h
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-01
 */

#ifndef WYXSTD_H
#define WYXSTD_H

#include <cstdio>



#ifdef DEBUG
#define PrintForDebug(code)  HereIsDebug(code, __FILE__, __LINE__, __func__, __DATE__, __TIME__)
#else
#define PrintForDebug(code);
#endif

//调试宏定义
#ifdef DEBUG
#define DBGCODE(code);  code
#else
#define DBGCODE(code);
#endif

void HereIsDebug(const char* strerr, const char* file, int line, const char* func, const char* date, const char* time )
{
    printf("Error occured in file:%s line:%d , while calling function:%s .\n", file, line, func);
    printf("The final compilation of %s happend at %s in %s .\n", file, time, date);
    printf("Author-defined error TIP is \" %s \" .\n", strerr);
}



#endif  /*WYXSTD_H*/