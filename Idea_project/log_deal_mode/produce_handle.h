// Last Update:2017-03-30 15:20:30
/**
 * @file produce_handle.h
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */

#ifndef PRODUCE_HANDLE_H
#define PRODUCE_HANDLE_H

#include "log_message.h"
#include "handle.h"
#include <string>
using std::string;

class add_handle:virtual public handle
{
    private:
    protected:
    public:
        add_handle();
        virtual ~add_handle(){}
        bool handle_getopt();
        bool run(log_message*);
};

class jscon_parse_handle:virtual public handle
{
    private:
    protected:
        bool get_value_from_jscon_str(string&, string&);
    public:
        jscon_parse_handle();
        virtual ~jscon_parse_handle(){}
        bool handle_getopt();
        bool run(log_message*);
};

class produce_handle
{
    private:
        produce_handle();
    protected:
    public:
        virtual~produce_handle(){}
        static produce_handle* get_instance()
        {
            static produce_handle static_produce_handle;
            return &static_produce_handle;
        }
        handle* produce_handle_pointer(string&);
};





#endif  /*PRODUCE_HANDLE_H*/
