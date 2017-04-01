// Last Update:2017-03-31 09:10:04
/**
 * @file log_analysiser.h
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-31
 */

#ifndef LOG_ANALYSISER_H
#define LOG_ANALYSISER_H

#include "arrange_table.h"
#include "read_mysql.h"
#include <list>

using std::list;

class log_analysiser
{
    private:
        list<arrange_table*> m_table_list;
        read_mysql* m_p_read_mysql;
        int m_thread_num;
        bool one_arrange_table(list<log_message*>*);
        string m_xml_path;
        void xml_parse();
    protected:
    public:
        log_analysiser(const char*);
        log_analysiser(log_analysiser& tmp);
        log_analysiser& operator= (log_analysiser&);
        virtual~log_analysiser()
        {
            if(m_p_read_mysql != NULL)
            {
                delete m_p_read_mysql;
                m_p_read_mysql = NULL;
            }
            for(list<arrange_table*>::iterator iter = m_table_list.begin(); iter != m_table_list.end(); ++iter)
            {
                if(*(iter) != NULL)
                {
                    delete *(iter);
                    *(iter) = NULL;
                }
            }
        }
        void* analysis();
};

#endif  /*LOG_ANALYSISER_H*/
