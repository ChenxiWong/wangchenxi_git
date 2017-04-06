// Last Update:2017-03-30 11:45:07
/**
 * @file find_first_of.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string tmp_str = "./a.out -1 123 -d ";
    string::size_type pos;
    //if((pos = tmp_str.find_first_of("1234")) != string::npos)
    if((pos = tmp_str.find("1234")) != string::npos)
    {
        cout<<"find!"<<endl;
    }
}
