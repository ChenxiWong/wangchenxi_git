// Last Update:2017-04-20 10:25:46
/**
 * @file main.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-20
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

typedef int Arry[2];
typedef char CA[20];

struct TArry
{
    Arry a;
};

int main(int argc, char* argv[])
{
    TArry t;
    t.a[0] =1;
    t.a[1] =2;
    char buffer[20] ="hello";
    map<string, TArry> test_map;
    test_map.insert(pair<string, TArry>(buffer, t));
    //st_map[string(buffer)] = a;
    cout<<"---"<<test_map[buffer].a[1]<<"---"<<endl;
    Arry af;
    af[0] = 1;
    af[1] = 2;
    cout<<af[0]<<endl;
    CA ca[2];
    memset(ca, 0, 40);
    sscanf("hello world", "%s %s", ca[0], ca[1]);
    cout<<string(ca[0])<<endl;
    cout<<string(ca[1])<<endl;
}
