// Last Update:2016-12-09 11:14:30
/**
 * @file main.c
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-12-09
 */
#include<stdio.h>

typedef signed char int8_t;
typedef unsigned char   uint8_t;
typedef short  int16_t;
typedef unsigned short  uint16_t;
typedef int  int32_t;
typedef unsigned   uint32_t;
typedef long long  int64_t;
typedef unsigned long long   uint64_t;

int main(int argc, char* argv[])
{
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(int8_t) = %d\n", sizeof(int8_t));
    printf("sizeof(uint8_t) = %d\n", sizeof(uint8_t));
    printf("sizeof(int16_t) = %d\n", sizeof(int16_t));
    printf("sizeof(uint16_t) = %d\n", sizeof(uint16_t));
    printf("sizeof(int32_t) = %d\n", sizeof(int32_t));
    printf("sizeof(uint32_t) = %d\n", sizeof(uint32_t));
    printf("sizeof(int64_t) = %d\n", sizeof(int64_t));
    printf("sizeof(uint64_t) = %d\n", sizeof(uint64_t));
}
