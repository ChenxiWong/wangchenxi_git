// Last Update:2017-04-26 14:04:06
/**
 * @file fork.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-26
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t fp = fork();
    if(fp < 0)
    {
        printf("fork error.\n");
    }
    if( fp == 0)
    {
        printf("hello, world!--pid = %ld .\n", getpid());
        sleep(10);
    }else
    {
        pid_t sp = wait(NULL);
        printf("sp is %ld\n", sp);
    }
}
