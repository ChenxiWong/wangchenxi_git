//遍历一个目录中的所有内容
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
	//1.打开目录
	DIR* dir = opendir(argv[1]);
	if(NULL == dir)
	{
		perror("opendir"),exit(-1);
	}
	//2.读取目录中所有内容
	// 普通文件类型 8  目录的类型 4
	//struct dirent* ent = readdir(dir);
	//while(ent != NULL)
	struct dirent* ent;
	while(ent = readdir(dir))
	{
		//printf("%d,%s\n",ent->d_type,ent->d_name);
		// ent[0] => *(ent+0) =>*ent
		//printf("%d,%s\n",ent[0].d_type,ent[0].d_name);
		printf("size = %d , type = %d, name = %s\n",(*ent).d_reclen,(*ent).d_type,(*ent).d_name);
		//读取下一个
		//ent = readdir(dir);
	}
	//3.关闭目录
	closedir(dir);
	return 0;
}


