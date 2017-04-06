// Last Update:2016-11-17 09:04:04
/**
 * @file main.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-11-17
 */
#include <iostream>
using namespace std;

class A 
{
    public:
        int arr[4000];
};

class B :public A
{
    public:
        int brr[2000];
};

void* hello_test(A* tmp_p_a)
{
    //delete tmp_p_a;
}

int main(void)
{
    while(1)
    {
        B* p_b = new B();
        hello_test(p_b);
    }
}
