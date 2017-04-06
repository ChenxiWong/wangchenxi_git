// Last Update:2016-07-30 09:48:09
/**
 * @file wyxstd.h
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-07-30
 */

#ifndef WYXSTD_H
#define WYXSTD_H
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
extern "C"{
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <iconv.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pthread.h>
#include<regex.h>    // 关于正则匹配
#include<assert.h>
}

#include "wyxdef.h"

using namespace std;
/*
 * aim_str：用于带出找到的目的字符串；
 * p_buffer：从哪里开始查找，是一个地址值；
 * start_sign：开始标志，一般是关键字；
 * end_sign：结束标志；
 * aim_str_start：从开始标志向后偏移位数；
 * aim_str_end_to_end_sign：结束标志位开始位置向前偏移到达目的字符串结尾的位数；
 * p_deal_len：用于带出已经处理查找过的长度（相对于p_buffer）；
 * p_no_useful_len：用于带出可以确定没有可用信息的长度（相对于p_buffer）；
 * 返回值：找到了符合要求的字符串，则返回true，传入参数错误（p_buffer为空，或者没有找到开始关键字）返回false；
 */
bool get_string_from_http_buffer(string& aim_str,const char* p_buffer,const char* start_sign,const char* end_sign,int aim_str_start,int aim_str_end_to_end_sign, int* p_deal_len = NULL, int* p_no_useful_len = NULL);


string&   replace_all(string&   str,const   string&   old_value,const   string&   new_value);


int code_convert(const char *from_charset, const char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen);


