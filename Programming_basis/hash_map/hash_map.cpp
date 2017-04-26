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
using namespace __gnu_cxx;
using std::string;
using std::pair;
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

int main()
{

    hash_map<string, int> hm;
    hm["hello"] = 100 + hm["hello"];
    std::cout<<hm["hello"]<<std::endl;
    for(hash_map<string, int>::iterator iter = hm.begin();
            iter != hm.end(); ++iter)
    {
        iter += 100;
    }

    /* 其它使用hash_map的代码 */

}
