// Last Update:2017-03-30 14:45:00
/**
 * @file handle.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */

#include "handle.h"
#include <cstring>
#include <vector>
#include <map>
using std::vector;
using std::map;

handle::handle()
{
    m_argv = NULL;
    m_p_c = NULL;
}
handle::handle(const handle& p_handle)
{
    m_argc = p_handle.m_argc;
    m_argv = new char*[m_argc];
    memset(m_argv, 0, m_argc * sizeof(char*));
    memcpy(m_argv, p_handle.m_argv, m_argc * sizeof(char*));
    m_p_c = new char[p_handle.m_arg_str.size()+1];
    memset(m_p_c, 0, p_handle.m_arg_str.size()+1);
    memcpy( m_p_c, p_handle.m_p_c, p_handle.m_arg_str.size());
    m_arg_str = p_handle.m_arg_str;
    m_p_map = p_handle.m_p_map;
    p_log_message = p_handle.p_log_message;
}
handle& handle::operator= (const handle& p_handle)
{
    m_argc = p_handle.m_argc;
    m_argv = new char*[m_argc];
    memset(m_argv, 0, m_argc * sizeof(char*));
    memcpy(m_argv, p_handle.m_argv, m_argc * sizeof(char*));
    m_p_c = new char[p_handle.m_arg_str.size()+1];
    memset(m_p_c, 0, p_handle.m_arg_str.size()+1);
    memcpy( m_p_c, p_handle.m_p_c, p_handle.m_arg_str.size());
    m_arg_str = p_handle.m_arg_str;
    m_p_map = p_handle.m_p_map;
    p_log_message = p_handle.p_log_message;
    return *this;
}
void handle::str2argv()
{
    int len = m_arg_str.size();
    m_p_c = new char[len + 1];
    memset(m_p_c, 0, len+1);
    strcpy(m_p_c, m_arg_str.c_str());
    vector<char*> c_vec;
    while(1)
    {
        if( *m_p_c == 0)break;
        if(*m_p_c == ' ')
        {
            *m_p_c = 0;
        }else
        {
            if(*(m_p_c - 1) == 0)
            {
                c_vec.push_back(m_p_c);
            }
        }
        ++m_p_c;
    }
    int m_argc = c_vec.size();
    m_argv =(char**) new char*[m_argc];
    memset(m_argv, 0, m_argc * sizeof(char*));
    for(vector<char*>::size_type ix = 0; ix != c_vec.size(); ++ix)
    {
        m_argv[ix] = c_vec[ix];
    }
}

void handle::set_m_arg_str(string& tmp_str)
{
    m_arg_str = tmp_str;
}

void handle::set_m_p_map(map<string, string>* p_map)
{
    m_p_map = p_map;
}
void handle::init_handle(string& tmp_str, map<string, string>* p_map)
{
    set_m_arg_str(tmp_str);
    set_m_p_map(p_map);
    str2argv();
}

bool handle::get_value_from_map(string& str_value, string& str_key)
{
    map<string, string>::iterator iter = m_p_map->find(str_key);
    if( iter != m_p_map->end())
    {
        str_value = iter->second;
        return true;
    }
    return false;
}

bool handle::insert_kv_to_map(string& str_key, string& str_value)
{
    (*m_p_map)[str_key] = str_value;
    return true;
}


