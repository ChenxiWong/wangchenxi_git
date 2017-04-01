// Last Update:2016-08-01 13:17:13
/**
 * @file commit_tool.cpp
 * @brief 
 * @author zhangqi
 * @version 0.1.00
 * @date 2015-04-27
 */
#include "commit_tools.h"
#include <iomanip>
#include <sstream>
#include <sys/stat.h>
#include <sys/time.h>
using namespace std;
int enc_get_utf8_size__(unsigned char pInput)
{
    unsigned char c = pInput;
    // 0xxxxxxx 返回0
    // 10xxxxxx 不存在
    // 110xxxxx 返回2
    // 1110xxxx 返回3
    // 11110xxx 返回4
    // 111110xx 返回5
    // 1111110x 返回6
    if(c< 0x80) return 0;
    if(c>=0x80 && c<0xC0) return -1;
    if(c>=0xC0 && c<0xE0) return 2;
    if(c>=0xE0 && c<0xF0) return 3;
    if(c>=0xF0 && c<0xF8) return 4;
    if(c>=0xF8 && c<0xFC) return 5;
    if(c>=0xFC) return 6;
}
bool cmp_wiat_end(char * str,const  char * str1)
{
    int len = strlen(str) - strlen(str1);
    if(len < 0) 
    {
        return false;
    }
    else {
        if(strcmp(str+len,str1)==0)
            return true;
        else 
            return false;
    }
}
bool cmpn_wiat_end(char * str,int len ,const  char * str1)
{

    if(strncmp(str+len,str1,strlen(str1))==0)
    {
        return true;
    }
    return false;
}

char * splits_string(char * srcstr ,char splits_sign )
{
    char * p = srcstr;
    for(;*p!= 0x0 && *p != splits_sign; p++)
    {

    }
    if(*p != 0x0)
    {
        *p =0x0;
        return p+1;
    }
    else {
        return NULL;
    }
}

string date_day()
{
    time_t t2;
    time(&t2);  /*得到time_t类型的UTC时间*/ 
    struct tm result;
    struct tm* tm = localtime_r(&t2, &result);
    std::stringstream ss;
    ss << setfill('0')
        << setw(4) << tm->tm_year+1900 << '-'
        << setw(2) << tm->tm_mon+1 << 'u'
        << setw(2) << tm->tm_mday ;
    return ss.str();
}
string date_time()
{
    time_t t2;
    time(&t2);  /*得到time_t类型的UTC时间*/ 
    struct tm result;
    struct tm* tm = localtime_r(&t2, &result);
    std::stringstream ss;
    ss << setfill('0')
        << setw(4) << tm->tm_year+1900 << '-'
        << setw(2) << tm->tm_mon+1 << '-'
        << setw(2) << tm->tm_mday << '-'
        << setw(2) << tm->tm_hour << '-' 
        << setw(2) << tm->tm_min << '-'
        << setw(2) << tm->tm_sec;
    return ss.str();
}

string hour_time()
{
    time_t t2;
    time(&t2);  /*得到time_t类型的UTC时间*/ 
    struct tm result;
    struct tm* tm = localtime_r(&t2, &result);
    std::stringstream ss;
    ss << setfill('0')
        << setw(2) << tm->tm_hour << ':' 
        << setw(2) << tm->tm_min << ':'
        << setw(2) << tm->tm_sec;
    return ss.str();
}

string date_time2(time_t t)
{
    struct tm result;
    struct tm* tm = localtime_r(&t, &result);
    std::stringstream ss;
    ss << setfill('0')
        << setw(4) << tm->tm_year+1900 << '-'
        << setw(2) << tm->tm_mon+1 << '-'
        << setw(2) << tm->tm_mday << ' '
        << setw(2) << tm->tm_hour << ':' 
        << setw(2) << tm->tm_min << ':'
        << setw(2) << tm->tm_sec;
    return ss.str();
}

string date_time3(time_t t)
{
    struct tm result;
    time_t t2 = t/1000000;
    time_t t3 = t%1000000;
    struct tm* tm = localtime_r(&t2, &result);
    std::stringstream ss;
    ss << setfill('0')
        << setw(4) << tm->tm_year+1900 << '-'
        << setw(2) << tm->tm_mon+1 << '-'
        << setw(2) << tm->tm_mday << ' '
        << setw(2) << tm->tm_hour << ':' 
        << setw(2) << tm->tm_min << ':'
        << setw(2) << tm->tm_sec << ':'
        << setw(5) << t3;
    return ss.str();
}

