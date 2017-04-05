// Last Update:2017-03-30 16:43:15
/**
 * @file arrange_table.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */

#include "arrange_table.h"

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xmlsave.h>

#include <string>
#include <list>
#include <vector>
#include <map>

using std::string;
using std::list;
using std::vector;
using std::map;

arrange_table::arrange_table(){}

void arrange_table::set_m_p_msg_list(list<log_message*>* p_list)
{
    m_p_msg_list = p_list;
}

bool arrange_table::arrange(list<log_message*>* p_list)
{
    set_m_p_msg_list(p_list);
    //handle::run();
}

bool arrange_table::init_arrange_table(xmlNodePtr node)
{
    xmlNodePtr curNode;
    curNode = node->xmlChildrenNode;
    string str_content("");
    for(; curNode != NULL; curNode = curNode->next)
    {
        if(0 == xmlStrcmp(curNode->name, BAD_CAST("handle")))
        {
            str_content.clear();
            str_content = (char*)xmlNodeGetContent(curNode);
            handle* p_handle = produce_handle::get_instance()->produce_handle_pointer(str_content);
            str_content.clear();
            str_content = (char*)xmlGetProp(curNode , BAD_CAST "argv");
            p_handle->init_handle(str_content, &m_map);
            p_handle->handle_getopt();
            m_vec.push_back(p_handle);
        }
    }
}
