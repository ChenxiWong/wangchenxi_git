// Last Update:2017-03-30 15:20:30
/**
 * @file produce_handle.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */

#include <ctime>
#include <cstring>
#include <cstdlib>

#include "wyxstd.h"
#include "handle.h"
#include "json/json.h"
#include "jscon_parse.h"
#include "produce_handle.h"

add_handle::add_handle()
{
}

bool add_handle::handle_getopt()
{
    return true;
}

bool add_handle::run(log_message* p_msg)
{
    return true;
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
    int ch;
    int* p_optind = & optind;
    *p_optind = 1;
    while ((ch = getopt( m_argc, m_argv, "f:t:a:"))!=-1)
    {
        switch(ch)
        {
            case 'g':
                {
                    m_b_g = true;
                    m_str_g = optarg;
                    break;
                }
            case 'f':
                {
                    m_b_f = true;
                    m_str_f = optarg;
                    break;
                }
            case 't':
                {
                    m_b_t = true;
                    m_str_t = optarg;
                    break;
                }
            case 'a':
                {
                    m_b_a = true;
                    m_str_a = optarg;
                    break;
                }
            default:
                {
                    PrintForDebug("undefined optargs occured!\n");
                    return false;
                }
        }
    }
}

bool jscon_parse_handle::run(log_message* p_msg)
{
    if(m_b_f)
        if(!(get_value_from_map( m_tmp_str, m_str_f)))
        {
            PrintForDebug("get value from map faile");
            m_tmp_str.clear();
            return false;
        }
    if(m_b_a)
        if(!(get_value_from_jscon_str(m_tmp_str, m_str_a)))
        {
            PrintForDebug("get_value_from_jscon_str faile");
            m_tmp_str.clear();
            return false;
        }
    if(m_b_t)
        if(!(insert_kv_to_map( m_str_t, m_tmp_str)))
        {
            PrintForDebug("insert value to map faile");
            m_tmp_str.clear();
            return false;
        }
    m_tmp_str.clear();
    return true;
}


get_handle::get_handle()
{
}

bool get_handle::handle_getopt()
{
    int ch;
    int* p_optind = & optind;
    *p_optind = 1;
    while ((ch = getopt( m_argc, m_argv, "g:t:"))!=-1)
    {
        switch(ch)
        {
            case 'g':
                {
                    m_b_g = true;
                    m_str_g = optarg;
                    break;
                }
            case 't':
                {
                    m_b_t = true;
                    m_str_t = optarg;
                    break;
                }
            default:
                {
                    PrintForDebug("undefined optargs occured!\n");
                    return false;
                }
        }
    }
    return true;
}

bool get_handle::run(log_message* p_msg)
{
    if(m_b_g)
        if(!(p_msg->get_member_str( m_tmp_str, m_str_g)))
        {
            PrintForDebug("get value from message faile");
            m_tmp_str.clear();
            return false;
        }
    if(m_b_t)
        if(!(insert_kv_to_map( m_str_t, m_tmp_str)))
        {
            PrintForDebug("insert value to map faile");
            m_tmp_str.clear();
            return false;
        }
    m_tmp_str.clear();
    return true;
}

filter_handle::filter_handle()
{
}

bool filter_handle::handle_getopt()
{
    int ch;
    int* p_optind = & optind;
    *p_optind = 1;
    while ((ch = getopt( m_argc, m_argv, "f:i:e:"))!=-1)
    {
        switch(ch)
        {
            case 'f':
                {
                    m_b_f = true;
                    m_str_f = optarg;
                    break;
                }
            case 'i':
                {
                    m_b_i = true;
                    m_str_i = optarg;
                    break;
                }
            case 'e':
                {
                    m_b_e = true;
                    m_str_e = optarg;
                    break;
                }
            default:
                {
                    PrintForDebug("undefined optargs occured!\n");
                    return false;
                }
        }
    }
    return true;
}

bool filter_handle::run(log_message* p_msg)
{
    if(m_b_f)
        if(!(get_value_from_map( m_tmp_str, m_str_f)))
        {
            PrintForDebug("get value from map faile");
            m_tmp_str.clear();
            return false;
        }
    if(m_b_e)
        if(m_tmp_str != m_str_e)
        {
            m_tmp_str.clear();
            return false;
        }
    string::size_type pos = string::npos;
    if(m_b_i)
        if((pos = m_tmp_str.find(m_str_i)) == string::npos)
        {
            m_tmp_str.clear();
            return false;
        }
    return true;
}

put_handle::put_handle()
{
}

