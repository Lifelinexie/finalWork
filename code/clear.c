#include "head.h"

void clear()
{
	//����������
	HANDLE hOut = NULL;
	HANDLE hIn = NULL;
	//���������¼��ṹ��
	INPUT_RECORD mouseRecord;
	//���ڴ洢��ȡ��¼
	DWORD res;
	//���ڴ洢��굱ǰλ��
	COORD pos;
	//��ȡ��׼������
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//��ȡ��׼������
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	if(hOut == INVALID_HANDLE_VALUE || hIn == INVALID_HANDLE_VALUE)
	{
		printf("���������ʧ��\n");
	}
	else
	{
		printf("�뵥������Ҽ�����\n");
		while (1)
		{
			//��ȡ�����¼�
			ReadConsoleInput(hIn, &mouseRecord, 1, &res);
			//��ȡ��굱ǰλ��
			pos = mouseRecord.Event.MouseEvent.dwMousePosition;
			//�����ǰ�¼�������¼�
			if (mouseRecord.EventType == MOUSE_EVENT)
			{
				if (mouseRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
				{
					pos.X = 0,pos.Y = 0;
					SetConsoleCursorPosition(hOut, pos);
					//ʵ�����ع�� 
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
