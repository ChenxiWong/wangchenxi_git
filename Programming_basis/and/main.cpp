// Last Update:2017-04-21 11:14:48
/**
 * @file main.c
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-21
 */
#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;
int main(int argc, char* argv[])
{
    uint32_t mask = inet_addr("111.161.88.105");
    struct in_addr in;
    in.s_addr = mask;
    printf("%08llx, %s\n", mask, inet_ntoa(in));
    uint32_t ip = inet_addr("255.255.255.0");
    uint32_t value = mask & ip;
    uint32_t ip2 = inet_addr("111.161.88.111");
    if(value == (ip2 & ip))
    {
        printf("-----\n");
    }
}
