// Last Update:2016-09-13 15:07:36
/**
 * @file main.cpp
 * @brief 进程搬运函数
 * @author wangchenxi
 * @version 0.1.00
 * @date 2016-09-13
 */
extern "C"{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <string.h>
}
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    printf("Usage: sudo ./LiveNpr [网卡号]  [pcap处理目录] \n");
    if( 0 != access("/tmp/LiveNpr/", F_OK))
    {
        system("mkdir /tmp/LiveNpr/ -p");
    }
    system("rm -rf /tmp/LiveNpr/*");
    pid_t pid_ping = fork();
    if(0 == pid_ping)
    {
        system("sudo ping 127.0.0.1 -l 245000 >/dev/null ");
    }
    pid_t pid_tcpdump = fork();
    if(0 == pid_tcpdump)
    {
        char c_buff[150];
        memset(c_buff, 0, 150);
        sprintf(c_buff, "./tcpdump -i %s -C 1 -w /tmp/LiveNpr/.livnprpcap > /dev/null ", argv[1]);
        system(c_buff);
    }
    pid_t pid_move = fork();
    if(0 == pid_move)
    {
        while(1)
        {
            //1.打开目录
            DIR* dir = opendir("/tmp/LiveNpr");
            //2.不断地读取目录中的内容
            struct dirent* ent = NULL;
            while(ent = readdir(dir))
            {
                //如果读取到的是文件，则直接打印
                if(8 == ent->d_type)
                {
                    char c_file_path[150];
                    memset( c_file_path, 0, 150);
                    sprintf( c_file_path, "/tmp/LiveNpr/%s ", ent->d_name);
                    struct stat st = {};
                    int res = stat(c_file_path, &st);
                    if(-1 == res)
                    {
                        perror("stat"),exit(-1);
                    }
                    if(st.st_size >= 1000000)
                    {
                        char c_mv_cmd[150];
                        memset( c_mv_cmd, 0, 150);
                        sprintf( c_mv_cmd, " mv  %s  %s/$(date +%%F-%%H-%%S-%%N).pcap ", c_file_path, argv[2]);
                        sleep(1);
                        system(c_mv_cmd);
                        memset( c_mv_cmd, 0, 150);
                    }
                    memset( c_file_path, 0, 150);
                }
            }
            //3.关闭目录
            closedir(dir);
        }
    }
    printf("如要结束程序运行，请执行如下命令：\n \
            $kill -9 %d\n\
            $kill -9 %d\n\
            $kill -9 %d\n", pid_ping, pid_tcpdump, pid_move);
    waitpid(pid_ping, NULL, 0);
    waitpid(pid_tcpdump, NULL, 0);
    waitpid(pid_move, NULL, 0);
}

