// Last Update:2016-08-30 19:11:25
/**
 * @file main.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-08-30
 */
#include "./wyxstd.h"
int main(void)
{
    string str_tmp("0123456789");
    cout<<str_tmp[4]<<endl;
    str_tmp[4] = 'f';
    cout<<str_tmp[4]<<endl;
    cout<<str_tmp.size()<<endl;
    cout<<str_tmp[str_tmp.size()]<<endl;
    cout<<str_tmp[str_tmp.size() -1]<<endl;
    cout<<str_tmp<<endl;
    char c_arry[100];
    memset(c_arry, 0, 100);
    str_tmp.copy(c_arry, str_tmp.find('6'));
    string str(c_arry);
    cout<<str<<endl;
}
