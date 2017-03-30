// Last Update:2017-03-30 16:30:20
/**
 * @file arrange_table.h
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-30
 */

#ifndef ARRANGE_TABLE_H
#define ARRANGE_TABLE_H

#include "log_message.h"
#include "handle.h"
#include "produce_handle.h"
#include <list>
#include <vector>
#include <map>
using std::list;
using std::vector;
using std::map;

class arrange_table
{
    private:
        list<log_message*> * m_p_msg_list;
        map<string, string> m_map;
        vector<handle*> m_vec;
    public:
        arrange_table();
        virtual ~arrange_table(){}
        bool init_arrange_table(xmlNodePtr&);
        bool arrange();
};


#endif  /*ARRANGE_TABLE_H*/