bool put_handle::handle_getopt()
{
    int ch;
    int* p_optind = & optind;
    *p_optind = 1;
    while ((ch = getopt( m_argc, m_argv, "a:t:"))!=-1)
    {
        switch(ch)
        {
            case 'a':
                {
                    m_b_a = true;
                    m_str_a = optarg;
                    break;
                }
            case 't':
                {
                    m_b_t = true;
                    m_str_t = optarg;
                    break;
                }
            default:
                {
                    PrintForDebug("undefined optargs occured!\n");
                    return false;
                }
        }
    }
    return true;
}

bool put_handle::run(log_message* p_msg)
{
    if(m_b_t && m_b_a)
        if(!(insert_kv_to_map( m_str_t, m_str_a)))
        {
            PrintForDebug("insert value to map faile");
            m_tmp_str.clear();
            return false;
        }
    return true;
}

time_handle::time_handle()
{
}

bool time_handle::handle_getopt()
{
    int ch;
    int* p_optind = & optind;
    *p_optind = 1;
    while ((ch = getopt( m_argc, m_argv, "f:a:t:"))!=-1)
    {
        switch(ch)
        {
            case 'f':
                {
                    m_b_f = true;
                    m_str_f = optarg;
                    break;
                }
            case 'a':
                {
                    m_b_a = true;
                    m_str_a = optarg;
                    break;
                }
            case 't':
                {
                    m_b_t = true;
                    m_str_t = optarg;
                    break;
                }
            default:
                {
                    PrintForDebug("undefined optargs occured!\n");
                    return false;
                }
        }
    }
    return true;
}

static time_t time_str_to_time_num(const char* time_str)
{
    struct tm sTime;
    sscanf(time_str, "%d-%d-%d %d:%d:%d", &sTime.tm_year, &sTime.tm_mon, &sTime.tm_mday, &sTime.tm_hour, &sTime.tm_min, &sTime.tm_sec);
    sTime.tm_year -= 1900;
    sTime.tm_mon -= 1;
    time_t ft=mktime(&sTime);
    return ft;
}

bool time_handle::modulo_operation_of_time(string& dst_str, string& str_a)
{
    int spacing_time = atoi(str_a.c_str());
    struct tm * p_tm;
    time_t clock = time_str_to_time_num(dst_str.c_str());
    clock = clock- (clock % spacing_time);
    p_tm = localtime(&clock);
    char buffer[30];
    memset(buffer, 0, 30);
    strftime(buffer, sizeof(buffer),"%Y-%m-%d %H:%M:%S", p_tm);
    dst_str = buffer;
    return true;
}


bool time_handle::run(log_message* p_msg)
{
    if(m_b_f)
        if(!(get_value_from_map( m_tmp_str, m_str_f)))
        {
            PrintForDebug("get value from map faile");
            m_tmp_str.clear();
            return false;
        }
    if(m_b_a)
        if(!(modulo_operation_of_time(m_tmp_str, m_str_a)))
        {
            PrintForDebug("Modulo Operation of time faile");
            m_tmp_str.clear();
            return false;
        }
    if(m_b_t)
        if(!(insert_kv_to_map( m_str_t, m_tmp_str)))
        {
            PrintForDebug("insert value to map faile");
            m_tmp_str.clear();
            return false;
        }
    m_tmp_str.clear();
    return true;
}

write_cache_handle::write_cache_handle()
{
}

bool write_cache_handle::handle_getopt()
{
    int ch;
    int* p_optind = & optind;
    *p_optind = 1;
    while ((ch = getopt( m_argc, m_argv, "s:v:M:d:t:"))!=-1)
    {
        switch(ch)
        {
            case 'v':
                {
                    m_b_v = true;
                    m_str_v = optarg;
                    m_int_v = atoi(m_str_v.c_str());
                    m_vec.reserve(m_int_v + 1);
                    break;
                }
            case 'M':
                {
                    m_b_M = true;
                    m_str_M = optarg;
                    break;
                }
            case 'd':
                {
                    m_b_d = true;
                    m_str_d = optarg;
                    break;
                }
            case 't':
                {
                    m_b_t = true;
                    m_str_t = optarg;
                    break;
                }
            case 's':
                {
                    m_b_s = true;
                    m_str_s = optarg;
                    m_int_s = atoi(m_str_s.c_str());
                    break;
                }
            default:
                {
                    PrintForDebug("undefined optargs occured!\n");
                    return false;
                }
        }
    }
    if( m_b_v && m_b_M && m_b_d)
    {
        string::size_type pos = string::npos;
        while((pos = m_str_M.find(m_str_d)) != string::npos)
        {
            string tmp_str(m_str_M, 0,pos);
            m_vec.push_back(tmp_str);
            m_str_M = m_str_M.substr(pos+1);
        }
    }
    return true;
}

