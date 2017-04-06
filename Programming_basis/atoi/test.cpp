// Last Update:2016-09-10 10:02:46
/**
 * @file test.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-09-10
 */
#include <stdlib.h>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char* argv[])
{
    uint16_t pid;
    char* pc = "65536";
    pid = atoi(pc);
    cout<<pid<<endl;
    cout<<sizeof(pid)<<endl;
}
