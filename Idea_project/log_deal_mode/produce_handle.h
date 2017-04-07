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

        bool m_b_g;
        string m_str_g;

        bool m_b_f;
        string m_str_f;

        bool m_b_t;
        string m_str_t;

        bool m_b_a;
        string m_str_a;

    public:
        jscon_parse_handle();
        virtual ~jscon_parse_handle(){}
        bool handle_getopt();
        bool run(log_message*);
};

class get_handle:virtual public handle
{
    private:
    protected:

        bool m_b_g;
        string m_str_g;

        bool m_b_t;
        string m_str_t;

    public:
        get_handle();
        virtual ~get_handle(){}
        bool handle_getopt();
        bool run(log_message*);
};

class filter_handle:virtual public handle
{
    private:
    protected:

        bool m_b_f;
        string m_str_f;

        bool m_b_i;
        string m_str_i;

        bool m_b_e;
        string m_str_e;

    public:
        filter_handle();
        virtual ~filter_handle(){}
        bool handle_getopt();
        bool run(log_message*);
};

class put_handle:virtual public handle
{
    private:
    protected:

        bool m_b_t;
        string m_str_t;

        bool m_b_a;
        string m_str_a;

    public:
        put_handle();
        virtual ~put_handle(){}
        bool handle_getopt();
        bool run(log_message*);
};

class time_handle:virtual public handle
{
    private:
    protected:

        bool m_b_f;
        string m_str_f;

        bool m_b_t;
        string m_str_t;

        bool m_b_a;
        string m_str_a;

        bool modulo_operation_of_time(string&, string&);
    public:
        time_handle();
        virtual ~time_handle(){}
        bool handle_getopt();
        bool run(log_message*);
};

class write_cache_handle:virtual public handle
{
    private:
    protected:

        unsigned long long m_count;

        vector<string> m_vec;

        string m_cache_str;

        bool m_b_v;
        string m_str_v;
        int m_int_v;

        bool m_b_M;
        string m_str_M;

        bool m_b_d;
        string m_str_d;

        bool m_b_t;
        string m_str_t;

        bool m_b_s;
        string m_str_s;
        int m_int_s;

    public:
        write_cache_handle();
        virtual ~write_cache_handle(){}
        bool handle_getopt();
        bool run(log_message*);
};

class write_file_handle:virtual public handle
{
    private:
    protected:

        bool m_b_f;
        string m_str_f;

        bool m_b_o;
        string m_str_o;

    public:
        write_file_handle();
        virtual ~write_file_handle(){}
        bool handle_getopt();
        bool run(log_message*);
};

class oracle_output_handle:virtual public handle
{
    private:
    protected:

        bool m_b_c;
        string m_str_c;

        bool m_b_b;
        string m_str_b;

        bool m_b_p;
        string m_str_p;

        bool m_b_u;
        string m_str_u;

        bool m_b_i;
        string m_str_i;

    public:
        oracle_output_handle();
        virtual ~oracle_output_handle(){}
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
