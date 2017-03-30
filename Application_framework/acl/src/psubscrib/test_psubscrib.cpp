// Last Update:2017-03-28 15:43:25
/**
 * @file test_psubscrib.cpp
 * @brief 
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-03-28
 */

#include "acl_cpp/lib_acl.hpp"
#include "lib_acl.h"

int main(int argc, char* argv[])
{
    int  ch, n = 1, conn_timeout = 10, rw_timeout = 0;
    acl::string addr("127.0.0.1:6379"), cmd;
    bool cluster_mode = false;
    acl::acl_cpp_init();

    acl::redis_client_cluster cluster;
    cluster.set(addr.c_str(), 100, conn_timeout, rw_timeout);

    acl::redis_client client(addr.c_str(), conn_timeout, rw_timeout);

    acl::redis_pubsub redis;

    if (cluster_mode)
        redis.set_cluster(&cluster, 100);
    else
        redis.set_client(&client);


}
