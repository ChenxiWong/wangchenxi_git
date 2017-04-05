// Last Update:2017-02-08 15:39:26
/**
 * @file read_mysql.h
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-02-08
 */

#ifndef READ_MYSQL_H
#define READ_MYSQL_H
#include "c_mysql.h"

#include "log_message.h"

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xmlsave.h>

#include <string>
#include <list>

using std::string;
using std::list;

class read_mysql
{
    private:
        c_mysql* m_mysql;
        string m_host;
        int m_port;
        string m_db_name;
        string m_table_name;
        int m_max_id;
        string m_user_name;
        string m_passwd;

        int m_min_id;
        int m_plan_to_get_num_once;
        int m_get_num_infact;


        bool get_min_id();
        bool get_max_id();
        bool ensure_get_num_infact();

    public:
        read_mysql(xmlNodePtr curNode);
        ~read_mysql();
        int m_space_time;


        list<log_message*> first_stemp_result;
        bool first_stemp_work();

};

#endif  /*READ_MYSQL_H*/
