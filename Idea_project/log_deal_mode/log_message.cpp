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
