// Last Update:2016-09-22 09:46:46
/**
 * @file wyxstd.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-09-22
 */

#include "wyxdef.h"
#include "wyxstd.h"

bool get_string_from_http_buffer(string& aim_str,const char* p_buffer,const char* start_sign,const char* end_sign,int aim_str_start,int aim_str_end_to_end_sign, int* p_deal_len, int* p_no_useful_len)
{
    if(NULL == p_buffer)
    {
        return false;
    }
    char* p_start = NULL;
    char* p_end = NULL;
    if(NULL != start_sign)
    {
        if(1 == strlen(start_sign))
        {
            char tmp = *start_sign;
            p_start = const_cast<char*>(strchr(p_buffer, tmp));
        }else
        {
            p_start = const_cast<char*>(strstr(p_buffer, start_sign));
        }
        if(NULL == p_start)
        {
            return false;
        }
    }else
    {
        p_start = const_cast<char*>(p_buffer);
    }
    if( NULL == end_sign)
    {
        aim_str = p_start + aim_str_start;
        if(p_deal_len != NULL)
        {
            char* p_deal = NULL;
            p_deal = p_start + aim_str_start + aim_str.size();
            *p_deal_len = p_deal - p_buffer;
        }
        if(p_no_useful_len != NULL)
        {
            *p_no_useful_len = p_start - p_buffer;
        }
        return true;
    }else if(1 == strlen(end_sign))
    {
        char tmp = *end_sign;
        p_end = strchr(p_start + aim_str_start, tmp);
    }else
    {
        p_end = strstr(p_start + aim_str_start, end_sign);
    }
    if(NULL == p_end)
    {//该部分代码有待进一步思考处理
        aim_str = p_start + aim_str_start;
        if(p_deal_len != NULL)
        {
            char* p_deal = NULL;
            p_deal = p_start + aim_str_start + aim_str.size();
            *p_deal_len = p_deal - p_buffer;
        }
        if(p_no_useful_len != NULL)
        {
            *p_no_useful_len = p_start - p_buffer;
        }
        return true;
    }
    int aim_len = p_end - p_start - aim_str_start - aim_str_end_to_end_sign;
    if(aim_len < 0)
    {
        return false;
    }
    string tmp_aim(p_start, aim_str_start, aim_len);
    aim_str = tmp_aim;
    if(p_deal_len != NULL)
    {
        char* p_deal = NULL;
        p_deal = p_end + strlen(end_sign);
        *p_deal_len = p_deal - p_buffer;
    }
    if(p_no_useful_len != NULL)
    {
        *p_no_useful_len = p_start - p_buffer;
    }
    return true;
}


string&   replace_all(string&   str,const   string&   old_value,const   string&   new_value)
{
    while(true)   {
        string::size_type   pos(0);
        if(   (pos=str.find(old_value))!=string::npos   )
            str.replace(pos,old_value.length(),new_value);
        else   break;
    }
    return   str;
}


int code_convert(const char *from_charset, const char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
    iconv_t cd;
    char **pin = &inbuf;
    char **pout = &outbuf;

    cd = iconv_open(to_charset, from_charset);
    if (cd == 0)
        return -1;
    memset(outbuf, 0, outlen);
    if (iconv(cd, pin, &inlen, pout, &outlen) == -1)
        return -1;
    iconv_close(cd);
    *pout = '\0';

    return 0;
}

int u2g(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
    return code_convert("utf-8", "gb2312", inbuf, inlen, outbuf, outlen);
}

int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
    return code_convert("gb2312", "utf-8", inbuf, inlen, outbuf, outlen);
}

//IPV4、IPV6判断，需要进一步完善
void classify_ip_kind_info(string  ip_str, int& is_ipv6, int& is_ipv4)
{
    is_ipv6 = 0;
    is_ipv4 = 0;
    size_t pos = ip_str.find(".");
    if(pos == string::npos)
    {
        pos = ip_str.find(":");
        if(pos != string::npos)
        {
            is_ipv6 = 1;
            is_ipv4 = 0;
        }
    }
    else
    {
        is_ipv4 = 1;
        is_ipv6 = 0;
    }

}

//----------------需要改进
void create_path(string& path)
{
    size_t pre=2;
    size_t pos = path.find_first_of('/', pre);
    if(pos == string::npos)
        return;

    pre = ++pos;

    string dir;
    while((pos=path.find_first_of('/',pre)) != string::npos)
    {
        dir = path.substr(0, pos++);
        pre = pos;
        if(dir.size() == 0)
            continue;
        mkdir(dir.c_str(),0777);
    }
}

