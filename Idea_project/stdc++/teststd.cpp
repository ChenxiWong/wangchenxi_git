// Last Update:2017-04-23 15:51:43
/**
 * @file teststd.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-23
 */

#include "teststd.h"

int main(int argc, char* argv[])
{
    time_t tt = time(NULL);
    char* p = ctime(&tt);
    printf("time_t = %ld, time_str= %s", tt, p);
}
