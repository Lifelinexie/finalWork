#include "head.h" 
#include "data.h" 
#include "creatDiretory.h"
#include "clear.h"
int main() {
	USER user = {//初始化用户结构体 
			" ",//user.account[ACCOUNT_MAX]
			" ",//user.passWord[PASSWORD_MAX]
			{0},
			{
				600,//user.PlayerOne.skillPoints
				0,//user.PlayerOne.score
				-1,//user.PlayerOne.magicChoice
				{0} //user.PlayerOne.magic.magicNum[MAGIC_MAX][SKILL_RANK_MAX]
			},
			{
				600,//user.PlayerTow.skillPoints
				0,//user.PlayerTow.score
				-1,//user.PlayerTow.magicChoice
				{0} //user.PlayerTow.magic.magicNum[MAGIC_MAX][SKILL_RANK_MAX]
			}
		};
	//定义句柄变量
	HANDLE hOut = NULL;
	HANDLE hIn = NULL;
	//定义输入事件结构体
	INPUT_RECORD mouseRecord;
	//用于存储读取记录
	DWORD res;
	//用于存储鼠标当前位置
	COORD pos;
	//获取标准输出句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//获取标准输入句柄
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	printf("测试是否能进行鼠标操作,请单击左键或右键,双击退出测试\n\n");
	printf("如果不能请,右键点击命令行窗口边缘白色部分->选项->属性\n\n");
	printf("取消快速编辑模式,选中插入模式\n\n");
	color(4);
	printf("如果下棋时出现闪退,请至少重新打开3次\n\n");
	printf("为了保证棋盘能对齐:\n");
	printf("请选中使用旧版控制台,再重新打开程序\n\n");
	color(16);
	if(hOut == INVALID_HANDLE_VALUE || hIn == INVALID_HANDLE_VALUE)
	{
		printf("无法进行鼠标操作\n");
	}
	else
	{
		while (1)
		{
			//读取输入事件
			ReadConsoleInput(hIn, &mouseRecord, 1, &res);
			//获取鼠标当前位置
			pos = mouseRecord.Event.MouseEvent.dwMousePosition;
			//如果当前事件是鼠标事件
			if (mouseRecord.EventType == MOUSE_EVENT)
			{
				//单击鼠标左键
				if (mouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					printf("鼠标左键单击 x: %d y: %d\n", pos.X, pos.Y);
				}
				//单击鼠标右键
				if (mouseRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
				{
					printf("鼠标右键单击 x: %d y: %d\n", pos.X, pos.Y);
				}
				//如果是双击就退出循环
				if (mouseRecord.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
				{
					break;
				}
			}
		}
	}
	
	clear(); 
	while(1)
	{
		int i;
		diretoryOperate();
		i = programView(&user);
		if(i == 1)//返回程序开始界面 
		{
			;
		}
		else if(i == 2)//进入游戏开始界面 
		{
			while(1)
			{
				int j;
				clear();
				j = gameView(&user);
				if(j == 0)//返回程序开始界面 
				{
					CWFile(&user);
					break;
				}
			}
		}
		else if(i ==0)//结束程序 
		{
			CWFile(&user);
			break;
		}
		else
		{
			printf("main.c have something error!\n");
		}
	}
	//关闭句柄
	CloseHandle(hOut);
	CloseHandle(hIn);
	//system("pause");
	return 0;
}