bool write_cache_handle::run(log_message* p_msg)
{
    if( m_b_v && m_b_M && m_b_d)
    {
        for(vector<string>::iterator iter = m_vec.begin();iter != m_vec.end();)
        {
            if(get_value_from_map( m_tmp_str, *iter))
            {
                m_cache_str += m_tmp_str;
                m_cache_str += m_str_d;
                m_tmp_str.clear();
                ++iter;
                continue;
            }
            return false;
        }
        ++m_count;
        if(((m_count % m_int_s)== 0) && m_b_t)
        {
            if(!(insert_kv_to_map( m_str_t, m_cache_str)))
            {
                PrintForDebug("insert value to map faile");
                m_tmp_str.clear();
                return false;
            }
            m_cache_str.clear();
        }
        else{
            m_cache_str +="\n";
            m_tmp_str.clear();
            if(!(insert_kv_to_map( m_str_t, m_tmp_str)))
            {
                PrintForDebug("insert value to map faile");
                return false;
            }
        }
        return true;
    }
    return false;
}

write_file_handle::write_file_handle()
{
}

bool write_file_handle::handle_getopt()
{
    int ch;
    int* p_optind = & optind;
    *p_optind = 1;
    while ((ch = getopt( m_argc, m_argv, "f:o:"))!=-1)
    {
        switch(ch)
        {
            case 'f':
                {
                    m_b_f = true;
                    m_str_f = optarg;
                    break;
                }
            case 'o':
                {
                    m_b_o = true;
                    m_str_o = optarg;
                    break;
                }
            default:
                {
                    PrintForDebug("undefined optargs occured!\n");
                    return false;
                }
        }
    }
    return true;
}

bool write_file_handle::run(log_message* p_msg)
{
    if(m_b_f)
        if(!(get_value_from_map( m_tmp_str, m_str_f)))
        {
            m_tmp_str.clear();
        }
    if(m_b_o && m_tmp_str.size() != 0)
    {
        FILE* fp = fopen(m_str_o.c_str(), "w+");
        if(fp == NULL)
        {
            PrintForDebug(m_str_o.c_str());
            return false;
        }
        fwrite( m_tmp_str.c_str(), m_tmp_str.length(), 1, fp);
        PrintForDebug(m_tmp_str.c_str());
        fflush(fp);
        fclose(fp);
        m_tmp_str.clear();
        fp = NULL;
    }
    return true;
}

oracle_output_handle::oracle_output_handle()
{
}

bool oracle_output_handle::handle_getopt()
{
    int ch;
    int* p_optind = & optind;
    *p_optind = 1;
    while ((ch = getopt( m_argc, m_argv, "i:u:p:b:c:"))!=-1)
    {
        switch(ch)
        {
            case 'i':
                {
                    m_b_i = true;
                    m_str_i = optarg;
                    break;
                }
            case 'u':
                {
                    m_b_u = true;
                    m_str_u = optarg;
                    break;
                }
            case 'p':
                {
                    m_b_p = true;
                    m_str_p = optarg;
                    break;
                }
            case 'b':
                {
                    m_b_b = true;
                    m_str_b = optarg;
                    break;
                }
            case 'c':
                {
                    m_b_c = true;
                    m_str_c = optarg;
                    break;
                }
            default:
                {
                    PrintForDebug("undefined optargs occured!\n");
                    return false;
                }
        }
    }
    return true;
}

bool oracle_output_handle::run(log_message* p_msg)
{
    if(m_b_i && m_b_u && m_b_p && m_b_b && m_b_c)
    {
        char buffer[300];
        memset(buffer, 0, 300);
        sprintf(buffer, "sqlldr %s/%s@%s control=%s.ctl bad=%s.bad", m_str_u.c_str(), m_str_p.c_str(), m_str_b.c_str(), m_str_c.c_str(), m_str_c.c_str());
        //system(buffer);
    }
    return true;
}

produce_handle::produce_handle()
{
}

handle* produce_handle::produce_handle_pointer(string& tmp_str)
{
    handle* p_handle = NULL;
    if( tmp_str == "get")
    {
        p_handle = new get_handle();
    }
    else if( tmp_str == "jscon_parse")
    {
        p_handle = new jscon_parse_handle();
    }
    else if( tmp_str == "filter")
    {
        p_handle = new filter_handle();
    }
    else if( tmp_str == "time")
    {
        p_handle = new time_handle();
    }
    else if( tmp_str == "put")
    {
        p_handle = new put_handle();
    }
    else if( tmp_str == "write_cache")
    {
        p_handle = new write_cache_handle();
    }
    else if( tmp_str == "write_file")
    {
        p_handle = new write_file_handle();
    }
    else if( tmp_str == "oracle_output")
    {
        p_handle = new oracle_output_handle();
    }
    else
    {
        PrintForDebug("undefined config str cooured!\n");
    }
    return p_handle;
}
