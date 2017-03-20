# Last Update:2016-09-04 23:51:50
#########################################################################
# File Name: 处理ubuntu软件中心打不开的问题.sh
# Author: wangchenxi
# mail: chinawangchenxi@gmail.com
# Created Time: 2016年09月04日 星期日 23时51分50秒
#########################################################################
#!/bin/bash
sudo apt-get update
sudo apt-get dist-upgrade
sudo apt-get install --reinstall software-center
