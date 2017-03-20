// Last Update:2017-03-20 14:59:51
/**
 * @file accumulate.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-20
 */
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    int i_arry[11]={0,1,2,3,4,5,6,7,8,9,10};
    size_t cnt = 0;
    vector<int> i_vec(i_arry+0,i_arry+11);
    int i_arry_second[13] = {1,2,3,11,22,33,4,5,6,77,88,99,100};
    vector<int> i_vec_second(i_arry_second+0, i_arry_second+13);
    vector<int>::iterator it = i_vec.begin();
    while((it = find_first_of(it, i_vec.end(),i_vec_second.begin(), i_vec_second.end())) != i_vec.end())
    {
        ++cnt;
        ++it;
    }
    cout<<" Found "<<cnt
        <<" mem in both vector ！"<<endl;
}
