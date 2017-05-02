// Last Update:2017-04-28 17:03:05
/**
 * @file print.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-28
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
int main(int argc, char* argv[])
{
    uint32_t abc = 123;
    uint64_t bcd = 45006758100;
    //printf("%I32u\n", abc);
    //printf("%u\n", abc);
    //printf("%d\n", abc);
    char buffer[300];
    memset(buffer, 0, 300);
    sprintf(buffer, "%u %lu", abc, bcd);
    printf("%s\n", buffer);
}
