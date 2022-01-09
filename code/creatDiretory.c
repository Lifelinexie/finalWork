#include "head.h"

int creteDiretory(char* filepath)
{
    int res;
  	//filepath为绝对路径
  	//如果文件夹不存在
  	//创建文件夹
    // 返回 0 表示创建成功，-1 表示失败
  	if(_access(filepath,0)!=0)
  	{
  		res = mkdir(filepath);
	}
  	else
  	{
  		res = 1;	
	}
  	return res;
}
void diretoryOperate()
{
	int flag = creteDiretory("d:\\JsGame");
    int m;
    if(flag==-1)
        printf("创建文件夹失败,请查看帮助\n");
    else if(flag==0)
    {
    	m = creteDiretory("d:\\JSGame\\data");
    	if(m == 1)
    	{
    		; 
		}
	}
    else if(flag==1)
    {
    	//printf("文件夹已存在,请查看帮助\n");
	}
}
