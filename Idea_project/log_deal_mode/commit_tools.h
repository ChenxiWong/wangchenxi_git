// Last Update:2016-08-01 12:08:13
/**
 * @file commit_tools.h
 * @brief :
 * @author zhangqi
 * @version 0.1.00
 * @date 2015-04-27
 */

#ifndef COMMIT_TOOLS_H
#define COMMIT_TOOLS_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdint.h>
#include <sys/stat.h>
#include <vector>
#include <arpa/inet.h>

#include <sys/types.h> 
#include <unistd.h> 
#include <sstream>
#include <ctype.h>
#include <iconv.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <sys/time.h>

using namespace std;

#define DNUMTOSTR(n,s) \
{ std::stringstream ss; \
        ss<<n; \
        s+=std::string(ss.str()) ;\
        ss.clear(); }


//比较字符str 的尾部是不是  str1 
bool cmp_wiat_end(char * str,const  char * str1);

bool cmpn_wiat_end(char * str,int len ,const  char * str1);

char * splits_string(char * srcstr ,char splits_sign ) ;

string date_time();
string hour_time();
string date_time2(time_t t);
string date_time3(time_t t);

string get_year_month();
string get_day_hour();
string get_min_sec();
void create_path(string path);

string base64_encode(const unsigned char* Data,int DataByte);
string base64_decode(const char* Data,int DataByte,int& OutByte);

uint32_t crc32( unsigned char *buf, int len);
void  splitEx(const string src, string separate_character , vector<string> &strs);
bool char_path_parse(char * &src_path , char * node) ;
string&   replace_all(string&   str,const   string&   old_value,const   string&   new_value);

uint16_t parse_buf2uint16N(char * buf, int offise);
uint16_t parse_buf2uint16H(char * buf, int offise);

uint32_t parse_buf2uint32N(char * buf, int offise);
uint32_t parse_buf2uint32H(char * buf, int offise);
char * c_to_shell(const char * cmd ,char * out ,int len);
void replace_str(string &original_str, string old_str, string new_str);
double s2f(const string& src);

string del_unsign_char(string s_username); //用于去除字符串中的不可见字符

int HandleEscapeChar(unsigned char *pbuf, unsigned char *res);
int html_to_txt(char *poutbuf, int &olen, const char *pinbuf, int inlen);
const char * StrnLowStr(const char *buf, int len, const char *pattern, int length);
string strncpytoc(string& str ,int n , char  c  );
// 从缓存中获取字符串
bool get_string_from_http_buffer(string& aim_str,const char* p_buffer,const char* start_sign,const char* end_sign,int aim_str_start,int aim_str_end_to_end_sign,int* p_deal_len = NULL, int* p_no_useful_len = NULL);
int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen);
int u2g(char *inbuf, size_t inlen, char *outbuf, size_t outlen);
int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen);
int unicode_to_utf8_1(uint32_t unic, unsigned char* pOutput, int outSize);
bool unic2utf(string& svalue, string& flag);
void classify_ip_kind_info(string  ip_str, int& is_ipv6, int& is_ipv4);
//祛除字符串中因字符集问题导致的乱码。
//该函数仅仅支持字符串编码格式为带u、U的Unicode编码、GBK编码转换为UTF-8编码  王晨曦添加
void get_rid_of_garbled(string& answer_str, string& question_str);
string& trim(string &s);  // string 去空格 
string reserved_number(string& a) ; //去掉字符串中除了数字和点以为的其他串
string strassigntoc(string& str ,int n , char  c  );
uint64_t get_local_time64();

#endif  /*COMMIT_TOOLS_H*/
