// Last Update:2017-04-01 18:14:57
/**
 * @file jscon_parse.h
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-01
 */

#ifndef JSCON_PARSE_H
#define JSCON_PARSE_H

#include "commit_tools.h"


#include <string>
#include "json/json.h"

using std::string;




//***********************
// json 解析
//*************************** 
//**************************
//json 不同数据类型解析出不同的 
// 最后转换成string 型数据
//**************************
bool  json_value(Json::Value &  node ,string & value)
{
    if(node.isString())
    {
        value = node.asString();
        return true ;
    }
    switch(node.type())
    {
        case Json::nullValue:
            return true;
        case Json::realValue: // 
            DNUMTOSTR(node.asDouble(),value);
            return true; 
        case Json::intValue:
            DNUMTOSTR(node.asInt(),value);
            return true;
        case Json::uintValue:
            DNUMTOSTR((uint32_t)node.asInt(),value);
            return true; 
        case Json::stringValue:
            value = node.asString();
            return true;
        case Json::booleanValue:
            if(node.asBool())
            {
                value= "true";
            }
            else 
            {
                value = "false";
            }
            return true; 
        case Json::arrayValue:
            {
             int size = node.size();
              for ( int index =0; index < size; ++index ) 
              {
                json_value( node[index],value);
              }
              return true;
            }
        default:
            return false;
    }
}

string  json_key_value(Json::Value  node , string dir ) 
{
    // 解析多层
    int off = 0 ;
    string value = "";
    for(;;)
    {
        string tmp = strncpytoc(dir,0,'/');
        if(tmp == dir )
        {
         //   return node.get(tmp,"null").asString();
                value ="";
                json_value(node[tmp],value);
                return value;
              //  return node[tmp].asString();

        }
       // if(tmp[tmp.length()-1] == '[')
       if(node[tmp].type()== Json::arrayValue )
        {
           dir = string(dir ,tmp.length()+1,dir.length());
           //tmp.erase(tmp.rbegin());
           int node_size = node[tmp].size() ;
            string tmp1 = strncpytoc(dir,0,'/') ;
            for(int i = 0; i < node_size; ++i)
            {
                if(tmp1 == dir )
                {
                        //return  node[tmp][i][tmp1].asString() ;
                        value ="";
                        json_value(node[tmp][i][tmp1],value);
                        return value;
                }
                else 
                {
                    if(!node[tmp].isNull())
                    {
                        node  = node[tmp][i][tmp1];
                        dir = string(dir ,tmp1.length()+1,dir.length());
                    }
                }
            }
        }
        else  if(node[tmp].type()== Json::objectValue)
        {
            if(tmp == dir)
            {
                value ="";
                json_value(node[tmp],value);
                return value;
                //return node[tmp].asString();
            }
            else 
            {
                if(!node[tmp].isNull())
                {
                  node = node[tmp];
                }
                dir = string(dir ,tmp.length()+1,dir.length());
            }
        }
        else {
                value ="";
                json_value(node[tmp],value);
                return value;

        }

       // node = node[""]
    }
    return value;
}

#endif  /*JSCON_PARSE_H*/
