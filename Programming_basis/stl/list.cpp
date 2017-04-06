// Last Update:2016-12-29 09:03:52
/**
 * @file list.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-12-29
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;


template <class T>
void print ( list<T>& l)
{
        list<int>::iterator It = l.begin();
        while(It != l.end())
        {
                cout<< *(It++)<<" ";
        }
        cout << endl;
}


void InsertToList(list<int>& Global_list)
{
        int i = 0;
       // list<int>::iterator It = global_list.begin();
        for(; i < 10; ++i)
        {
                Global_list.push_back(i);
        }
}


int main(int argc, char* argv[])
{
        list<int> global_list;
        InsertToList(global_list);
        print(global_list);
}
