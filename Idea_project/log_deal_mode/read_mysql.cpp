// Last Update:2017-02-08 15:39:26
/**
 * @file read_mysql.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-02-08
 */
#include "read_mysql.h"
#include "log_message.h"

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xmlsave.h>

extern "C"{
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
}


read_mysql::read_mysql(xmlNodePtr curNode)
{

    curNode = curNode->xmlChildrenNode;
    while(curNode != NULL)
    {
        if( 0 == xmlStrcmp(curNode->name, BAD_CAST("space_time")))
        {
            m_space_time =atoi((char*)xmlNodeGetContent(curNode));
        }else if( 0 == xmlStrcmp(curNode->name, BAD_CAST("port")))
        {
            m_port =atoi((char*)xmlNodeGetContent(curNode));
        }else if( 0 == xmlStrcmp(curNode->name, BAD_CAST("host")))
        {
            m_host =(char*)xmlNodeGetContent(curNode);
        }else if( 0 == xmlStrcmp(curNode->name, BAD_CAST("db_name")))
        {
            m_db_name =(char*)xmlNodeGetContent(curNode);
        }else if( 0 == xmlStrcmp(curNode->name, BAD_CAST("table_name")))
        {
            m_table_name =(char*)xmlNodeGetContent(curNode);
        }else if( 0 == xmlStrcmp(curNode->name, BAD_CAST("user_name")))
        {
            m_user_name =(char*)xmlNodeGetContent(curNode);
        }else if( 0 == xmlStrcmp(curNode->name, BAD_CAST("passwd")))
        {
            m_passwd =(char*)xmlNodeGetContent(curNode);
        }else if( 0 == xmlStrcmp(curNode->name, BAD_CAST("plan_to_get_num_once")))
        {
            m_plan_to_get_num_once =atoi((char*)xmlNodeGetContent(curNode));
        }else
        {
        }
        curNode = curNode->next;
    }
    m_mysql = new c_mysql(m_host, m_port, m_db_name, m_user_name, m_passwd);
}

read_mysql::~read_mysql()
{
    if(m_mysql != NULL)
    {
        delete m_mysql;
        m_mysql = NULL;
    }
}

void read_mysql_set_int_value(MYSQL_ROW& row , void* data)
{
    int* p_int = (int*) data;
    *p_int = atoi(row[0]);
}

bool read_mysql::get_min_id()
{
    string sql("select min(ID) from SystemEvents ;");
    m_mysql->select(sql, read_mysql_set_int_value, (void*)&m_min_id);
    if(m_min_id == 0)
    {
        printf("The table mightbe empty!\n");
        return false;
    }
    return true;
}

bool read_mysql::get_max_id()
{
    string sql("select count(ID) from SystemEvents ;");
    m_mysql->select(sql, read_mysql_set_int_value, (void*)&m_max_id);
    if(m_max_id == 0)
    {
        printf("The table mightbe empty!\n");
        return false;
    }
    m_max_id += m_min_id;
    return true;
}

bool read_mysql::ensure_get_num_infact()
{
    if(get_max_id() && get_min_id())
    {
        if(m_plan_to_get_num_once >= (m_max_id -m_min_id))
        {
            m_get_num_infact = m_max_id - m_min_id + 1;
        }else{
            m_get_num_infact = m_plan_to_get_num_once;
        }
        return true;
    }
    return false;
}

void fill_read_mysql_list(MYSQL_ROW& row, void* data)
{
    read_mysql* p_read_mysql = (read_mysql*) data;
    log_message* p_tmp_log_message = new log_message((char*)row[0], (char*) row[1], (char*) row[2], (char*)row[3]);
    p_read_mysql->first_stemp_result.push_back(p_tmp_log_message);
}

bool read_mysql::first_stemp_work()
{
    if(ensure_get_num_infact())
    {
        char sql_buf[1024];
        memset( sql_buf, 0, 1024);
        sprintf(sql_buf, "select ID, DeviceReportedTime, FromHost, Message from SystemEvents where ID>= %d and ID <= %d order by ID asc;", m_min_id, m_min_id + m_get_num_infact-1);
        string sql(sql_buf);
        m_mysql->select(sql, fill_read_mysql_list, (void*) this);
        memset( sql_buf, 0, 1024);
        sprintf(sql_buf, "delete from SystemEvents where ID >= %d and ID <= %d ;", m_min_id, m_min_id + m_get_num_infact-1);
        sql = sql_buf;
        m_mysql->mysql_insert(sql);
        return true;
    }
    return false;
}

