// Last Update:2017-03-22 14:52:40
/**
 * @file get_next_arry.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-22
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void get_next_arry(int* arry, const int num, const char* str)
{
    int j = 1;
    arry[j-1] = 0;
    ++j;
    arry[j-1] = 1;
    int tmp = arry[j-1];
    ++j;
    for(;j<= num ; ++j)
    {
        if(str[tmp -1] == str[j -2])
        {
            ++tmp;
        }else
            tmp = 1;
        arry[j-1] = tmp;
    }
}

const char*mystrstr(const char* p,int size,int* arry,const char* pattern)
{
    int pos = 0;
    int tmp = 0;
    int len = strlen(pattern);
    const char* p_tmp = pattern;
    while(*(p + tmp) != 0 )
    {
        if ((p_tmp + tmp) >= (pattern + len ))
        {
            return NULL;
        }
        if(*(p + tmp) != *(p_tmp + tmp))
        {
            if( tmp != 0 )
            {
                p_tmp += *(arry + tmp);
                tmp = 0;
                continue;
            }
            else
            {
                ++p_tmp;
            }
        }
        ++ tmp;
    }
    if(*(p + tmp) == 0)return p_tmp;
    return NULL;
}

int main(int argc, char* argv[])
{
    const char* pattern = argv[1];
    int size = strlen(pattern);
    int* arry = new int[size];
    memset(arry, 0, size*sizeof(int));
    //得到next[]   还有进一步优化的余地
    get_next_arry(arry, size, pattern);
    //怎么使用next[]??
    const char* pos = mystrstr(pattern, size, arry, argv[2]);
    if(pos != NULL)
    {
        printf(" %s .\n", pos);
    }
    for(int i = 0; i < size; ++i)
    {
        printf(" %d ", arry[i]);
    }
    printf(" \n ");
}


