// Last Update:2017-05-08 15:17:43
/**
 * @file test.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-05-08
 */
#include <iostream>
#include <vector>
using namespace std;

void print (std::initializer_list<int> values)
{
    for(auto i : values)
    {
        cout<<i<<endl;
    }
}

template <typename T>
void printElements ( const T& coll)
{
    for(const auto& elem : coll)
    {
        cout<<elem<<endl;
    }
}


int main(int argc, char* argv[])
{
    for(auto i : {1,2,3,4,5,6,7,8,9,10})
    {
        cout<<i<<endl;
    }
    print({1,2,3,4,5,6,7,8,9,10});
    vector<int> vec({1,2,3,4,5,6,7,8,9,10});
    printElements(vec);
}



