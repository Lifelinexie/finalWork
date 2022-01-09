#include "head.h"

void clear()
{
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
	if(hOut == INVALID_HANDLE_VALUE || hIn == INVALID_HANDLE_VALUE)
	{
		printf("鼠标句柄操作失败\n");
	}
	else
	{
		printf("请单击鼠标右键清屏\n");
		while (1)
		{
			//读取输入事件
			ReadConsoleInput(hIn, &mouseRecord, 1, &res);
			//获取鼠标当前位置
			pos = mouseRecord.Event.MouseEvent.dwMousePosition;
			//如果当前事件是鼠标事件
			if (mouseRecord.EventType == MOUSE_EVENT)
			{
				if (mouseRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
				{
					pos.X = 0,pos.Y = 0;
					SetConsoleCursorPosition(hOut, pos);
					//实现隐藏光标 
					for(int i=0;i < 200;i++)
					{
						printf("                                                        ");
					}
					pos.X = 0,pos.Y = 0;
					SetConsoleCursorPosition(hOut, pos);
					break;
				}
			}
				
		}
	}
	
}
