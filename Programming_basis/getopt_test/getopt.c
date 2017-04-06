// Last Update:2017-04-05 13:00:52
/**
 * @file getopt.c
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-04-05
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int ch = 0;
    opterr = 0;
    while ((ch = getopt(argc,argv,"a:b:c:d:e:f:"))!=-1)
    {
        switch(ch)
        {
            case 'a':
                {
                    printf("optind:%d\n",optind);
                    printf("option a's optarg is %s\n",optarg);
                    break;
                }
            case 'b':
                {
                    printf("optind:%d\n",optind);
                    printf("option b 's optarg is %s\n", optarg);
                    break;
                }
            case '1':
                {
                    printf("optind:%d\n",optind);
                    printf("option 1 's optarg is %s\n", optarg);
                    break;
                }
            default:
                {
                    printf("other option :%c\n",ch);
                    printf("optopt +%c\n",optopt);
                }
        }
        ch = 0;
    }
}

