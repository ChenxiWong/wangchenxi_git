// Last Update:2017-03-30 15:20:30
/**
 * @file produce_handle.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */

#include "wyxstd.h"
#include "handle.h"
#include "json/json.h"
#include "jscon_parse.h"

add_handle::add_handle()
{
}

bool add_handle::handle_getopt()
{
}

bool add_handle::run(log_message* p_msg)
{
    if(!(m_b_f && get_value_from_map(m_str_f_dst, m_str_f)))
    {
        PrintForDebug("get value from map faile");
        return false;
    }
}

bool jscon_parse_handle::get_value_from_jscon_str(string& dst_str, string& src_str)
{
    Json::Reader reader;
    Json::Value root;
    reader.parse( (char*)(dst_str.c_str()), root);
    dst_str = json_key_value(root, src_str) ;
    return true;
}

jscon_parse_handle::jscon_parse_handle()
{
}

bool jscon_parse_handle::handle_getopt()
{
}

bool jscon_parse_handle::run(log_message* p_msg)
{
    if(!(m_b_g && p_msg->get_member_str( m_str_g_dst, m_str_g)))
    {
        PrintForDebug("get value from message faile");
        return false;
    }
    if(!(m_b_a && get_value_from_jscon_str(m_str_g_dst, m_str_a)))
    {
        PrintForDebug("get value from jscon_str faile");
        return false;
    }
    if(!(m_b_t && insert_kv_to_map( m_str_t, m_str_a_str)))
    {
        PrintForDebug("insert value to map faile");
        return false;
    }
    return true;
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
    else if( tmp_str == "jscon_parse")
    {
        handle* p_handle = new jscon_parse_handle();
    }
}
