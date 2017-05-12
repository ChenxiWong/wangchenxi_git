// Last Update:2017-05-11 17:06:55
/**
 * @file reverseOrder.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-05-11
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    string src_str("");
    string dst_str("");
    string tmp_str("");
    cout<<"Please input a string : ";
    getline(cin, src_str);
    cout<<"The string is "<<src_str<<endl;
    while( 1)
    {
        string::size_type pos = src_str.find(' ');
        tmp_str=src_str.substr(0, pos);
        dst_str = tmp_str + " " + dst_str;
        if(pos == string::npos)break;
        src_str = src_str.substr(pos+1);
    }
    cout<<"dst_str is "<<dst_str<<endl;
}