int u2g(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

//IPV4、IPV6判断，需要进一步完善
void classify_ip_kind_info(string  ip_str, int& is_ipv6, int& is_ipv4);

//----------------需要改进
void create_path(string& path);

static int big_little_signe = 0;

//转字符集函数实现
typedef union
{
    uint32_t num;
    unsigned char code[4];
}four_char;

typedef union
{
    unsigned short num;
    unsigned char code[2];
}two_char;


bool is_bigendian();

int unicode_to_utf8_1(uint32_t unic, unsigned char* pOutput, int outSize);

//该函数用于处理字符串中含有%u的转码问题 svalue为含有%u的字符串，flag是你要处理的标志可以是%u也可以为\\u
bool unic2utf(string& svalue, string& flag);

bool gbk_invisible(unsigned short short_tmp, unsigned int* low_line, unsigned int* high_line);

bool utf_visible(unsigned int short_tmp, unsigned int* low_line, unsigned int* high_line);

//通过检查字符串中是否存在未被编码集合映射字符，来判定是否为gbk编码
bool gbk_judgement(unsigned char* c_tmp);

//将gbk编码转换成utf-8编码
void gbk_to_utf(string& answer_str, string& question_str);

void little_endian_deal(four_char* p_union, int num, unsigned char* c_arry);

void big_endian_deal(four_char* p_union, int num, unsigned char* c_arry);


// 判断字符是否符合utf-8编码规范
// 数组范围有待进一步完善
bool utf_judgement(unsigned char* p_tmp, int i);

bool find_flag(string& answer_str,string& flag);

void deal_answer_str_find_unicode_form(string& answer_str);

//祛除字符串中因字符集问题导致的乱码。
//该函数仅仅支持字符串编码格式为带u、U的Unicode编码、GBK编码转换为UTF-8编码
void get_rid_of_garbled(string& answer_str, string& question_str);

void deal_pcre_url(string& pcre_url, string& tmp_aim_str);

int write_config_xml(string& dst_file, string& src_file);

string base64_encode(const unsigned char* Data, int DataByte)

string base64_decode(const char* Data, int DataByte, int& OutByte);

static int php_htoi(char *s);

//url解码函数:utf-8类型
string urldecode(string &str_source);


void  host_ip(string& src_file_path, int argc);

// 以下代码为自实现队列，基于此实现高效率、安全的线程池

class Cnode
{
    private:
        void* m_buffer;
        Cnode* m_p_next_node;
        Cnode* m_p_precede_node;
    public:
        Cnode(void* buffer):m_buffer(buffer),m_p_next_node(NULL),m_p_precede_node(NULL){}

        Cnode(Cnode* p_Cnode):m_buffer(p_Cnode->get_m_buffer())
                              ,m_p_next_node(p_Cnode->get_m_p_next_node())
                              ,m_p_precede_node(p_Cnode->get_m_p_precede_node()){}

        Cnode():m_buffer(NULL),m_p_next_node(NULL),m_p_precede_node(NULL){}

        void* get_m_buffer(){return m_buffer;}
        //only constructors take member initializers
        //void set_m_p_Cdata(Cdata* p_Cdata):m_p_Cdata(p_Cdata){}  error!!!
        void set_m_buffer(void* buffer){m_buffer = buffer;}

        Cnode* get_m_p_next_node(){return m_p_next_node;}

        void set_m_p_next_node(Cnode* p_Cnode){m_p_next_node = p_Cnode;}

        Cnode* get_m_p_precede_node(){return m_p_precede_node;}
        void set_m_p_precede_node(Cnode* p_Cnode){ m_p_precede_node = p_Cnode;}
};

typedef enum QueueAction
{
    HEAD_PUSH,
    TAIL_PUSH,
    HEAD_POP,
    TAIL_POP,
}EQA;

//尝试加入信号量机制，也许会更好。
class Cqueue
{
    private:
        //队列节点总数
        volatile uint64_t m_counter;

        //头节点
        Cnode* m_p_head_Cnode;

        //尾部节点
        Cnode* m_p_tail_Cnode;


        // 以下变量为实现多线程安全操作而添加
        // 灵活、保守队列操作使用
        volatile int32_t entrance_num;

        //为提高效率，尽可能实现进入队列、出队列可以同时进行
        volatile int32_t safe_push_num;
        volatile int32_t safe_pop_num;

        //头进队列
        bool head_push(Cnode* p_Cnode, uint64_t* p_m_counter)
        {
            // apply  memory for new node which will be added to the queue.
            Cnode* p_tmp_Cnode = new Cnode(p_Cnode);
            assert(p_tmp_Cnode);
            if( p_tmp_Cnode == NULL)exit(EXIT_FAILURE);
            // add this node to the queue.
            // if this node is the first node of the queue...
            if( 0 == m_counter )
            {
                // the both of the headnode and tailnode pointer point to this node.
                m_p_head_Cnode = p_tmp_Cnode;
                m_p_tail_Cnode = p_tmp_Cnode;
            }
            else
            {
                // only operate the headnode pointer.
                p_tmp_Cnode->set_m_p_next_node(m_p_head_Cnode);
                m_p_head_Cnode->set_m_p_precede_node(p_tmp_Cnode);
                p_tmp_Cnode->set_m_p_precede_node(NULL);
                m_p_head_Cnode = p_tmp_Cnode;
            }
            ++m_counter;
            if(p_m_counter != NULL)*p_m_counter = m_counter;
            return true;
        }

        //尾进队列
        bool tail_push(Cnode* p_Cnode, uint64_t* p_m_counter)
        {
            // apply memory for this new node which will be added to the queue.
            Cnode* p_tmp_Cnode = new Cnode(p_Cnode);
            assert(p_tmp_Cnode);
            if( p_tmp_Cnode == NULL)exit(EXIT_FAILURE);
            // add this node to the queue.
            // if this node is the first node of the queue...
            if( 0 == m_counter)
            {
                m_p_head_Cnode = p_tmp_Cnode;
                m_p_tail_Cnode = p_tmp_Cnode;
            }
            else
            {
                // else  only operate the tailnode pointer.
                p_tmp_Cnode->set_m_p_precede_node(m_p_tail_Cnode);
                m_p_tail_Cnode->set_m_p_next_node(p_tmp_Cnode);
                p_tmp_Cnode->set_m_p_next_node(NULL);
                m_p_tail_Cnode = p_tmp_Cnode;
            }
            ++m_counter;
            if(p_m_counter != NULL)*p_m_counter = m_counter;
            return true;
        }

        //头出队列
        bool head_pop(Cnode* node, uint64_t* p_m_counter)
        {
            // if the queue has no node.
            if(m_counter == 0)
            {
                node = NULL;
                *p_m_counter = 0;
                return false;
            }
            Cnode* p_tmp_Cnode = m_p_head_Cnode;
            if( 1 == m_counter)
            {
                m_p_head_Cnode = NULL;
                m_p_tail_Cnode = NULL;
            }else
            {
                m_p_head_Cnode = m_p_head_Cnode->get_m_p_next_node();
                m_p_head_Cnode->set_m_p_precede_node(NULL);
            }
            p_tmp_Cnode->set_m_p_next_node(NULL);
            p_tmp_Cnode->set_m_p_precede_node(NULL);
            *node = *p_tmp_Cnode;

            // release memory
            delete p_tmp_Cnode;
            p_tmp_Cnode = NULL;

            --m_counter;
            if(p_m_counter != NULL)*p_m_counter = m_counter;
            return true;
        }

        // 尾部出队列
        bool tail_pop(Cnode* node, uint64_t* p_m_counter)
        {
            // if the queue has no node.
            if(m_counter == 0)
            {
                node = NULL;
                *p_m_counter = 0;
                return false;
            }
            Cnode* p_tmp_Cnode = m_p_tail_Cnode;
            if(1 == m_counter)
            {
                m_p_tail_Cnode = NULL;
                m_p_head_Cnode = NULL;
            }else
            {
                m_p_tail_Cnode = m_p_tail_Cnode->get_m_p_precede_node();
                m_p_tail_Cnode->set_m_p_next_node(NULL);
            }
            p_tmp_Cnode->set_m_p_next_node(NULL);
            p_tmp_Cnode->set_m_p_precede_node(NULL);

            // release memory
            *node = *p_tmp_Cnode;
            delete p_tmp_Cnode;
            p_tmp_Cnode = NULL;

            --m_counter;
            if(p_m_counter != NULL)*p_m_counter = m_counter;
            return true;
        }
    public:
        Cqueue():m_counter(0),m_p_head_Cnode(NULL)
                 ,m_p_tail_Cnode(NULL)
                 ,entrance_num(0)
                 ,safe_push_num(0)
                 ,safe_pop_num(0){}
        ~Cqueue(){}


        // 保守的使用方法，实现了安全和操作灵活，多线程效率较好。
        bool conservative_safety_call(Cnode* p_Cnode, uint64_t* p_m_counter, EQA enum_queue_action)
        {
            while(!__sync_bool_compare_and_swap(&entrance_num, 0, 1)){}
            bool tmp_bool = false;
            switch(enum_queue_action)
            {
                case HEAD_PUSH:
                    {
                        tmp_bool = head_push(p_Cnode, p_m_counter);
                        __sync_sub_and_fetch(&entrance_num, 1);
                        return tmp_bool;
                    }
                case TAIL_PUSH:
                    {
                        tmp_bool = tail_push(p_Cnode, p_m_counter);
                        __sync_sub_and_fetch(&entrance_num, 1);
                        return tmp_bool;
                    }
                case HEAD_POP:
                    {
                        tmp_bool = head_pop(p_Cnode, p_m_counter);
                        __sync_sub_and_fetch(&entrance_num, 1);
                        return tmp_bool;
                    }
                case TAIL_POP:
                    {
                        tmp_bool = tail_pop(p_Cnode, p_m_counter);
                        __sync_sub_and_fetch(&entrance_num, 1);
                        return tmp_bool;
                    }
                default:
                    {
                        DBGCODE(cout<<"Unknown action appeared, Please check your code!"<<endl;
                             exit(EXIT_FAILURE););
                    }
            }
            return false;
        }

        //激进的使用方法，只支持HEAD_PUSH、TAIL_POP，特点：安全、效率高。
        bool radical_safety_call(Cnode* p_Cnode, uint64_t* p_m_counter, EQA enum_queue_action)
        {
            if(__sync_bool_compare_and_swap(&m_counter, 1, 1))
            {
                return conservative_safety_call( p_Cnode, p_m_counter, enum_queue_action);
            }
            bool tmp_bool = false;
            switch(enum_queue_action)
            {
                case HEAD_PUSH:
                    {
                        while(!__sync_bool_compare_and_swap(&safe_push_num, 0, 1)){}
                        tmp_bool = head_push(p_Cnode, p_m_counter);
                        __sync_sub_and_fetch(&safe_push_num, 1);
                        return tmp_bool;
                    }
                case TAIL_POP:
                    {
                        while(!__sync_bool_compare_and_swap(&safe_pop_num, 0, 1)){}
                        tmp_bool = tail_pop(p_Cnode, p_m_counter);
                        __sync_sub_and_fetch(&safe_pop_num, 1);
                        return tmp_bool;
                    }
                case TAIL_PUSH:
                case HEAD_POP:
                default:
                    {
                        DBGCODE(
                             cout<<"Unknown action appeared, Please check your code!"<<endl;
                             exit(EXIT_FAILURE);
                            );
                    }
            }
            return false;
        }

        uint64_t get_m_counter()
        {
            return m_counter;
        }

        Cnode* get_m_p_head_Cnode(){return m_p_head_Cnode;}
        Cnode* get_m_p_tail_Cnode(){return m_p_tail_Cnode;}

};

// 借助以上双向队列实现线程池
//详细实现案例查看 ~/workshop/bin/mine_threadpool/test_wyxthreadpool.cpp
typedef void*(*FuncHandle)(void*);
// task descripstion

class wyxCTask
{
    private:
        void* m_data;
        FuncHandle m_work;
    public:
        wyxCTask(void* tmp_data):m_data(tmp_data){}
        wyxCTask():m_data(NULL){}
        ~wyxCTask(){}
        bool set_m_data(void* tmp_data)
        {
            m_data = tmp_data;
            return true;
        }
        /*bool get_m_data(void* tmp_data)
          {
          if(m_data == NULL)return false;
         *tmp_data = *m_data;
         return true;
         }*/
        void* get_m_data()
        {
            return m_data;
        }
        bool set_m_work(FuncHandle p_tmp_handle)
        {
            m_work = p_tmp_handle;
            return true;
        }
        FuncHandle get_m_work()
        {
            return m_work;
        }
};

static void* m_thread_work(void* thread_data);

class wyxCThreadPool
{
    private:
        //待改进，加入停止机制
        Cqueue m_task_queue;
        int32_t m_max_thread_num;
        pthread_t* m_pthread_id;
        char* m_relax_sign;

        int m_create()
        {
            m_pthread_id = (pthread_t*)new char[sizeof(pthread_t)*m_max_thread_num];
            m_relax_sign = (char*)new char[m_max_thread_num + 1];
            memset(m_relax_sign, 0, m_max_thread_num + 1);
            for(int i = 0; i < m_max_thread_num; ++i)
            {
                pthread_create(&m_pthread_id[i], NULL, m_thread_work, this);
            }
            return 0;
        }

    public:

        wyxCThreadPool(int tmp_thread_num = 5):m_max_thread_num(tmp_thread_num)
    {
        m_create();
    }

        ~wyxCThreadPool()
        {
            delete[] m_pthread_id;
            m_pthread_id = NULL;
            delete[] m_relax_sign;
            m_relax_sign = NULL;
        }

        bool m_push_task_to_queue(wyxCTask* p_wyxCTask, uint64_t* p_num)
        {
            Cnode tmp_Cnode((void*)p_wyxCTask);
            if(!m_task_queue.radical_safety_call(&tmp_Cnode, p_num, HEAD_PUSH))
            {
                DBGCODE(cout<<"Unknown action appeared, Please check your code!"<<endl;     );
                return false;
            }
            return true;
        }

        bool m_pop_task_from_queue(wyxCTask* p_wyxCTask, uint64_t* num)
        {
            Cnode pop_node;
            if(!m_task_queue.radical_safety_call(&pop_node, num, TAIL_POP))
            {
                DBGCODE(cout<<"Unknown action appeared, Please check your code!"<<endl;);
                return false;
            }
            *p_wyxCTask = *((wyxCTask*)pop_node.get_m_buffer());
            return true;
        }

        void thread_declare_relax(pthread_t tmp_tid)
        {
            int i = 0;
            for( ;i<m_max_thread_num; ++i)
            {
                if(m_pthread_id[i] == tmp_tid)
                {
                    m_relax_sign[i] = 'r';
                    return;
                }
            }
            DBGCODE(cout<<"error appeared,line 1516"<<endl;);
            return;
        }

        void thread_declare_busy(pthread_t tmp_tid)
        {
            int i = 0;
            for( ;i<m_max_thread_num; ++i)
            {
                if(m_pthread_id[i] == tmp_tid)
                {
                    m_relax_sign[i] = 0;
                    return;
                }
            }
           DBGCODE(cout<<"error appeared,line 1516"<<endl;);
            return;
        }

        bool threadpool_is_relax()
        {
            if(m_max_thread_num == strlen(m_relax_sign))return true;

            return false;
        }
};


static void* m_thread_work(void* thread_data)
{
    wyxCThreadPool* tmp_threadpool = (wyxCThreadPool*)thread_data;
    pthread_t tid = pthread_self();
    uint64_t num = 0;
    while(1)
    {
        wyxCTask tmp_task;
        while(!tmp_threadpool->m_pop_task_from_queue(&tmp_task, &num))
        {
            tmp_threadpool->thread_declare_relax(tid);

          DBGCODE(cout<<"threadpool has no task..."<<endl;);

            sleep(1);
        }
        tmp_threadpool->thread_declare_busy(tid);
        FuncHandle tmp_func_handle = tmp_task.get_m_work();
        tmp_func_handle((void*)&tmp_task);
    }
    return (void*)0;
}

void file_to_str(string& dst_str, string& file_path)
{
    stringstream sstream_tmp;
    ifstream in(file_path.c_str(), ios::in);
    string str_tmp("");
    while(1)
    {
        getline(in, str_tmp);
        if(!in)break;
        sstream_tmp<<str_tmp<<endl;
        str_tmp.clear();
    }
    if(str_tmp.size() != 0)sstream_tmp<<str_tmp;
    sstream_tmp<<endl;
    dst_str = sstream_tmp.str();
    in.close();
}

void* get_shell_cmd_output(string& shell_cmd_str, string& cmd_output)
{
    FILE* pp = popen( shell_cmd_str.c_str(), "r");
    if(!pp)
    {
        cout<<"PopenFailed!"<<endl;
        return (void*)0;
    }
    char c_tmp[MAX_SIZE_ARRAY];
    memset(c_tmp, 0, MAX_SIZE_ARRAY);
    while(fgets(c_tmp, MAX_SIZE_ARRAY, pp) != NULL) //读取并处理一行
    {
        cmd_output += c_tmp;
    }
    pclose(pp);
    //cout<< cmd_output<<endl;
    return (void*)0;
}

void calculus_monitor_cmd(string& shell_cmd_str)
{
    // find  /home/zipfiles  -name "*.txt" | xargs -n 1 tail -n 1
    //string shell_cmd_str(argv[1]);
    string all_string("");
    string tail_string("");
    string swap_string("");
    while(1)
    {
        string cmd_output("");
        get_shell_cmd_output(shell_cmd_str, cmd_output);
        stringstream s_line(cmd_output.c_str());
        string line("");
        char c_arry[MAX_SIZE_ARRAY];
        memset(c_arry, 0 , MAX_SIZE_ARRAY);
        while(1)
        {
            s_line.getline(c_arry, MAX_SIZE_ARRAY);
            if(!s_line)break;
            tail_string = c_arry;
            memset(c_arry, 0, MAX_SIZE_ARRAY);
            if( string::npos == all_string.find(tail_string))
            {
                cout<<tail_string
                    <<endl
                    <<endl;
                swap_string += tail_string;
            }
            swap_string += tail_string;
            tail_string.clear();
        }
        s_line.str("");
        all_string.swap(swap_string);
        swap_string.clear();
    }
}

// 未来待加入 多进程协作功能函数，目录操作，文件状态检测
//关于正则匹配的相关函数

#define SUBSLEN 1024/*匹配子串的数量*/
#define EBUFLEN 128/*错误消息buffer长度*/
#define BUFLEN 1024/*匹配到的字符串buffer长度*/
bool wyx_regex_match(const string& src_str, const string& pattern_str)
{
    const char* src = src_str.c_str();
    const char* pattern = pattern_str.c_str();
    size_t len;
    regex_t re;/*存储编译好的正则表达式，正则表达式在使用之前要经过编译*/
    regmatch_t subs[SUBSLEN];/*存储匹配到的字符串位置*/
    char matched[BUFLEN];/*存储匹配到的字符串*/
    char errbuf[EBUFLEN];/*存储错误消息*/
    int err,i;
    DBGCODE(
         printf("String:%s\n",src);
         printf("Pattern:\"%s\"\n",pattern);
        );
    /*编译正则表达式*/
    err=regcomp(&re,pattern, REG_EXTENDED|REG_NEWLINE);
    if(err){
        len=regerror(err,&re,errbuf,sizeof(errbuf));
        DBGCODE(
             printf("error:regcomp:%s\n",errbuf);
            );
        return false;
    }
    DBGCODE(
         printf("Totalhassubexpression:%d\n",re.re_nsub);
        );
    /*执行模式匹配*/
    err=regexec(&re,src,(size_t)SUBSLEN,subs,0);
    if(err== REG_NOMATCH ){/*没有匹配成功*/
        DBGCODE(
             printf("Sorry,nomatch...\n");
            );
        regfree(&re);
        return false;
    }else if(err){/*其它错误*/
        len = regerror(err,&re,errbuf,sizeof(errbuf));
        DBGCODE(
             printf("error:regexec:%s\n",errbuf);
            );
        return false;
    }
    /*如果不是REG_NOMATCH并且没有其它错误，则模式匹配上*/
    DBGCODE(
         printf("\nOK,hasmatched...\n\n");
        );
    for(i=0;i<=re.re_nsub;i++){
        len=subs[i].rm_eo-subs[i].rm_so;
        if(i==0){
            DBGCODE(
                 printf("begin:%d,len=%d",subs[i].rm_so,len);
                );/*注释1*/
        }else{
            DBGCODE(
                 printf("subexpression%dbegin:%d,len=%d",i,subs[i].rm_so,len);
                );
        }
        memcpy(matched,src+subs[i].rm_so,len);
        matched[len]='\0';
        DBGCODE(
             printf("match:%s\n",matched);
            );
    }
    regfree(&re);/*用完了别忘了释放*/
    return true;
}



#endif  /*WYXSTD_H*/
