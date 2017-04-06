// Last Update:2017-03-07 09:48:26
/**
 * @file time_test.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-07
 */
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
    time_t timep;
    time(&timep);
    printf("%s", ctime(&timep));
}
