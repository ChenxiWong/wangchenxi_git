/*************************************************************************
  > File Name: mem_data_base_oper.cpp
  > Author: wangxiang
  > Mail: wangxiang456789@163.com 
  > Created Time: 2013年12月21日 星期六 15时15分17秒
 ************************************************************************/
#include <stdio.h>
#include "c_mysql.h"


bool c_mysql::mysql_insert(string  sql)
{
    // 取最大得ID	
    //插入一跳数据 
    res_conn();
    int res = mysql_query(&mysql, sql.c_str());
    if (!res) 
    {
        //printf("Inserted %lu rows\n",(unsigned long)mysql_affected_rows(&mysql));
        /*里头的函数返回受表中影响的行数*/
    } 
    else 
    {

       fprintf(stderr, "Insert error %d: %s\n",mysql_errno(&mysql),mysql_error(&mysql));
        // 写日志		
        return false;
    }

    return true; 
}
//远程查询操作数据库
// c_mysql::
// // 取用户的信息
// 
void c_mysql::mysql_update(string sql)
{
    res_conn();
    int res = mysql_query(&mysql, sql.c_str());
    if (!res) 
    {
        //printf("update  %lu rows\n",(unsigned long)mysql_affected_rows(&mysql));
        /*里头的函数返回受表中影响的行数*/
    }
    else {
        //   fprintf(stderr, "Insert error %d: %s\n",mysql_errno,(mysql),mysql_error(mysql));

    }


}
// c_mysql
bool  c_mysql::select (std::string sql ,C_MYSQL_SELECT_RESULT  func,void * data)
{
    // 查询数据库	
    res_conn();
    MYSQL_RES * res;
    MYSQL_ROW row;

    int t=mysql_real_query(&mysql,sql.c_str(),sql.length());

    if(t) {
        printf("查询数据库失败%s/n",mysql_error(&mysql));
    }
    else 
    {
        res=mysql_store_result(&mysql);//
        while(row=mysql_fetch_row(res))
        {
            //p_msg.set_userid(atoi(row[2]));
            func(row,data);
        }

        mysql_free_result(res);//操作完毕，查询结果集
    }
    return true;


}


void c_mysql::init()
{
    //    if(!mysql_real_connect(&mysql,s_host.c_str() ,s_username.c_str() ,s_passwd.c_str(),s_database.c_str(),0,NULL,0)){
    if(!mysql_real_connect(&mysql,s_host.c_str() ,s_username.c_str() ,s_passwd.c_str(),s_database.c_str(),iport,NULL,0)){

        fprintf(stderr,"无法连接到数据库，错误原因是:%s/n",mysql_error(&mysql));

    }
    else {

        printf("数据库连接成功");
    }
    if (!mysql_set_character_set(&mysql, "utf8"))
    {
            printf("New client character set: %s\n",
                               mysql_character_set_name(&mysql));
    }
    char value = 1;
    mysql_options(&mysql , MYSQL_OPT_RECONNECT, (char *)&value);

}
bool c_mysql::res_conn()
{
    mysql_ping(&mysql) ;
    return true ;
}

c_mysql::c_mysql(string host ,int port , string database ,string username ,string passwd)
{
    //mysql_init(&mysql);//初始化MYSQL标识符，用于连接
    
    mysql_init(&mysql);
    s_host = host ;
    iport = port ;
    s_username = username ;
    s_database = database ; 
    s_passwd = passwd ;
    init();

}
c_mysql::~c_mysql()
{
    mysql_close(&mysql);
    // --- 清理内存 
}

string c_mysql::add_varchar(string value) 
{
    replace_all(value,"\"","\\\"");
    replace_all(value,"\'","\\\'");
    string tmp ="\'";
    tmp += value;
    tmp += "\',";
    return tmp ;
}
string c_mysql::add_string(string value ) 
{
    return add_varchar(value);
}
string c_mysql::add_int(string value) 
{
    string tmp = value;
    tmp += ",";
    return tmp ;
}

string c_mysql::add_int(uint32_t value) 
{
    string tmp = ""; 
    DNUMTOSTR (value ,tmp );
    tmp += ",";
    return tmp ;
}
string c_mysql::add_int(int value) 
{
    string tmp = ""; 
    DNUMTOSTR (value ,tmp );
    tmp += ",";
    return tmp ;
}
string c_mysql::add_intdate(int value) 
{
    string tmp = ""; 
    DNUMTOSTR (value ,tmp );
    if(tmp.length() == 6) 
    {
        return add_date(tmp) ;
    }
    else 
    {
        return "curdate(),";
    }

}
string c_mysql::add_date(string value)
{
    string sql = "";
    sql = "date_format(\'";
    sql += value ;
    sql +="\', \'%Y%m%d\')"; 
    sql  += ",";
    return sql ;
}
void c_mysql::Insert_end(string & sql) 
{
    if(sql[sql.size()-1] == ')')
    {
        return  ;
    }
    if(sql[sql.size()-1] == ',')
    {
        sql[sql.size()-1] = ')';
    }
    return ;
}


string  c_mysql::update_setint(bool & b_begin , string clud_name  ,string value  )
{
    string sql = "";
    if(value == "") 
    {
        return sql ;
    }
    else 
    {
        if(b_begin) 
        {
            b_begin = false ; 
        }
        else 
        {
            sql += "," ; 
        }
        sql += clud_name ; 
        sql += " = " ;
        sql  += value ; 
        sql += " " ;

    }
    return sql ; 
}
string  c_mysql :: update_setstring(bool & b_begin , string clud_name  ,string value  )
{
    string sql = "";
    if(value == "") 
    {
        return sql ;
    }
    else 
    {
        if(b_begin) 
        {
            b_begin = false ; 
        }
        else 
        {
            sql += "," ; 
        }
        sql += clud_name ; 
        sql += " = \'" ;
        sql  += value ; 
        sql += "\' " ;

    }
    return sql ; 
}
