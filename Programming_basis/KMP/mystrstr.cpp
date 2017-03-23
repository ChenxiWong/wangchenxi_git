// Last Update:2017-03-23 14:41:18
/**
 * @file mystrstr.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-23
 */
#include <stdio.h>
#include <iostream>
using namespace std;

const char* mystrstr(const char* p, const char* pattern)
{
    int pos = 0;
    while(*(pattern + pos) != 0)
    {
        int tmp = 0;
        const char* p_tmp = pattern + pos;
        while(*(p + tmp) != 0)
        {
            if(*(p + tmp) != *(p_tmp + tmp))break;
            ++ tmp;
        }
        if(*(p + tmp) == 0)return pattern + pos;
        ++pos;
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    const char* pattern = "1234i56123456123bc123";
    const char* p = "123bc";
    const char* pos = mystrstr(p, pattern);
    printf(" pos = %s.\n", pos);
}
