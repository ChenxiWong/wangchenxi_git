# Last Update:2016-09-06 15:40:58
#########################################################################
# File Name: ssh_no_password.sh
# Author: wangchenxi
# mail: chinawangchenxi@gmail.com
# Created Time: 2016年09月06日 星期二 15时40分58秒
#########################################################################
#!/bin/bash
echo "举例如：现在需要免密码登录root@192.168.1.100 \n
在当前主机终端，执行如下命令:\n
ssh-keygen -t rsa -P ""\n
scp ~/.ssh/id_rsa.pub root@192.168.1.100:/root/tmp_id_rsa.pub\n
ssh root@192.168.1.100\n
此时还需要输入密码\n
ssh-keygen -t rsa -P ""\n
cat ~/tmp_id_rsa.pub  >> ~/.ssh/authorized_keys\n
exit
然后就可以免密码登录root@192.168.1.100\n
尝试执行:ssh root@192.168.1.100 \n "
