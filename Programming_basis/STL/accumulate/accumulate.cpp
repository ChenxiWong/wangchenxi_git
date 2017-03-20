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
    int i_arry_second[13] = {1,22,3,11,22,33,4,22,6,77,88,22,100};
    vector<int> i_vec_second(i_arry_second+0, i_arry_second+13);
    vector<int>::iterator it = i_vec.begin();
    while((it = find_first_of(it, i_vec.end(),i_vec_second.begin(), i_vec_second.end())) != i_vec.end()) //the usage of find_first_of.
    {
        ++cnt;
        ++it;
    }
    cout<<" Found "<<cnt<<" mem in both vector ！"<<endl;
    int sum = accumulate(i_vec.begin(), i_vec.end(), 0); //the usage of accumulate.
    cout<<"ivector first sum = "<<sum<<endl;

    cnt = 0;
    fill(i_vec_second.begin(), i_vec_second.end(), 0);
    cnt = count(i_vec_second.begin(), i_vec_second.end(), 22);// the usage of count

    fill_n(i_vec_second.begin(), 10, 22);// the usage of fill_n

    fill_n(back_inserter(i_vec_second), 10, 22); //the usage of back_inserter

    cnt = count(i_vec_second.begin(), i_vec_second.end(), 22);
    cout<<"the num of 22 in i_vec_second is "<<cnt<<endl;

    //vector<int> i_vec_third(i_vec.begin(), i_vec.end());// 这个方法存在比较隐蔽的问题，谨慎使用。
    vector<int> i_vec_third(i_vec);
    copy(i_vec.begin(), i_vec.end(), i_vec_third.begin()); // the usage of copy

    vector<int> ivec_tmp;
    replace_copy(i_vec_third.begin(), i_vec_second.end(),back_inserter(ivec_tmp), 0, 10);
    replace(i_vec_third.begin(), i_vec_third.end(),0, 10);

    cnt = count(i_vec_third.begin(), i_vec_third.end(), 10);
    cout<<"the num of 10 in i_vec_second is "<<cnt<<endl;
}
