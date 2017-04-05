// Last Update:2017-03-31 09:11:26
/**
 * @file log_analysiser.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-31
 */

#include "log_analysiser.h"

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xmlsave.h>

#include <list>
#include <unistd.h>

using std::list;

void log_analysiser::xml_parse()
{
    xmlDocPtr doc;
    xmlNodePtr curNode;
    xmlChar* szkey;
    string xmlstr(m_xml_path.c_str());
    doc = xmlReadFile(xmlstr.c_str(), "UTF-8", XML_PARSE_RECOVER);
    curNode = xmlDocGetRootElement(doc);
    if (0 == xmlStrcmp(curNode->name, BAD_CAST "log_config"))
    {
        curNode = curNode->xmlChildrenNode;
        for(; curNode != NULL; curNode = curNode->next)
        {
            if(0 == xmlStrcmp(curNode->name, BAD_CAST("mysql")))
            {
                m_p_read_mysql = new read_mysql(curNode); // 需要去改进实现
            }else if(0 == xmlStrcmp(curNode->name, BAD_CAST("table")))
            {
                arrange_table* p_table = new arrange_table();
                p_table->init_arrange_table(curNode);//需要去实现
                m_table_list.push_back(p_table);
            }
        }
    }
    xmlFreeDoc(doc);
}


log_analysiser::log_analysiser(const char* tmp_xml_path)
{
    m_xml_path = tmp_xml_path;
    xml_parse();
}

log_analysiser::log_analysiser(log_analysiser& tmp)
{
    m_xml_path = tmp.m_xml_path;
    xml_parse();
}


log_analysiser& log_analysiser::operator= (log_analysiser& tmp)
{
    this->m_xml_path = tmp.m_xml_path;
    this->xml_parse();
}

bool log_analysiser::one_arrange_table(list<log_message*>* p_list, arrange_table* p_arrange)
{
    ++m_thread_num;
    p_arrange->arrange(p_list);
    --m_thread_num;
}

void* log_analysiser::analysis()
{
    while(1)
    {
        m_p_read_mysql->first_stemp_work();
        if(m_p_read_mysql->first_stemp_result.size() > 0)
        {
            for(list<arrange_table*>::iterator iter = m_table_list.begin(); iter != m_table_list.end(); ++iter)
            {
                one_arrange_table(&(m_p_read_mysql->first_stemp_result), *iter); // 可以使用多线程
            }
        }else{
            sleep(m_p_read_mysql->m_space_time);
        }
    }
}
