// Last Update:2016-11-26 16:06:57
/**
 * @file thread_pool_ex.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-11-26
 */
#include "wyxstd.h"

class work_node
{
    private:
        const char* m_p_c;

    public:
        work_node(const char*p):m_p_c(p){}
        ~work_node(){}
        const char* get_m_p_c()
        {
            return m_p_c;
        }
        void set_m_p_c(char* p)
        {
            m_p_c = p;
        }
};

class data_group
{
    private:
        wyxCThreadPool* m_work_pool;
        work_node* m_work_node;

    public:
        data_group(wyxCThreadPool* p_pool, work_node* p_node):m_work_pool(p_pool),m_work_node(p_node){}
        ~data_group(){}
        wyxCThreadPool* get_m_work_pool()
        {
            return m_work_pool;
        }
        work_node* get_m_work_node()
        {
            return m_work_node;
        }
};

void* work_func(void* data)
{
    sleep(3);
    wyxCTask* tmp_task = (wyxCTask*)data;
    work_node* tmp_data =(work_node*)tmp_task->get_m_data();
    string test_str(tmp_data->get_m_p_c());
    cout<<"task char* is "<<test_str<<endl;
    delete tmp_data;
    tmp_data = NULL;
}

void* add_task_to_threadpool(void* data)
{
    data_group* p_data = (data_group*)data;
    wyxCThreadPool* p_tmp_threadpool = p_data->get_m_work_pool();
    work_node* p_tmp_work_node = p_data->get_m_work_node();

    wyxCTask* tmp_task = new wyxCTask((void*)p_tmp_work_node);
    tmp_task->set_m_work( work_func);
    p_tmp_threadpool->m_push_task_to_queue(tmp_task, NULL);

    return (void*)0;
}

int main(int argc, char* argv[])
{
    //创建线程池
    wyxCThreadPool test_threadpool(1);
    int task_num = 0;
    const char* p_test_char = "Hello, world!";
    for(;task_num < 10; task_num++)
    {
        //构造任务节点
        work_node* p_work_node = new work_node(p_test_char);
        data_group my_data (&test_threadpool, p_work_node);
        //向线程池中添加任务
        add_task_to_threadpool((void*)&my_data);
    }
    //结束程序
    while(!test_threadpool.threadpool_is_relax()){}
    sleep(3);
}





