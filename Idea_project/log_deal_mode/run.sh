# Last Update:2017-04-05 15:20:11
#########################################################################
# File Name: run.sh
# Author: wangchenxi
# mail: chinawangchenxi@gmail.com
# Created Time: 2017年04月05日 星期三 15时20分11秒
# brief:
#########################################################################
#!/bin/bash 
rm -rf *.gch wyxLogDeal
g++ -g main.cpp -I../include/ -I. log_analysiser.cpp  -L../lib/ -lxml2 read_mysql.h read_mysql.cpp c_mysql.cpp c_mysql.h -lmysqlclient arrange_table.cpp arrange_table.h commit_tools.h commit_tools.cpp produce_handle.cpp produce_handle.h -ljson_linux-gcc-4.8.5_libmt handle.cpp handle.h log_message.cpp log_message.h -o wyxLogDeal
