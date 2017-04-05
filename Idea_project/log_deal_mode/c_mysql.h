/*************************************************************************
    > File Name: mem_data_base_oper.h
    > Author: wangxiang
    > Mail: wangxiang456789@163.com 
    > Created Time: 2013年12月21日 星期六 15时15分22秒
 ************************************************************************/
#ifndef __C_MYSQL_H__
#define __C_MSYQL_H__
#include<iostream>
#include<string>
#include <mysql/mysql.h>
#include "commit_tools.h"
//#include <plugin_common.h>
typedef void (*C_MYSQL_SELECT_RESULT)(MYSQL_ROW& row ,void * data );
using namespace std;
class c_mysql
{
    public:
        c_mysql(string host ,int port , string database ,string username ,string passwd);
        ~c_mysql();
        bool mysql_insert(string  sql);
        void mysql_update(string sql);
        bool select (std::string sql ,C_MYSQL_SELECT_RESULT  func,void * data);
        //************************88
        string add_varchar(string value) ;
        string add_int(int value) ;
        string add_int(uint32_t value) ;
        string add_int(string value);
        string add_intdate(int value);
        string add_string(string value ) ;
        string add_date(string) ;
        void Insert_end(string & sql) ;
        string update_setint(bool & b_begin , string clud_name  ,string value  );
        string update_setstring(bool & b_begin , string clud_name  ,string value  );
    private:
     bool res_conn();
     void  init();
      string s_host;  
      int   iport ;
      string s_username;
      string s_passwd ;
      string s_database ; 
      MYSQL mysql;
};
#endif

