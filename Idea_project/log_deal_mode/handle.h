// Last Update:2017-03-30 14:45:00
/**
 * @file handle.h
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */

#ifndef HANDLE_H
#define HANDLE_H

#include "log_message.h"
#include <map>
#include <string>
using std::map;
using std::string;

class handle
{
    private:
        void set_m_arg_str(string&);
        void set_m_p_map(map<string, string>*);
        void str2argv();
        string m_arg_str;
        map<string, string>* m_p_map;
    protected:
        int m_argc;
        char** m_argv;
        char* m_p_c;
        log_message* p_log_message;
    public:
        handle();
        handle(handle& p_handle);
        handle& operator= (handle& p_handle);
        void init_handle(string& , map<string, string>*);
        virtual ~handle()
        {
            if(m_argv != NULL)
            {
                delete[] m_argv;
                m_argv = NULL;
            }
            if(m_p_c != NULL)
            {
                delete[] m_p_c;
                m_p_c = NULL;
            }
        }
        virtual bool run(log_message*) = 0;
};


#endif  /*HANDLE_H*/
