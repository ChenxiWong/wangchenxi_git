// Last Update:2017-05-11 17:06:55
/**
 * @file reverseOrder.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-05-11
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Mathod1{
    int Mathod_main(int argc, char* argv[])
    {
        // src tmp dst  init
        string src_str("");
        string dst_str("");
        string tmp_str("");
        // input src
        cout<<"Please input a string : ";
        getline(cin, src_str);
        cout<<"src_str is "<<src_str<<endl;
        // start while loop
        while( 1)
        {
            // find blank
            string::size_type pos = src_str.find(' ');
            // true
            if(pos != string::npos)
            {

                // get one word from src assign to tmp 
                tmp_str=src_str.substr(0, pos);
                // form dst
                dst_str = tmp_str + " " + dst_str;

            }
            // false
            else {

                // may be the last
                dst_str = src_str + " " + dst_str;
                break;

            }

            // substr src
            //if final charactor is space
            if( pos == (src_str.size() - 1))
            {
                dst_str = " " + dst_str;
                break;
            }
            // not space
            else
            {
                src_str = src_str.substr(pos+1);
            }

        }
        cout<<"dst_str is "<<dst_str<<endl;
    }
}

namespace Mathod2{
    int Mathod_main(int argc, char* argv[])
    {
        // src tmp dst  init
        string src_str("");
        string dst_str("");
        string tmp_str("");
        // input src
        cout<<"Please input a string : ";
        getline(cin, src_str);
        cout<<"src_str is "<<src_str<<endl;
        // start while loop
        while( 1)
        {
            // find blank
            string::size_type pos = src_str.find(' ');
            // true
            if(pos != string::npos)
            {
                // get one word from src assign to tmp 
                tmp_str=src_str.substr(0, pos);
                // form dst
                dst_str = tmp_str + " " + dst_str;
                // substr src
                src_str = src_str.substr(pos+1);
                //if final charactor is space
                if(src_str.empty())
                {
                    dst_str = " " + dst_str;
                    break;
                }

            }
            // false
            else {
                // may be the last
                dst_str = src_str + " " + dst_str;
                break;
            }

        }
        cout<<"dst_str is "<<dst_str<<endl;
    }
}

namespace Mathod3{
    int Mathod_main(int argc, char* argv[])
    {
        // src dst vec
        string src_str(""), dst_str("");
        std::vector<string> vec;
        // input src
        cout<<"Please input a string (end with Enter): ";
        getline(cin, src_str);
        cout<<"src_str is "<<src_str<<endl;
        // while loop
        while(1)
        {
            // find space
            string::size_type pos = src_str.find(' ');
            // true
            if(pos != string::npos)
            {
                // get one word from src push_back to vec
                vec.push_back(src_str.substr(0, pos));
                // src substr
                src_str = src_str.substr(pos + 1);
                // empty()? the last charactor is space
                if(src_str.empty())
                {
                    // push_back one "" to vec and break
                    vec.push_back("");
                    break;
                }
            }
            // false
            else{
                // may be the last push_back to vec and break
                vec.push_back(src_str);
                break;
            }
        }
        // orgnization dst
        for(vector<string>::reverse_iterator iter = vec.rbegin();
                iter != vec.rend(); ++iter)
        {
            dst_str += *iter;
            dst_str += " ";
        }
        // cout dst
        cout <<"dst_str is "<<dst_str<<endl;
    }
}





int main(int argc, char* argv[])
{
    return Mathod3::Mathod_main(argc, argv);
}
