// Last Update:2017-04-19 16:28:04
/**
 * @file map_test.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-19
 */
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
    map<int, int> m;
    m[1] = 10;
    int* p = &m[1];
    *p = 20;
    cout<<m[1] <<endl;
}
