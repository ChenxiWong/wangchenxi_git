// Last Update:2017-05-22 16:54:12
/**
 * @file var_arg.c
 *
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-05-22
 */

//
// main.c
// 自定义多参数函数
//
// Created by MacroHong on 14-2-19.
// Copyright (c) 2014年 Macro. All rights reserved.
//
#include <stdio.h>
//#include <stdarg.h>
//#include <limits.h>
/**
 * 求不定个参数的和
 *
 * @param count 不定参数的个数
 * @param ... 不定参数的列表
 *
 * @return 返回不定参数列表的和
 */
int sum(int count, ...) {
    int sum = 0;
    int i = 0;
    __builtin_va_list vaptr;//相当于一种指针
    __builtin_va_start(vaptr, count);//指向某块内存地址
    for (i = 0; i < count; i++) {
        sum += __builtin_va_arg(vaptr, int);//将指针指向的内存数据转换成指定数据类型
    }
    __builtin_va_end(vaptr);//指针归零
    return sum;
}
/**
 * 求不定个参数的和
 *
 * @param count 不定参数的个数
 * @param ... 不定参数的列表
 *
 * @return 返回不定参数列表的和
 */
double sumDouble(int cnt, ...) {
    double sum = 0.0;
    int i = 0;
    __builtin_va_list vaptr;
    __builtin_va_start(vaptr, cnt);
    for (i = 0; i < cnt; i++) {
        sum += __builtin_va_arg(vaptr, double);
    }
    return sum;
}
/**
 * 打印指定多个字符串
 *
 * @param cnt 字符串个数
 * @param ... 字符串列表
 */
void printStrings(const int cnt, ...) {
    int i = 0;
    __builtin_va_list vaptr;//定义一个指针型变量
    __builtin_va_start(vaptr, cnt);//将变量赋值
    for (i = 0; i < cnt; i++) {
        printf("%s ", __builtin_va_arg(vaptr, char  *));//指针指向的数据转换成指定数据类型
        //vprintf("%s ", vaptr);//和上一行只要一行
    }
    printf("\n");
    __builtin_va_end(vaptr);//指针归零
}
int main(int argc, const char  * argv[])
{
    //打印字符串
    printStrings(4, "My", "name", "is", "Macro!!!!!");

    //求int型数据和
    int ret = sum(6, 1,2,3,4,5,6);
    printf("%d\n", ret);

    //求double型数据和
    printf("%g\n", sumDouble(4, 1.2, 4.3, 2.1, 6.7));

    return 0;
}
