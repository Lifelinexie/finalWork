#include "head.h"
#include "programViewHandle.h"
//自定义函数根据参数改变颜色 
void color(short x)	
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色 
    else//默认的颜色白色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
//程序开始界面 
int programView(USER *user)
{
	
	color(2);
	printf("\t*******************************************\n");
	printf("\t*****************五子棋游戏****************\n");
	printf("\t*******************************************\n");	
	printf("\t*******************************************\n");
	color(11);	
	printf("\t*****************  一:关于  ***************\n");
	printf("\t*****************  二:帮助  ***************\n");
	printf("\t*****************  三:注册  ***************\n");
	printf("\t*****************  四:登录  ***************\n");
	printf("\t*****************  五:退出  ***************\n"); 
	color(2); 
	printf("\t*******************************************\n");
	color(4);
	printf("\t*****注意**********************************\n");
	printf("\t*********开始游戏前请看帮助****************\n");	
	printf("\t*********请输入输入数字(1~5)***************\n");
	color(2);
	printf("\t*******************************************\n");	
	printf("\t*******************************************\n");
	color(16);
	
	return programViewHandle(user);	
} 
