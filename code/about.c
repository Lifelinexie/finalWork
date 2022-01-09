#include "head.h"
#include "back.h"
int about()
{
	
	printf("该程序的名称:五子棋\n");
	printf("该程序版本为2.0版本\n");
	printf("开发时间:2022.01.08完成\n"); 
	printf("开发者信息:\n");
	printf("姓名:谢文垒\n");
	printf("学号:8008121016\n");
	printf("专业:计算机II类\n");
	printf("班级:2101班\n");
	printf("按B/b返回程序开始界面\n");
	
	if(back())
	{
		return 1;
	}
}
