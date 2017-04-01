// Last Update:2017-03-30 17:26:17
/**
 * @file log_message.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */

#include "commit_tools.h"
#include "log_message.h"
#include <string>
using std::string;

log_message::log_message(){}

log_message::log_message(char* c_ID, char* c_time_str, char* c_host_name,char* c_jscon_value ):m_jscon_value(c_jscon_value),m_host_name(c_host_name),m_time_str(c_time_str),m_ID(c_ID)
{
    replace_all(m_jscon_value, "#012", "");
    replace_all(m_jscon_value, " ", "");
    sign = true;
}

log_message::log_message(const bool tmp_b)
{
    sign = tmp_b;
}

bool log_message::get_member_str(string& dst_str, string& which_str)
{
    if(which_str == "m_jscon_value")
    {
        dst_str = m_jscon_value;
    }
    else if(which_str == "m_host_name")
    {
        dst_str = m_host_name;
    }
    else if(which_str == "m_time_str")
    {
        dst_str = m_time_str;
    }
    else if(which_str == "m_ID")
    {
        dst_str = m_ID;
    }
    else
    {
        return false;
    }
    return true;
}