void create_path(string path)
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
uint64_t get_local_time64()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    uint64_t m_timeval = tv.tv_sec * 1000000 + tv.tv_usec;
    return m_timeval ;

}
string get_year_month()
{
    time_t t2;
    time(&t2);  /*得到time_t类型的UTC时间*/ 
    struct tm result;
    struct tm* tm = localtime_r(&t2, &result);
    std::stringstream ss;
    ss << setfill('0')
        << setw(4) << tm->tm_year+1900
        << setw(2) << tm->tm_mon+1 << '/';
    return ss.str();
}

string get_day_hour()
{
    time_t t2;
    time(&t2);  /*得到time_t类型的UTC时间*/ 
    struct tm result;
    struct tm* tm = localtime_r(&t2, &result);
    std::stringstream ss;
    ss << setfill('0')
        << setw(2) << tm->tm_mday
        << setw(2) << tm->tm_hour << '/';
    return ss.str();
}

string get_min_sec()
{
    time_t t2;
    time(&t2);  /*得到time_t类型的UTC时间*/ 
    struct tm result;
    struct tm* tm = localtime_r(&t2, &result);
    std::stringstream ss;
    ss << setfill('0')
        << setw(2) << tm->tm_min
        << setw(2) << tm->tm_sec << '/';
    return ss.str();
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
        strEncode+= EncodeTable[Tmp[1] >> 2];
        strEncode+= EncodeTable[((Tmp[1] << 4) | (Tmp[2] >> 4)) & 0x3F];
        strEncode+= EncodeTable[((Tmp[2] << 2) | (Tmp[3] >> 6)) & 0x3F];
        strEncode+= EncodeTable[Tmp[3] & 0x3F];
        if(LineLength+=4,LineLength==76) 
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


const unsigned int CRC32_TABLE[] = { 0x00000000L, 0x77073096L, 0xee0e612cL,
    0x990951baL, 0x076dc419L, 0x706af48fL, 0xe963a535L, 0x9e6495a3L,
    0x0edb8832L, 0x79dcb8a4L, 0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL,
    0x7eb17cbdL, 0xe7b82d07L, 0x90bf1d91L, 0x1db71064L, 0x6ab020f2L,
    0xf3b97148L, 0x84be41deL, 0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L,
    0x83d385c7L, 0x136c9856L, 0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL,
    0x14015c4fL, 0x63066cd9L, 0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L,
    0x4c69105eL, 0xd56041e4L, 0xa2677172L, 0x3c03e4d1L, 0x4b04d447L,
    0xd20d85fdL, 0xa50ab56bL, 0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L,
    0xacbcf940L, 0x32d86ce3L, 0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L,
    0x26d930acL, 0x51de003aL, 0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L,
    0x56b3c423L, 0xcfba9599L, 0xb8bda50fL, 0x2802b89eL, 0x5f058808L,
    0xc60cd9b2L, 0xb10be924L, 0x2f6f7c87L, 0x58684c11L, 0xc1611dabL,
    0xb6662d3dL, 0x76dc4190L, 0x01db7106L, 0x98d220bcL, 0xefd5102aL,
    0x71b18589L, 0x06b6b51fL, 0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L,
    0x0f00f934L, 0x9609a88eL, 0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL,
    0x91646c97L, 0xe6635c01L, 0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L,
    0xf262004eL, 0x6c0695edL, 0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L,
    0x65b0d9c6L, 0x12b7e950L, 0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL,
    0x15da2d49L, 0x8cd37cf3L, 0xfbd44c65L, 0x4db26158L, 0x3ab551ceL,
    0xa3bc0074L, 0xd4bb30e2L, 0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL,
    0xd3d6f4fbL, 0x4369e96aL, 0x346ed9fcL, 0xad678846L, 0xda60b8d0L,
    0x44042d73L, 0x33031de5L, 0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL,
    0x270241aaL, 0xbe0b1010L, 0xc90c2086L, 0x5768b525L, 0x206f85b3L,
    0xb966d409L, 0xce61e49fL, 0x5edef90eL, 0x29d9c998L, 0xb0d09822L,
    0xc7d7a8b4L, 0x59b33d17L, 0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL,
    0xedb88320L, 0x9abfb3b6L, 0x03b6e20cL, 0x74b1d29aL, 0xead54739L,
    0x9dd277afL, 0x04db2615L, 0x73dc1683L, 0xe3630b12L, 0x94643b84L,
    0x0d6d6a3eL, 0x7a6a5aa8L, 0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L,
    0x7d079eb1L, 0xf00f9344L, 0x8708a3d2L, 0x1e01f268L, 0x6906c2feL,
    0xf762575dL, 0x806567cbL, 0x196c3671L, 0x6e6b06e7L, 0xfed41b76L,
    0x89d32be0L, 0x10da7a5aL, 0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L,
    0x17b7be43L, 0x60b08ed5L, 0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L,
    0x4fdff252L, 0xd1bb67f1L, 0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL,
    0xd80d2bdaL, 0xaf0a1b4cL, 0x36034af6L, 0x41047a60L, 0xdf60efc3L,
    0xa867df55L, 0x316e8eefL, 0x4669be79L, 0xcb61b38cL, 0xbc66831aL,
    0x256fd2a0L, 0x5268e236L, 0xcc0c7795L, 0xbb0b4703L, 0x220216b9L,
    0x5505262fL, 0xc5ba3bbeL, 0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L,
    0xc2d7ffa7L, 0xb5d0cf31L, 0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L,
    0xec63f226L, 0x756aa39cL, 0x026d930aL, 0x9c0906a9L, 0xeb0e363fL,
    0x72076785L, 0x05005713L, 0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL,
    0x0cb61b38L, 0x92d28e9bL, 0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L,
    0x86d3d2d4L, 0xf1d4e242L, 0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL,
    0xf6b9265bL, 0x6fb077e1L, 0x18b74777L, 0x88085ae6L, 0xff0f6a70L,
    0x66063bcaL, 0x11010b5cL, 0x8f659effL, 0xf862ae69L, 0x616bffd3L,
    0x166ccf45L, 0xa00ae278L, 0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L,
    0xa7672661L, 0xd06016f7L, 0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL,
    0xd9d65adcL, 0x40df0b66L, 0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L,
    0x47b2cf7fL, 0x30b5ffe9L, 0xbdbdf21cL, 0xcabac28aL, 0x53b39330L,
    0x24b4a3a6L, 0xbad03605L, 0xcdd70693L, 0x54de5729L, 0x23d967bfL,
    0xb3667a2eL, 0xc4614ab8L, 0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L,
    0xc30c8ea1L, 0x5a05df1bL, 0x2d02ef8dL };
//crc32实现函数
uint32_t crc32( unsigned char *buf, int len)
{
    uint32_t ret = 0xFFFFFFFF;
    int   i;
    for(i = 0; i < len;i++)
    {
        ret = CRC32_TABLE[((ret & 0xFF) ^ buf[i])] ^ (ret >> 8);
    }
    ret = ~ret;
    return ret;
}
// string 按分割符号分割程list
void  splitEx(const string src, string separate_character , vector<string> &strs)
{

    int separate_characterLen = separate_character.size();//分割字符串的长度,这样就可以支持如“,,”多字符串的分隔符
    int lastPosition = 0,index = -1;
    while (-1 != (index = src.find(separate_character,lastPosition)))
    {
        strs.push_back(src.substr(lastPosition,index - lastPosition));
        lastPosition = index + separate_characterLen;
    }
    string lastString = src.substr(lastPosition);//截取最后一个分隔符后的内容
    if (!lastString.empty())
        strs.push_back(lastString);//如果最后一个分隔符后还有内容就入队
    return ;

}
bool char_path_parse(char * &src_path , char * node) 
{
    node[0] =0x0;
    if(src_path == NULL) return false;
    if(*src_path == '/') src_path ++;
    if(*src_path == 0x0) return false;

    char * p = strchr(src_path,'/');
    if(p == NULL)
    {
        strcpy(node,src_path);
        src_path = NULL;
        return true;
    }
    else {
        int len = p - src_path;
        strncpy(node,src_path,len);
        node[len] = 0x0;
        src_path = p+1;
        return true;
    }
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

uint16_t parse_buf2uint16N(char * buf, int offise)
{
    return (uint16_t)ntohl(*(int *)(buf + offise));
}
uint16_t parse_buf2uint16H(char * buf, int offise)
{
    return (*(uint16_t *)(buf + offise));
}
uint32_t parse_buf2uint32N(char * buf, int offise)
{
    return (uint32_t)ntohl(*(int *)(buf + offise));
}
uint32_t parse_buf2uint32H(char * buf, int offise)
{
    return (*(uint32_t *)(buf + offise));
}


char * c_to_shell(const char * cmd ,char * out ,int  len) 
{
    memset( out, 0x0, len );//初始化buf,以免后面写如乱码到文件中
    FILE * stream = popen( cmd, "r" ); //将“ls －l”命令的输出 通过管道读取（“r”参数）到FILE* stream    
    if(stream == NULL)
        return NULL;

    fread(out,1, len, stream); 

    pclose( stream ); 
    return out;
}

void replace_str(string &original_str, string old_str, string new_str)
{
    string::size_type pos=0;
    string::size_type a=old_str.size();
    string::size_type b=new_str.size();
    while((pos=original_str.find(old_str,pos))!=string::npos)
    {   
        original_str.replace(pos,a,new_str);
        pos+=b;
    }   
}


double s2f(const string& src)
{
    stringstream longlat(src);
    double l;
    longlat >> l;
    return l;
}


string del_unsign_char(string s_username) 
{
    char str[s_username.size() + 1];
    strcpy(str, s_username.c_str());
    string s_out = "";
    for(int j = 0; j < s_username.size() ;j++)
    {
        if (iscntrl(str[j]) == 0)
        {
            s_out += str[j];
        }
    }
    return s_out;
}

int HandleEscapeChar(unsigned char *pbuf, unsigned char *res)
{
    char token[9];
        int i;
        char *buf=(char *)pbuf;
        /* copying token into local buffer */
        i = 0;
        while (i <= 8 && buf[i]!=';')
        {
            token[i]=buf[i];
                i++;
        }
    if( buf[i]==';')
    {
        token[i]=';';
            i++;
            token[i]=0;
    }
    else
    {
        /* if it does not seem to be a token, result is '&' */
            *res = 0x26;
            return 1;
    }
    /* identifying token */

    if (!strcmp(token,"&nbsp;"))
        {
            *res=0x20;
             return 6;
        }
   else if (!strncmp (token, "&amp;", 5))
    {
       // strcpy((char *)res,"&amp;"); 
        *res=0x26;
        return 5;
    }
    else if (!strncmp (token, "&lt;", 4))
    {
       // strcpy((char *)res,"&lt;");
        *res = 0x3C;
        return 4;
    }
    else if (!strncmp (token, "&gt;", 4))
    {
       // strcpy((char *)res,"&gt;");
        *res = 0x3E;
        return 4;
    }
    else if (!strncmp (token, "&quot;", 6))
    {
       // strcpy((char *)res,"&quot;"); 
        *res = 0x22;
        return 6;
    }
    else if (!strncmp(token,"&apos;",6))
    {
        strcpy((char *)res,"&apos;");
        // *res=  ;
        return 6;
    }
    else if (!strncmp (token, "&eacute;", 8))
    {
        *res = 0x20;//0xE9;
        return 8;
    }
    else if (!strncmp (token, "&Eacute;", 8))
    {
        *res = 0x20;//0xC9;
        return 8;
    }
    else if (!strncmp (token, "&egrave;", 8))
    {
        *res = 0x20;//0xE8;
        return 8;
    }
    else if (!strncmp (token, "&Egrave;", 8))
    {
        *res = 0x20;//0xC8;
        return 8;
    }
    else if (!strncmp (token, "&ecirc;", 7))
    {
        *res = 0x20;//0xEA;
        return 7;
    }
    else if (!strncmp (token, "&agrave;", 8))
    {
        *res = 0x20;//0xE0;
        return 8;
    }
    else if (!strncmp (token, "&iuml;", 6))
    {
        *res = 0x20;//0xEF;
        return 6;
    }
    else if (!strncmp (token, "&ccedil;", 8))
    {
        *res = 0x20;//0xE7;
        return 8;
    }
    else if (!strncmp (token, "&ntilde;", 8))
    {
        *res = 0x20;//0xF1;
        return 8;
    }
    else if (!strncmp (token, "&copy;", 6))
    {
        *res = 0x20;//0xA9;
        return 6;
    }
    else if (!strncmp (token, "&reg;", 5))
    {
        *res = 0x20;//0xAE;
        return 5;
    }
    else if (!strncmp (token, "&deg;", 5))
    {
        *res = 0x20;//0xB0;
        return 5;
    }
    else if (!strncmp (token, "&ordm;", 6))
    {
        *res = 0x20;//0xBA;
        return 6;
    }
    else if (!strncmp (token, "&laquo;", 7))
    {
        *res = 0x20;//0xAB;
        return 7;
    }
    else if (!strncmp (token, "&raquo;", 7))
    {
        *res = 0x20;//0xBB;
        return 7;
    }
    else if (!strncmp (token, "&micro;", 7))
    {
        *res = 0x20;//0xB5;
        return 7;
    }
    else if (!strncmp (token, "&para;", 6))
    {
        *res = 0x20;//0xB6;
        return 6;
    }
    else if (!strncmp (token, "&frac14;", 8))
    {
        *res = 0x20;//0xBC;
        return 8;
    }
    else if (!strncmp (token, "&frac12;", 8))
    {
        *res = 0x20;//0xBD;
        return 8;
    }
    else if (!strncmp (token, "&frac34;", 8))
    {
        *res = 0x20;//0xBE;
        return 8;
    }
    else if (!strncmp (token, "&#", 2))
    {
        res[0] = atoi (token + 2);
            return i + 1;
    }
    else
    {
        *res = 0x20;
            return i + 1;
    }
}

int html_to_txt(char *poutbuf, int &olen, const char *pinbuf, int inlen)
{
    unsigned char esc[32];
    register int len, i, isMarkup, isJavascript, isMeta, l, j;
    register int offset ;
    l = 0;
    isJavascript = 0;
    isMarkup = 0;
    isMeta = 0;
    i=0;
    len=inlen;
    olen=0;
    bool bHeadFirst=false;
    while (i<len && (pinbuf[i]==0x20||pinbuf[i]=='\t'||pinbuf[i]==0xd||pinbuf[i]==0xa||pinbuf[i]==0x00))
        i++;
    if (i>=len) return 0;
    while (len>(i+1) && (pinbuf[len-1]==0x20||pinbuf[len-1]=='\t'||pinbuf[len-1]==0xd||pinbuf[len-1]==0xa||pinbuf[i]==0x00))
        len--;
 //   if ((len-i)<32) return 0;
    while (i<len)
    {
        // utf -8 
        int charset_len  =   enc_get_utf8_size__(pinbuf[i]) ;
        if(len == 0)
        {
            int m = 0;
            for(m = 0; m < charset_len ; m ++) 
            {
                poutbuf[l+m] = poutbuf[i+m];
            }
            i += charset_len ;
            l += charset_len;
            continue; 
        }
        if (pinbuf[i]=='<')
        {

            if (i<len-8 && !strncasecmp(pinbuf+i,"<script", 7)) //filter javascript
            {
                i+=8;
                const char *psend=StrnLowStr(pinbuf+i,len-i,"</script", 8);
                if (psend)
                {
                    j=psend-pinbuf-i;
                    j+=8;
                    i+=j;
                    for (;i<len&&pinbuf[i]!='>';i++) ;   //<find end '>
                    if (i<len&& pinbuf[i]=='>') i++;
                }
                continue;
            }



            else if (i<len-8 && !strncasecmp(pinbuf+i,"<head", 5))  //filter header
            {
                i+=6;
                const char *psend=StrnLowStr(pinbuf+i,len-i,"</head",5);
                if (psend)
                {
                    j=psend-pinbuf-i;
                    j+=6;
                    if (!bHeadFirst)
                    {
                        bHeadFirst=true;
                    }
                    i+=j;
                    for (;i<len&&pinbuf[i]!='>';i++) ;   //<find end '>
                    if (i<len&& pinbuf[i]=='>') i++;

                }
                else
                {
                    for (;i<len&&pinbuf[i]!='>';i++) ;   //<find end '>
                    if (i<len&& pinbuf[i]=='>') i++;
                }
                continue;
            }



            else if (i<len-8 && !strncasecmp(pinbuf+i,"<style",6))
            {
                i+=7;
                const char *psend=StrnLowStr(pinbuf+i,len-i,"</style",7);
                if (psend)
                {
                    j=psend-pinbuf-i;
                    j+=7;
                    i+=j;
                    for (;i<len&&pinbuf[i]!='>';i++) ;   //<find end '>
                    if (i<len&& pinbuf[i]=='>') i++;

                }
                else
                {
                    for (;i<len&&pinbuf[i]!='>';i++) ;   //<find end '>
                    if (i<len&& pinbuf[i]=='>') i++;
                }
                continue;
            }




            else if (i<len-8 && !strncasecmp(pinbuf+i,"<meta",5))
            {
                i+=6;
                const char *pMetaBegin = pinbuf+i;
                const char *psend=StrnLowStr(pinbuf+i,len-i,"</meta",6);
                if (psend)
                {
                    j=psend-pinbuf-i;
                    j+=6;
                    i+=j;
                    for (;i<len&&pinbuf[i]!='>';i++) ;   //<find end '>
                    if (i<len&& pinbuf[i]=='>') i++;					
                }
                else
                {
                    for (;i<len&&pinbuf[i]!='>';i++) ;   //<find end '>
                    if (i<len&& pinbuf[i]=='>') i++;					
                }
                 continue;
             }


           
            
                else if (!strncasecmp(pinbuf+i,"<p ",3)||!strncasecmp(pinbuf+i,"<pre",4)||!strncasecmp(pinbuf+i,"<br",3)||
                            !strncasecmp(pinbuf+i,"<li",3)||!strncasecmp(pinbuf+i,"<ul",3)||
                            !strncasecmp(pinbuf+i,"<ul",3)||!strncasecmp(pinbuf+i,"<ol",3)||!strncasecmp(pinbuf+i,"<tr",3))
                  {
                        for (;i<len &&pinbuf[i]!='>';i++) ;
                        if (i<len &&pinbuf[i]=='>')
                            i++;

                        if (l>0 && poutbuf[l-1]==0x0a)
                            continue;
                        else
                                {
                        poutbuf[l]=0x0a;
                        l++;
                        continue;
                                }
                  }
             



            else if (!strncasecmp(pinbuf+i,"<td",3)||!strncasecmp(pinbuf+i,"<th",3))  //table column handle
                 {
                        for (;i<len &&pinbuf[i]!='>';i++) ;
                        if (i<len &&pinbuf[i]=='>')
                            i++;
                        poutbuf[l]=0x20;
                        l++;
                        poutbuf[l]=0x20;
                        l++;
                        continue;
                 }
           

          else if (!strncmp(pinbuf+i,"</",2))
                {
                    for (;i<len &&pinbuf[i]!='>';i++) ;
                    if (i<len&&pinbuf[i]=='>')
                        i++;
                    continue;
                }



           else if (i<len-5 && !strncasecmp(pinbuf+i,"<div",4))
                {
                    for (;i<len &&pinbuf[i]!='>';i++) ;
                    if (i<len &&pinbuf[i]=='>')
                        i++;
                    poutbuf[l]=0x20;
                    l++;
                    poutbuf[l]=0x20;
                    l++;
                    continue;

                }



           else
               {
            for (;i<len && pinbuf[i]!='>';i++) ;  //find '<' skip <aaa>command
            if (i<len&& pinbuf[i]=='>') i++;
            continue;
                }
         
       }    




      else if (pinbuf[i]==0x26)  //&
        {
                isMarkup=0;
                if (i<len-1)
                {
                    for (j=i;j<len&&(j-i)<9;j++)
                    {
                        if (pinbuf[j]==';')
                        {
                            isMarkup=1;
                            break;
                        }
                    }
                }
                if (isMarkup)
                {
                    memset (esc, '\x00', 32);
                    offset = HandleEscapeChar((unsigned char *)(pinbuf + i), esc);
                    i+=offset;
                    j=strlen((char *)esc);
                    memcpy(poutbuf+l,esc,j);
                    l+=j;
                }
                else
                {
                    poutbuf[l]=pinbuf[i];
                    l++;
                    i++;
                }
                continue;
         }


      else if (pinbuf[i]=='\r'||pinbuf[i]=='\n')
         {
                i++;
                continue;
         }
            

      else if (pinbuf[i]=='>')  
            {
                i++;
                continue;
            }
            


     else if (pinbuf[i]==0x20||pinbuf[i]=='\t')
            {
                if(l>0 && poutbuf[l-1]!=0x20)
                {
                    poutbuf[l]=0x20;
                    l++;
                }
                i++;
                continue;
            }


     else if ((unsigned char)pinbuf[i]<0x20||(unsigned char)pinbuf[i]==0xff)
            {
                i++;
                continue;
            }

    else
     {
       poutbuf[l]=pinbuf[i];
       l++;
       i++;
      }
    }
   olen=l;
   return olen;
}

const char * StrnLowStr(const char *buf, int len, const char *pattern, int length)
{
    int i = 0;
    for(; i<len; ++i)
    {
        if((*(buf+i)==*pattern) && len-i>=length)
        {
            //if(strincmp(buf+i, pattern, length)==0)
            if(strncasecmp(buf+i, pattern, length)==0)
                return buf+i;
        }
    }
    return NULL;
}
string strassigntoc(string& str ,int n , char  c  ) 
{
    int i = 0; 
    string value ="";
    if(n > str.length())
    {
        return value;
    }
    while(str[n+i] != 0x0 && str[n+i] != c)
    {
        value += str[n+i];
        i++;
    }
    if(str[n+i] == 0x0) 
    {
        str = "";
    }
    else 
    {
         str.assign(str,n + i +1 , str.length()) ;
    }
    return value;
}

string strncpytoc(string& str ,int n , char  c  ) 
{
    int i = 0; 
    string value ="";
    if(n > str.length())
    {
        return value;
    }
    while(str[n+i] != 0x0 && str[n+i] != c)
    {
        value += str[n+i];
        i++;
    }
    return value;
}
// 查找字符串
bool get_string_from_http_buffer(string& aim_str,
        const char* p_buffer,
        const char* start_sign,
        const char* end_sign,
        int aim_str_start,
        int aim_str_end_to_end_sign,
        int* p_deal_len,
        int* p_no_useful_len)
{
    if(NULL == p_buffer)
    {
        return false;
    }
    char* p_start = NULL;
    char* p_end = NULL;
    if(1 == strlen(start_sign))
    {
        char tmp = *start_sign;
        p_start = const_cast<char*>(strchr(p_buffer, tmp));
    }
    else
    {
        p_start = const_cast<char*>(strstr(p_buffer, start_sign));
    }
    if(NULL == p_start)
    {
        return false;
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
    }
    else if(1 == strlen(end_sign))
    {
        char tmp = *end_sign;
        p_end = strchr(p_start + aim_str_start, tmp);
    }
    else
    {
        p_end = strstr(p_start + aim_str_start, end_sign);
    }
    if(NULL == p_end)
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
string& trim(string &s)
{
    if (s.empty())
    {  
        return s;  
    }  
    s.erase(0,s.find_first_not_of(" "));  
    s.erase(s.find_last_not_of(" ") + 1);  
    return s;  
}


string reserved_number(string& a)
{
    string::iterator t = a.begin();
    while(t != a.end())
    {
        if(*t == '.')
        {
            t++;
        }
        else if(*t >= '0' && *t <= '9')
        {
            t++;
        }
        else
        {
            a.erase(t);
        }
    }
    return a;
}
int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen)
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

//该函数用于处理字符串中含有%u的转码问题 svalue为含有%u的字符串，flag是你要处理的标志可以是%u也可以为\\u
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
            char* hex_char = "0123456789abcdefABCDEF";
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

//IPV4、IPV6判断
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

//通过检查字符串中是否存在未被编码集合映射字符，来判定是否为gbk编码
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

//将gbk编码转换成utf-8编码
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
        //小端处理情况。
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


// 判断字符是否符合utf-8编码规范
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
            //printf("0X%x\n");
            if(!utf_visible(union_four.num, low_arry, high_arry))return false;
            //需要添加大小端处理情况。
           break;
        }
    }
    return true;
}


//祛除字符串中因字符集问题导致的乱码。
//该函数仅仅支持字符串编码格式为带u、U的Unicode编码、GBK编码转换为UTF-8编码
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
    return;
}

