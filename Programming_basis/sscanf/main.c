// Last Update:2016-09-12 10:18:38
/**
 * @file main.c
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-09-12
 */
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
    char* c_str = "wangchenxi  181";
    char name[32];
    memset(name, 0, 32);
    int hight = 0;
    sscanf(c_str, "%s %d", name, &hight);
    printf(" My name is %s , hight is %d . \n", name, hight);
}
