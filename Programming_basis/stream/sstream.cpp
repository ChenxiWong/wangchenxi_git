// Last Update:2016-08-30 17:36:15
/**
 * @file sstream.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-08-30
 */
#include "wyxstd.h"

int main(void)
{
    stringstream sstream_tmp;
    string str_tmp("hello,world!");
    sstream_tmp << str_tmp<<endl;
    string str("");
    getline(sstream_tmp,str);
    //cout<<sstream_tmp.str()<<endl;
    cout<<str<<endl;
    sstream_tmp.seekg(ios::beg);
    str.clear();
    getline(sstream_tmp,str);
    cout<<str<<endl;
    //cout<<sstream_tmp.str()<<endl;
    /*stringstream sstream_tmp1 = sstream_tmp;
    str.clear();
    getline(sstream_tmp1,str);
    cout<<str<<endl;*/
}
