// Last Update:2017-05-11 18:05:52
/**
 * @file stdc.cpp
 * @brief stdc user
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-05-11
 */
namespace stdc{
/* isblank example */
#include <stdio.h>
#include <ctype.h>
    int stdc_main1 ()
    {
        char c;
        int i=0;
        char str[]="Example sentence to test isblank\n\n";
        while (str[i])
        {
            c=str[i];
            if (isblank(c)) c='\n';
            putchar (c);
            i++;
        }
        return 0;
    }
}

int main(int argc, char* arv[])
{
    return stdc::stdc_main1();
}
