// Last Update:2016-08-10 16:37:50
/**
 * @file test.cpp
 * @brief 测试函数指针的使用方法
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-08-10
 */
#include <iostream>
using namespace std;
typedef void (* FUNC_HANDLE)(int );
void test_handle (int int_temp)
{
    cout<<"Hello, world!"<<endl;
    cout<<" The num is "<< int_temp<<endl;
    cout.flush();
}
int main(void)
{
    int i = 100;
    FUNC_HANDLE func_tmp = test_handle;
    func_tmp(i);
    return 0;
}
