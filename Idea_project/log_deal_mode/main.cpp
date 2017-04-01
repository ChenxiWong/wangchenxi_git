// Last Update:2017-03-30 13:07:41
/**
 * @file main.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */
#include <iostream>
#include <unistd.h>
#include "log_analysiser.h"

int main(int argc , char* argv[])
{
    log_analysiser analysiser("./log_analysiser_config.xml");
    analysiser.analysis();
}




