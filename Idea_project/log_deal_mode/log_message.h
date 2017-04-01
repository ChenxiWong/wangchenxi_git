// Last Update:2017-03-30 17:09:46
/**
 * @file log_message.h
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */

#ifndef LOG_MESSAGE_H
#define LOG_MESSAGE_H
#include "commit_tools.h"
#include <string>
using std::string;

class log_message
{
    private:
        string m_jscon_value;
        string m_host_name;
        string m_time_str;
        string m_ID;
        bool sign;
    public:
        log_message(){}
        virtual ~log_message()
        {
        }
        log_message(char* c_ID, char* c_time_str, char* c_host_name,char* c_jscon_value ):m_jscon_value(c_jscon_value),m_host_name(c_host_name),m_time_str(c_time_str),m_ID(c_ID){
            replace_all(m_jscon_value, "#012", "");
            replace_all(m_jscon_value, " ", "");
            sign = true;
        }
        log_message(const bool tmp_b):sign(tmp_b){}
        bool get_member_str(string& dst_str, string& which_str);
};


#endif  /*LOG_MESSAGE_H*/
