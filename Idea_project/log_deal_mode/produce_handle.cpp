// Last Update:2017-03-30 15:20:30
/**
 * @file produce_handle.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */
#include "handle.h"

add_handle::add_handle(){}

bool add_handle::run(log_message* p_msg)
{
}

produce_handle::produce_handle()
{
}
handle* produce_handle::produce_handle_pointer(string& tmp_str)
{
    if( tmp_str == "add")
    {
        handle* p_handle = new add_handle();
        return p_handle;
    }
    else if()
    {
    }
}
