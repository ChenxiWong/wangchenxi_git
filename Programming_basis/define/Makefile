# Last Update:2017-05-22 16:02:49
#########################################################################
# File Name: Makefile
# Author: wangchenxi
# mail: chinawangchenxi@gmail.com
# Created Time: 2017年05月22日 星期一 16时02分49秒
# brief:
#########################################################################
.PHONY: all  clean
BIN=define.i
CC=gcc
CFLAGS=-E
all:$(BIN)
%.i:%.c
	$(CC) -o $@ $< $(CFLAGS)
clean:
	rm -rf $(BIN)