bool is_bigendian()
{
    if( big_little_signe == 0)
    {
        four_char union_ex;
        memset(union_ex.code, 0, 4);
        union_ex.code[0] = 1;
        if(union_ex.num == 1)
        {
            union_ex.code[0] = 0;
            big_little_signe = 1;
            return false;
        }
        big_little_signe = 2;
        return true;
    }
    else if( big_little_signe == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int unicode_to_utf8_1(uint32_t unic, unsigned char* pOutput, int outSize){
    if(!pOutput || outSize < 6)
        return 0;
    if(unic < 0x0000007F){
        //U 00000000 - U 0000007F : 0xxxxxxx
        *pOutput = (unic & 0x7F);
        return 1;
    }
    else if(unic >= 0x00000080 && unic <= 0x000007FF){
        //U 00000080 - U 000007FF :110xxxxx 10xxxxxx
        *(pOutput + 1) = (unic & 0x3F) | 0x80;
        *pOutput       = ((unic >> 6) & 0x1F) | 0xC0;
        return 2;
    }
    else if (unic >= 0x00000800 && unic <= 0x0000FFFF){
        //U 00000800 - U 0000FFFF : 1110xxxx 10xxxxxx 10xxxxxx
        *(pOutput + 2) = (unic & 0x3F) | 0X80;
        *(pOutput + 1) = ((unic >>  6) & 0x3F) | 0x80;
        *pOutput       = ((unic >> 12) & 0x0F) | 0xE0;
        return 3;
    }
    else if(unic >= 0x00010000 && unic <= 0x001FFFFF){
        //U 00010000 - U 001FFFFF : 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
        *(pOutput + 3) = (unic & 0x3F) | 0x80;
        *(pOutput + 2) = ((unic >>  6) & 0x3F) | 0x80;
        *(pOutput + 1) = ((unic >> 12) & 0x3F) | 0x80;
        *pOutput       = ((unic >> 18) & 0x07) | 0xF0;
        return 4;
    }
    else if(unic >= 0x00200000 && unic <= 0x03FFFFFF){
        //U 00200000 - U 03FFFFFF : 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
        *(pOutput + 4) = (unic & 0x3F) | 0x80;
        *(pOutput + 3) = ((unic >>  6) & 0x3F) | 0x80;
        *(pOutput + 2) = ((unic >> 12) & 0x3F) | 0x80;
        *(pOutput + 1) = ((unic >> 18) & 0x3F) | 0x80;
        *pOutput       = ((unic >> 24) & 0x03) | 0xF8;
        return 5;
    }
    else if(unic >= 0x04000000 && unic <= 0x7FFFFFFF){
        //U 04000000 - U 7FFFFFFF : 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
        *(pOutput + 5) = (unic & 0x3F) | 0x80;
        *(pOutput + 4) = ((unic >>  6) & 0x3F) | 0x80;
        *(pOutput + 3) = ((unic >> 12) & 0x3F) | 0x80;
        *(pOutput + 2) = ((unic >> 18) & 0x3F) | 0x80;
        *(pOutput + 1) = ((unic >> 24) & 0x3F) | 0x80;
        *pOutput       = ((unic >> 30) & 0x01) | 0xFC;
        return 6;
    }
}

bool unic2utf(string& svalue, string& flag)
{
    string::size_type now = 0;
    string::size_type cur = svalue.find(flag);
    int len = flag.size();
    int len1 = svalue.size();
    string goods = "";
    while (cur != string::npos)
    {
        goods += svalue.substr(now, cur-now);
        char arr[6];
        memset(arr, 0, 6);
        if (cur+len+4 <= len1)
        {
            string str_flag = svalue.substr(cur+len, 4);
            uint32_t i = strtoul(str_flag.c_str(), 0, 16);
            unicode_to_utf8_1(i, (unsigned char*)arr, 6);
            goods += arr;
            now = cur+4+len;
            cur = svalue.find(flag, now);
            if (cur == string::npos)
            {
                goods += svalue.substr(now);
            }
        }
        else
        {
            return false;
        }
    }
    if (goods.size() == 0)
    {
        return false;
    }
    else
    {
        svalue = "";
        svalue = goods;
        return true;
    }
}

bool gbk_invisible(unsigned short short_tmp, unsigned int* low_line, unsigned int* high_line)
{
    while(*low_line != 0 && *high_line != 0)
    {
        if( *low_line <= short_tmp && *high_line >= short_tmp)return true;
        ++low_line;
        ++high_line;
    }
    return false;
}

bool utf_visible(unsigned int short_tmp, unsigned int* low_line, unsigned int* high_line)
{
    while(*low_line != 0 && *high_line != 0)
    {
        if( *low_line <= short_tmp && *high_line >= short_tmp)
        {
            return true;
        }
        ++low_line;
        ++high_line;
    }
    return false;
}

bool gbk_judgement(unsigned char* c_tmp)
{
    two_char union_tmp;
    while(*c_tmp)
    {
        if(*c_tmp <= 0x7F)
        {
            ++c_tmp;
            continue;
        }else
        {
            if(is_bigendian())
            {
                union_tmp.code[0] = *c_tmp;
                ++c_tmp;
                union_tmp.code[1] = *c_tmp;
            }
            else
            {
                union_tmp.code[1] = *c_tmp;
                ++c_tmp;
                union_tmp.code[0] = *c_tmp;
            }
            if( *c_tmp == 0x7F || *c_tmp == 0xFF)
            {
                return false;
            }
            if(union_tmp.num == 0xA2E4)return false;
            unsigned int low_arry[]={
                0XA140,0XA240,0XA2AB,0XA2EF,0XA2CF,0XA340,0XA440,0XA4F4,0XA540,0XA5F7,0XA640,0XA6F6,0XA6B9,
                0XA740,0XA7C2,0XA7F2,0XA896,0XA8AB,0XA8BB,0XA8C1,0XA8EA,0XA95D,0XA997,0XA9F3,0XAAA2,0XABA2,
                0XACA2,0XADA2,0XAEA2,0XAFA2,0XF8A2,0XF9A2,0XFAA2,0XFBA2,0XFCA2,0XFDA2,0XFEA2,0
            };
            unsigned int high_arry[]={
                0XA1A1,0XA2A0,0XA2B0,0XA2F0,0XA2DF,0XA3A0,0XA4A0,0XA4FE,0XA5A0,0XA5FE,0XA6A0,0XA6FE,0XA6BF,
                0XA7A0,0XA7D0,0XA7FE,0XA8A0,0XA8AF,0XA8BF,0XA8C4,0XA8FE,0XA95F,0XA99F,0XA9FE,0XAAFE,0XABFE,
                0XACFE,0XADFE,0XAEFE,0XAFFE,0XF8FE,0XF9FE,0XFAFE,0XFBFE,0XFCFE,0XFDFE,0XFEFE,0
            };
            if(gbk_invisible(union_tmp.num, low_arry, high_arry))
            {
                return false;
            }
        }
        ++c_tmp;
    }
    return true;
}

void gbk_to_utf(string& answer_str, string& question_str)
{
    int dst_size = 4 * question_str.size();
    char* c_dst = new char[dst_size + 1];
    if(c_dst == NULL)
    {
        return;
    }
    memset(c_dst, 0, dst_size + 1);
    char* c_src = const_cast<char*>(question_str.c_str());
    g2u(c_src, question_str.size(), c_dst, dst_size);
    if(dst_size < 0)
    {
        delete [] c_dst;
        return;
    }
    answer_str = c_dst;
    delete [] c_dst;
    c_dst = NULL;
    return;
}

void little_endian_deal(four_char* p_union, int num, unsigned char* c_arry)
{
    switch(num)
    {
        //小端处理情况。
        case 1:
            {
                p_union->code[1] = p_union->code[1]|((c_arry[0]>> 2)&0x07);
                p_union->code[0] = p_union->code[0]|((c_arry[0]<<6)&0xC0);
                p_union->code[0] = p_union->code[0]|(c_arry[1]&0x3F);
                break;
            }
        case 2:
            {
                p_union->code[1] = ((c_arry[0]<<4)&0xF0)|p_union->code[1];
                p_union->code[1] = ((c_arry[1]>>2)&0x0F)|p_union->code[1];
                p_union->code[0] = ((c_arry[1]<<6)&0xC0)|p_union->code[0];
                p_union->code[0] = (c_arry[2]&0x3F)|p_union->code[0];
                break;
            }
        case 3:
            {
                p_union->code[2] = ((c_arry[0]<<2)&0x1C)|p_union->code[2];
                p_union->code[2] = ((c_arry[1]>>4)&0x03)|p_union->code[2];
                p_union->code[1] = ((c_arry[1]<<4)&0xF0)|p_union->code[1];
                p_union->code[1] = ((c_arry[2]>>2)&0x0F)|p_union->code[1];
                p_union->code[0] = ((c_arry[2]<<6)&0xC0)|p_union->code[0];
                p_union->code[0] = (c_arry[3]&0x3F)|p_union->code[0];
                break;
            }
        case 4:
            {
                p_union->code[3] = (c_arry[0]&0x03)|p_union->code[3];
                p_union->code[2] = ((c_arry[1]<<2)&0xFC)|p_union->code[2];
                p_union->code[2] = ((c_arry[2]>>4)&0x03)|p_union->code[2];
                p_union->code[1] = ((c_arry[2]<<4)&0xF0)|p_union->code[1];
                p_union->code[1] = ((c_arry[3]>>2)&0x0F)|p_union->code[1];
                p_union->code[0] = ((c_arry[3]<<6)&0x30)|p_union->code[0];
                p_union->code[0] = (c_arry[4]&0xCF)|p_union->code[0];
                break;
            }
        case 5:
            {
                p_union->code[3] = ((c_arry[0]<<7)&0x40)|p_union->code[3];
                p_union->code[3] = (c_arry[1]&0x3F)|p_union->code[3];
                p_union->code[2] = ((c_arry[2]<<2)&0xFC)|p_union->code[2];
                p_union->code[2] = ((c_arry[3]>>4)&0x03)|p_union->code[2];
                p_union->code[1] = ((c_arry[3]<<4)&0xF0)|p_union->code[1];
                p_union->code[1] = ((c_arry[4]>>2)&0x0F)|p_union->code[1];
                p_union->code[0] = ((c_arry[4]<<6)&0xC0)|p_union->code[0];
                p_union->code[0] = (c_arry[5]&0x3F)|p_union->code[0];
                break;
            }
        default:
            {
                break;
            }
    }
    return;
}

void big_endian_deal(four_char* p_union, int num, unsigned char* c_arry)
{
    switch(num)
    {
        //大端处理情况。
        case 1:
            {
                p_union->code[2] = p_union->code[2]|((c_arry[0]>> 2)&0x07);
                p_union->code[3] = p_union->code[3]|((c_arry[0]<<6)&0xC0);
                p_union->code[3] = p_union->code[3]|(c_arry[1]&0x3F);
                break;
            }
        case 2:
            {
                p_union->code[2] = ((c_arry[0]<<4)&0xF0)|p_union->code[2];
                p_union->code[2] = ((c_arry[1]>>2)&0x0F)|p_union->code[2];
                p_union->code[3] = ((c_arry[1]<<6)&0xC0)|p_union->code[3];
                p_union->code[3] = (c_arry[2]&0x3F)|p_union->code[3];
                break;
            }
        case 3:
            {
                p_union->code[1] = ((c_arry[0]<<2)&0x1C)|p_union->code[1];
                p_union->code[1] = ((c_arry[1]>>4)&0x03)|p_union->code[1];
                p_union->code[2] = ((c_arry[1]<<4)&0xF0)|p_union->code[2];
                p_union->code[2] = ((c_arry[2]>>2)&0x0F)|p_union->code[2];
                p_union->code[3] = ((c_arry[2]<<6)&0xC0)|p_union->code[3];
                p_union->code[3] = (c_arry[3]&0x3F)|p_union->code[3];
                break;
            }
        case 4:
            {
                p_union->code[0] = (c_arry[0]&0x03)|p_union->code[0];
                p_union->code[1] = ((c_arry[1]<<2)&0xFC)|p_union->code[1];
                p_union->code[1] = ((c_arry[2]>>4)&0x03)|p_union->code[1];
                p_union->code[2] = ((c_arry[2]<<4)&0xF0)|p_union->code[2];
                p_union->code[2] = ((c_arry[3]>>2)&0x0F)|p_union->code[2];
                p_union->code[3] = ((c_arry[3]<<6)&0x30)|p_union->code[3];
                p_union->code[3] = (c_arry[4]&0xCF)|p_union->code[3];
                break;
            }
        case 5:
            {
                p_union->code[0] = ((c_arry[0]<<7)&0x40)|p_union->code[0];
                p_union->code[0] = (c_arry[1]&0x3F)|p_union->code[0];
                p_union->code[1] = ((c_arry[2]<<2)&0xFC)|p_union->code[1];
                p_union->code[1] = ((c_arry[3]>>4)&0x03)|p_union->code[1];
                p_union->code[2] = ((c_arry[3]<<4)&0xF0)|p_union->code[2];
                p_union->code[2] = ((c_arry[4]>>2)&0x0F)|p_union->code[2];
                p_union->code[3] = ((c_arry[4]<<6)&0xC0)|p_union->code[3];
                p_union->code[3] = (c_arry[5]&0x3F)|p_union->code[3];
                break;
            }
        default:
            {
                break;
            }
    }
    return;
}

bool utf_judgement(unsigned char* p_tmp, int i)
{
    int int_tmp = 0;
    unsigned char c_arry[6];
    memset(c_arry, 0, 6);
    char tmp = 0;
    c_arry[int_tmp] = *p_tmp;
    ++p_tmp;
    four_char union_four;
    memset(union_four.code, 0, 4);
    unsigned char c_tmp = 0x0;
    while( *p_tmp >= 0x80 && *p_tmp <= 0xBF)
    {
        ++int_tmp;
        c_arry[int_tmp] = *p_tmp;
        ++p_tmp;
        if(int_tmp == i)
        {
            //通过联合将utf-8转换成unicode码，进行不可见字符判断。
            if(is_bigendian())
            {
                // 大端状态下进行转换
                big_endian_deal(&union_four, i, c_arry);
            }
            else
            {
                //小端状态下进行转换
                little_endian_deal(&union_four, i, c_arry);
            }
            //可见字符范围下限
            unsigned int low_arry[] = {
                0X0F00,0X0F49,0X0F71,0X0F99,0X0FBE,0X0FCE,0X0060,0X061E,0X2E80,0X2E9B,0X2F00,0X2FF0,0X3000,0X3041,
                0X3099,0X3105,0X3131,0X3190,0X31C0,0X31F0,0X3220,0X3300,0X3400,0XFE30,0XFE53,0XFE68,0XFE70,0XFE76,
                0XFEFF,0XFF02,0XFFC2,0XFFCA,0XFFD2,0XFFDA,0XFFE0,0X0001,0X370A,0X3804,0X380E,0X0750,0X08B6,0X1800,
                0X380C,0X03A3,0X08A0,0X08D4,0X1810,0X1820,0X1880,0X1D00,0X2000,0X2066,0X2070,0X2090,0X20A0,0X20D0,
                0X2100,0X2150,0X2190,0X2400,0X2440,0X2460,0X2B79,0X2B98,0X2BBD,0X2BCA,0X2BEC,0
            };
            //可见字符范围上限
            unsigned int high_arry[] = {
                0X0F47,0X0F6C,0X0F97,0X0FBC,0X0FCC,0X0FDA,0X061C,0X06FF,0X2E99,0x2EF3,0X2FD6,0X2FFB,0X303F,0X3096,
                0X30FF,0X312D,0X318E,0X31BA,0X31E3,0X321E,0X32FE,0X33FF,0X9FFF,0XFE52,0XFE66,0XFE6B,0XFE74,0XFEFC,
                0XFEFF,0XFFBE,0XFFC7,0XFFCF,0XFFD7,0XFFDC,0XFFEE,0X3707,0X370F,0X380A,0X03A1,0X077F,0X08BD,0X180E,
                0X380C,0X03F0,0X08B4,0X08FF,0X1819,0X1877,0X18AA,0X1DBF,0X2064,0X206F,0X208E,0X209C,0X20BE,0X20F0,
                0X214F,0X218B,0X23FE,0X2426,0X244A,0X2B73,0X2B95,0X2BB9,0X2BC8,0X2BD1,0X2BEF,0
            };
            if(!utf_visible(union_four.num, low_arry, high_arry))return false;
            //需要添加大小端处理情况。
            break;
        }
    }
    return true;
}

// 有待改进
bool find_flag(string& answer_str,string& flag)
{
    char* c_tmp = const_cast<char*>(answer_str.c_str());
    char c_arry[] = {'\\','u',0};
    char c_arry1[] = {'\\','U',0};
    char c_arry2[] = {'%','u',0};
    char c_arry3[] = {'%','U',0};
    char* flagv[4] ={c_arry, c_arry1, c_arry2, c_arry3};
    int i = 0;
    char* pos = NULL;
    for(;i < 4;++i)
    {
        pos = strstr( c_tmp, flagv[i]);
        if( pos != NULL)
        {
            char hex_char[] = "0123456789abcdefABCDEF";
            for(i = 1;i < 5; ++i)
            {
                c_tmp = strchr(hex_char, *(pos + i ));
                if(c_tmp == NULL)return false;
            }
            flag = flagv[i];
            return true;
        }
    }
    return false;
}

void deal_answer_str_find_unicode_form(string& answer_str)
{
    string flag("");
    if(find_flag(answer_str, flag))
    {
        unic2utf(answer_str, flag);
        return ;
    }
    return;
}

void get_rid_of_garbled(string& answer_str, string& question_str)
{
    char* c_tmp_1 = const_cast<char*>(question_str.c_str());
    unsigned char* c_tmp = (unsigned char*)c_tmp_1;
    while(*c_tmp)
    {
        if(*c_tmp <= 0x7F)
        {
            //是ASC码
            ++c_tmp;
            continue;
        }
        else if(*c_tmp >= 0x80 && *c_tmp <= 0xBF)
        {
            //GBK码
            gbk_to_utf(answer_str, question_str);
            deal_answer_str_find_unicode_form(answer_str);
            return;
        }
        else if(*c_tmp >= 0xC0 && *c_tmp <= 0xDF)
        {
            //双字节utf-8
            if(!utf_judgement(c_tmp, 1))
            {
                gbk_to_utf(answer_str, question_str);
                deal_answer_str_find_unicode_form(answer_str);
                return;
            }
            c_tmp += 2;
            continue;
        }
        else if(*c_tmp >= 0xE0 && *c_tmp <= 0xEF)
        {
            //三字节utf-8
            if(!utf_judgement(c_tmp, 2))
            {
                gbk_to_utf(answer_str, question_str);
                deal_answer_str_find_unicode_form(answer_str);
                return;
            }
            c_tmp += 3;
            continue;
        }
        else if(*c_tmp >= 0xF0 && *c_tmp <= 0xF7)
        {
            //四字节utf-8
            if(!utf_judgement(c_tmp, 3))
            {
                gbk_to_utf(answer_str, question_str);
                deal_answer_str_find_unicode_form(answer_str);
                return;
            }
            c_tmp += 4;
            continue;
        }
        else if(*c_tmp >= 0xF8 && *c_tmp <= 0xFB)
        {
            //五字节utf-8
            if(!utf_judgement(c_tmp, 4))
            {
                gbk_to_utf(answer_str, question_str);
                deal_answer_str_find_unicode_form(answer_str);
                return;
            }
            c_tmp += 5;
            continue;
        }
        else if(*c_tmp >= 0xFC && *c_tmp <= 0xFD)
        {
            //六字节utf-8
            if(!utf_judgement(c_tmp, 5))
            {
                gbk_to_utf(answer_str, question_str);
                deal_answer_str_find_unicode_form(answer_str);
                return;
            }
            c_tmp += 6;
            continue;
        }
        else
        {
            gbk_to_utf(answer_str, question_str);
            deal_answer_str_find_unicode_form(answer_str);
            return;
        }
    }
    answer_str = question_str;
    deal_answer_str_find_unicode_form(answer_str);
    return;
}

//待查詢資料完善
void deal_pcre_url(string& pcre_url, string& tmp_aim_str)
{
    char c_arry[2]={0,0};
    char* p_c=const_cast<char*>(pcre_url.c_str());
    while(*p_c)
    {
        if(*p_c == '.')
        {
            tmp_aim_str+="\\.";
        }else if(*p_c == '?')
        {
            tmp_aim_str+="\\?";
        }else if(*p_c == '&')
        {
            tmp_aim_str+="&amp;";
        }else
        {
            c_arry[0]=*p_c;
            tmp_aim_str+=c_arry;
        }
        ++p_c;
    }
}

//待有時間封裝完善
//思路：
//將一次解析配置文件分成識別部分、標籤部分、請求解析（urlparam解析部分、請求頭部分、cookie解析部分、體內容解析部分）、響應體解析（響應頭部分、響應體部分）、結束部分、發送標籤部分、標籤規則部分。
//將excel拆分成諸多解析配置
int write_config_xml(string& dst_file, string& src_file)
{
    stringstream sstream_cookie;
    string beizhu("");
    string host("");
    string mail_name("");
    string pcre_url("");
    string url_type("");
    string proto_type("");
    string jz_class("");
    string app_id("");
    string board_id("");
    string action_type("");
    string from_url("");
    string from_cookie("");
    string from_body("");
    string src_file_path = src_file;
    sstream_cookie
        <<"<config>\n<send_data_type>net</send_data_type>\n<time_out>60</time_out>\n<webmail_parse>\n";

    ifstream instream(src_file_path.c_str(), ios::in);
    int i = 1;
    while(1)
    {
        getline(instream, beizhu);
        if(!instream)
        {
            break;
        }
        getline(instream,host);
        getline(instream,mail_name);
        getline(instream,pcre_url);
        getline(instream,url_type);
        getline(instream,proto_type);
        getline(instream,jz_class);
        getline(instream,app_id);
        getline(instream,board_id);
        getline(instream,action_type);
        getline(instream,from_url);
        getline(instream,from_cookie);
        getline(instream,from_body);
        if(proto_type == "GET")
        {
            proto_type="PROTO_HTTP_GET";
        }else{
            proto_type="PROTO_HTTP_POST";
        }
        string pcre_url_str("");
        deal_pcre_url(pcre_url, pcre_url_str);
        sstream_cookie
            <<"<mail>\n<mail_name>"<<mail_name<<"</mail_name>"<<endl
            <<"<host>"<<host<<"</host>"<<endl
            <<"<urlhandle>"<<endl
            <<"<pcre_url>"<<pcre_url_str<<"</pcre_url>"<<"<!--"<<beizhu<<"-->"<<endl
            <<"<proto_type>"<<proto_type<<"</proto_type>"<<endl
            <<"<board_id>"<<board_id<<"</board_id>"<<endl
            <<"<jz_class>"<<jz_class<<"</jz_class>"<<endl
            <<"<app_id>"<<app_id<<"</app_id>"<<endl
            <<"<action_type>"<<action_type<<"</action_type>"<<endl
            <<"<url_type>"<<url_type<<"</url_type>"<<endl
            <<"<requset_parse>\n<burstification>web163_requse_att</burstification>\n<do>\n<doname>requst_head_pasre</doname>\n<key>Referer</key>\n<key>Accept</key>\n<key>Accept-Language</key>\n<key>User-Agent</key>\n<key>Accept-Encoding</key>\n<key>Host</key>\n<key>Cookie</key>\n<key>Accept-Charset</key>\n<key>Via</key> \n<key>Content-Length</key>\n<key>Content-Type</key>\n<key>X-Forwarded-For</key>\n</do>\n";
        if(from_url == "1")
        {
            sstream_cookie
                <<"<do>\n<doname>urlparam</doname>\n<key></key>\n</do>\n";
        }
        if(from_cookie =="1")
        {
            sstream_cookie
                <<"<do>\n<doname>cookie</doname>\n<key>home_username</key>\n</do>\n";
        }
        if(from_body == "1")
        {
            sstream_cookie
                <<"<do>\n<doname>get_info_from_request_body</doname>\n<key></key>\n</do>\n"
                <<"<do>\n<doname>urldecode_config</doname>\n<key></key>\n</do>\n"
                <<"<do>\n<doname>gbk_to_utf</doname>\n<key></key>\n</do>\n";
        }
        if(from_body == "2")
        {
            sstream_cookie
                <<"<do>\n<doname>get_info_from_request_body_form2</doname>\n<key></key>\n</do>\n"
                <<"<do>\n<doname>urldecode_config</doname>\n<key></key>\n</do>\n"
                <<"<do>\n<doname>gbk_to_utf</doname>\n<key></key>\n</do>\n";
        }
        if(from_body == "3")
        {
            sstream_cookie
                <<"<do>\n<doname>get_info_from_request_body_form3</doname>\n<key></key>\n</do>\n"
                <<"<do>\n<doname>urldecode_config</doname>\n<key></key>\n</do>\n"
                <<"<do>\n<doname>gbk_to_utf</doname>\n<key></key>\n</do>\n";
        }
        sstream_cookie
            <<"<do>\n<doname>finish_right_now</doname>\n<key>1</key>\n</do>\n</requset_parse>\n<response_parse>\n<burstification>no_burs</burstification>\n</response_parse>\n";
        if(url_type =="NEWS")
        {
            sstream_cookie<<"<tissue>\n<No0key_list>\n<key>action_statistics</key>\n</No0key_list>\n"
                <<"</tissue>\n</urlhandle>"<<endl<<"</mail>\n";
        }
        else if(url_type =="BBS")
        {
            sstream_cookie<<"<tissue>\n<No0key_list>\n<key>action_statistics</key>\n</No0key_list>\n"
                <<"<No10key_list>\n"<<"<key>requset_cookie_home_username</key>\n"<<"</No10key_list>\n"
                <<"</tissue>\n</urlhandle>"<<endl<<"</mail>\n";
        }
        else if(url_type =="REGIST")
        {
            sstream_cookie<<"<tissue>\n<No0key_list>\n<key>action_statistics</key>\n</No0key_list>\n"
                <<"<from>\n"<<"<key>requset_cookie_home_username</key>\n"<<"</from>\n"
                <<"</tissue>\n</urlhandle>"<<endl<<"</mail>\n";
        }else if(url_type == "SEARCH")
        {
            sstream_cookie<<"<tissue>\n<No0key_list>\n<key>action_statistics</key>\n</No0key_list>\n"
                <<"<access_name>\n"<<"<key>requset_urlparam_</key>\n"<<"</access_name>\n"
                <<"</tissue>\n</urlhandle>"<<endl<<"</mail>\n";
        }
        beizhu="";
        host="";
        mail_name="";
        pcre_url="";
        url_type="";
        proto_type="";
        jz_class="";
        app_id="";
        board_id="";
        action_type="";
        from_url="";
        from_cookie="";
        from_body="";
        pcre_url_str.clear();
        ++i;
    }
    string dst_file_path = dst_file;
    ofstream outstream(dst_file_path.c_str());
    sstream_cookie<<"</webmail_parse>\n</config>\n";
    outstream<<sstream_cookie.str();
    //cout<<sstream_cookie.str();
    instream.close();
    outstream.flush();
    outstream.close();
    sstream_cookie.str("");
}

string base64_encode(const unsigned char* Data, int DataByte)
{
    //编码表
    const char EncodeTable[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    //返回值
    string strEncode;
    unsigned char Tmp[4]={0};
    int LineLength=0;
    for(int i=0; i<(int)(DataByte / 3); i++)
    {
        Tmp[1] = *Data++;
        Tmp[2] = *Data++;
        Tmp[3] = *Data++;
        strEncode += EncodeTable[Tmp[1] >> 2];
        strEncode += EncodeTable[((Tmp[1] << 4) | (Tmp[2] >> 4)) & 0x3F];
        strEncode += EncodeTable[((Tmp[2] << 2) | (Tmp[3] >> 6)) & 0x3F];
        strEncode += EncodeTable[Tmp[3] & 0x3F];
        if(LineLength +=4,LineLength==76)
        {
            //strEncode+="\r\n";
            LineLength=0;
        }
    }
    //对剩余数据进行编码
    int Mod=DataByte % 3;
    if(Mod==1)
    {
        Tmp[1] = *Data++;
        strEncode+= EncodeTable[(Tmp[1] & 0xFC) >> 2];
        strEncode+= EncodeTable[((Tmp[1] & 0x03) << 4)];
        strEncode+= "==";
    }
    else if(Mod==2)
    {
        Tmp[1] = *Data++;
        Tmp[2] = *Data++;
        strEncode+= EncodeTable[(Tmp[1] & 0xFC) >> 2];
        strEncode+= EncodeTable[((Tmp[1] & 0x03) << 4) | ((Tmp[2] & 0xF0) >> 4)];
        strEncode+= EncodeTable[((Tmp[2] & 0x0F) << 2)];
        strEncode+= "=";
    }
    return strEncode;
}

string base64_decode(const char* Data, int DataByte, int& OutByte)
{
    //解码表
    const char DecodeTable[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        62,
        0, 0, 0,
        63,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, // '0'-'9'
        0, 0, 0, 0, 0, 0, 0,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // 'A'-'Z'
        0, 0, 0, 0, 0, 0,
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, // 'a'-'z'
    };

    //返回值
    string strDecode;
    int nValue;
    int i= 0;
    while (i < DataByte)
    {
        if (*Data != '\r' && *Data!='\n')
        {
            nValue = DecodeTable[*Data++] << 18;
            nValue += DecodeTable[*Data++] << 12;
            strDecode+=(nValue & 0x00FF0000) >> 16;
            OutByte++;
            if (*Data != '=')
            {
                nValue += DecodeTable[*Data++] << 6;
                strDecode+=(nValue & 0x0000FF00) >> 8;
                OutByte++;
                if (*Data != '=')
                {
                    nValue += DecodeTable[*Data++];
                    strDecode+=nValue & 0x000000FF;
                    OutByte++;
                }
            }
            i += 4;
        }
        else// 回车换行,跳过
        {
            Data++;
            i++;
        }
    }

    return strDecode;
}

static int php_htoi(char *s)
{
    int value;
    int c;

    c = ((unsigned char *)s)[0];
    if (isupper(c))
        c = tolower(c);
    value = (c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10) * 16;

    c = ((unsigned char *)s)[1];
    if (isupper(c))
        c = tolower(c);
    value += c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10;

    return (value);
}

string urldecode(string &str_source)
{
    char const *in_str = str_source.c_str();
    int in_str_len = strlen(in_str);
    int out_str_len = 0;
    string out_str;
    char *str;

    str = strdup(in_str);
    char *dest = str;
    char *data = str;
    while (in_str_len--)
    {
        if (*data == '+')
        {
            *dest = ' ';
        }
        else if (*data == '%' && in_str_len >= 2 && isxdigit((int) *(data + 1))
                && isxdigit((int) *(data + 2)))
        {
            *dest = (char) php_htoi(data+1);
            data += 2;
            in_str_len -= 2;
        }
        else
        {
            *dest = *data;
        }
        data++;
        dest++;
    }
    *dest = '\0';
    out_str_len =  dest - str;
    out_str = str;
    free(str);
    return out_str;
}

static int MAX_SIZE_ARRAY = 10240;

//  進一步解封裝、增加靈活性的同時，增加代碼復用的可能。
void  host_ip(string& src_file_path, int argc)
{
    if( argc < 2 || src_file_path == "-h" || src_file_path == "--help" || src_file_path == "help")
    {
        cout<<" 使用方法为:"<<endl<<"\t ./test  host汇总文件  "<<endl;
        cout<<"    \t 运行该命令会在当前目录下生成文件：HostIp对应关系.txt 、 IpList.txt 。\n"<<endl;
        return;
    }
    string dst_file_path("./HostIp对应文件.txt");
    stringstream sstream_tmp;
    ifstream in_host (src_file_path.c_str(), ios::in);
    string str_tmp("");
    string str_host("");
    string str_shell_cmd("");
    string str_ip("");
    while(1)
    {
        getline(in_host, str_tmp);
        if(!in_host)
        {
            in_host.close();
            break;
        }
        if(!get_string_from_http_buffer(str_host, str_tmp.c_str(), "host is [", "]", 9, 0))
        {
            str_host = str_tmp;
        }
        str_tmp.clear();
        str_shell_cmd = "host   " + str_host ;
        cout<<"host is "<< str_shell_cmd<<endl;
        //使用管道处理shell命令产生的数据
        FILE* pp = popen( str_shell_cmd.c_str(), "r");
        if(!pp)
        {
            cout<<"PopenFailed!"<<endl;
            return;
        }

        char c_tmp[MAX_SIZE_ARRAY];
        memset(c_tmp, 0, MAX_SIZE_ARRAY);

        while(fgets(c_tmp, MAX_SIZE_ARRAY, pp) != NULL) //读取并处理一行
        {
            get_string_from_http_buffer( str_ip, c_tmp,  "has address ", "\n", 12, 0);
            memset(c_tmp, 0, MAX_SIZE_ARRAY);
            if(str_ip.size() != 0)
            {
                sstream_tmp<<str_host<< "  "<<str_ip<<endl;
                cout<<"host : "<<str_host<<" <--> "<<"ip : "<<str_ip<<endl;
                cout.flush();
                str_ip.clear();
            }
        }

        pclose(pp);
        /*system(str_shell_cmd.c_str());
          sleep(1);
          ifstream in_cookie_txt( "./.cookie_txt", ios::in);
          while(1)
          {
          getline(in_cookie_txt, str_tmp);
          if(!in_cookie_txt)
          {
          in_cookie_txt.close();
          break;
          }
          get_string_from_http_buffer( str_ip, str_tmp.c_str(), "has address ", "\n", 12, 0);
          str_tmp.clear();
          if(str_ip.size() != 0)
          {
          sstream_tmp<<str_host<< "  "<<str_ip<<endl;
          cout<<"host : "<<str_host<<" <--> "<<"ip : "<<str_ip<<endl;
          cout.flush();
          str_ip.clear();
          }
          }*/
    }
    ofstream out_final(dst_file_path.c_str());
    out_final<<sstream_tmp.str();
    out_final.flush();
    out_final.close();
    sstream_tmp.str("");
    system("rm -rf ./.cookie_txt; cat ./HostIp对应文件.txt | awk '{print $2}' | sort - u > IpList.txt ");
}


