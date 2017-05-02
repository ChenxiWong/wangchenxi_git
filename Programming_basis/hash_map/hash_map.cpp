// Last Update:2017-04-13 14:35:00
/**
 * @file hash_map.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-13
 */
#include <ext/hash_map>
#include<string>
#include<iostream>
#include<time.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <map>
using namespace __gnu_cxx;
using std::string;
using std::pair;
using std::cout;
using std::endl;
using std::map;
namespace __gnu_cxx
{
    template<> struct hash<string>
    {
        size_t operator()(const string& s) const
        {
            return __stl_hash_string(s.c_str());
        }
    };
}
#define MAP hash_map

int main()
{
    char arry[60];
    long n=0;
    clock_t start,finish;
    MAP<int, int> hh;
    vector<string> vec;
    vec.reserve(100000000);
    unsigned long long  i = 0;
    for(;i != 100000000; ++i)
    {
        memset(arry, 0, 60);
        sprintf(arry,"%lld%lld%lld%lld", i,i,i,i);
        vec.push_back(string(arry));
    }

    start=clock();
    MAP<string, unsigned long long> hm;
    for(vector<string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        hm[*iter] = i;
    }
    finish=clock();
    cout<<(finish-start)/CLOCKS_PER_SEC<<endl;
    cout<<(finish-start)<<endl;
    cout<<hm["123123123123"]<<endl;



    /* 其它使用MAP的代码 */

}
