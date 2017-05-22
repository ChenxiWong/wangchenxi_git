// Last Update:2017-05-22 15:42:14
/**
 * @file define.c
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-05-22
 */

#include <stdio.h>

#define test(a) \
    do \
    { \
        init_ ##a (); \
    } while(0)
#define print(a,b) \
    do \
    { \
        printf(#a "=%07d ," #b "=%07f .\n", a, b); \
        printf(#a "=%7d ," #b "=%7f .\n", a, b); \
        printf(#a "=%-7d ," #b "=%-7f .\n", a, b); \
    }while(0)




int i = 100;
float f = 1.22;


void init_i()
{
    i = 0;
}
void init_f()
{
    f = 0;
}

int main(int argc, char* argv)
{
    print(i,f);
    test(i);
    test(f);
    print(i,f);
}
