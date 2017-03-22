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

int main(int argc, char* argv[])
{
    const char* pattern = argv[1];
    int size = strlen(pattern);
    int* arry = new int[size];
    memset(arry, 0, size*sizeof(int));
    get_next_arry(arry, size, pattern);
    for(int i = 0; i < size; ++i)
    {
        printf(" %d ", arry[i]);
    }
    printf(" \n ");
}
