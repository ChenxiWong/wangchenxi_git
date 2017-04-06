// Last Update:2016-09-10 14:56:53
/**
 * @file main.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-09-10
 */
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include "wyxstd.h"

void parseConfig(xmlDocPtr doc, xmlNodePtr cur, const char* label)
{
    xmlChar* key;
    cur =  cur->xmlChildrenNode;
    while(cur != NULL)
    {
        if((!xmlStrcmp(cur->name, (const xmlChar*)label)))
        {
            key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("%s: %s\n", label, key);
            xmlFree(key);
        }
        cur = cur->next;
    }
    return;
}

int main(int argc, char*argv[])
{
    xmlDocPtr doc;
    xmlNodePtr cur;

    doc = xmlParseFile("./ftp_plugin.xml");

    if(doc == NULL)
    {
        fprintf(stderr, "Document not parsed successfully. \n");
        return 0;
    }

    cur = xmlDocGetRootElement(doc);

    if(cur == NULL)
    {
        fprintf(stderr, "empty document\n");
        xmlFreeDoc(doc);
        return 0;
    }
    if(xmlStrcmp(cur->name, (const xmlChar*) "config"))
    {
        fprintf(stderr, "document of the wrong type, root node != config\n");
        xmlFreeDoc(doc);
        return 0;
    }
    cur =  cur->xmlChildrenNode;
    if(cur == NULL)
    {
        fprintf(stderr, "empty node\n");
        xmlFreeDoc(doc);
        return 0;
    }
    xmlChar* key;
    while(cur != NULL)
    {
        if(!xmlStrcmp(cur->name, (const xmlChar*)"send_data_type"))
        {
            parseConfig(doc, cur, "test");
        }
        /*if(!xmlStrcmp(cur->name, (const xmlChar*)"time_out"))
        {
            xmlChar* key;
            key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("value: %s\n",  key);
            xmlFree(key);
        }*/
        printf("cur->name: %s\n", (const char*)cur->name);
        xmlChar* key;
        key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
        printf("value: %s\n",  key);
        xmlFree(key);
        cur = cur->next;
    }
    return 0;
}

/*xmlXPathObjectPtr getnodeset(xmlDocPtr doc,const xmlChar* xpath)
  {
  xmlXPathContextPtr context;
  xmlXPathObjectPtr result;

  context = xmlXPathNewContext(doc);
  result = xmlXPathEvalExpression(xpath, context);
  if(xmlXPathNodeSetIsEmpty(result->nodesetval))
  {
  xmlXPathFreeObject(result);
  printf("No result\n");
  return NULL;
  }
  return result;
  }
  */

/*int main(int argc, char* argv[])
  {
  xmlDocPtr doc;

  doc = xmlParseFile("./ftp_plugin.xml");
  xmlChar* keyword;

  xmlXPathObjectPtr nodeset = getnodeset(doc, (const xmlChar*)"time_out");
  for(int i=0; i < nodeset->Nr; i++)
  {
  keyword = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
  printf("keyword : %s\n", keyword);
  xmlFree(keyword);
  }
  }*/











