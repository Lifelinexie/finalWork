#include "head.h" 
#include "data.h" 
#include "creatDiretory.h"
#include "clear.h"
int main() {
	USER user = {//��ʼ���û��ṹ�� 
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
	printf("�����Ƿ��ܽ���������,�뵥��������Ҽ�,˫���˳�����\n\n");
	printf("���������,�Ҽ���������д��ڱ�Ե��ɫ����->ѡ��->����\n\n");
	printf("ȡ�����ٱ༭ģʽ,ѡ�в���ģʽ\n\n");
	color(4);
	printf("�������ʱ��������,���������´�3��\n\n");
	printf("Ϊ�˱�֤�����ܶ���:\n");
	printf("��ѡ��ʹ�þɰ����̨,�����´򿪳���\n\n");
	color(16);
	if(hOut == INVALID_HANDLE_VALUE || hIn == INVALID_HANDLE_VALUE)
	{
		printf("�޷�����������\n");
	}
	else
	{
		while (1)
		{
			//��ȡ�����¼�
			ReadConsoleInput(hIn, &mouseRecord, 1, &res);
			//��ȡ��굱ǰλ��
			pos = mouseRecord.Event.MouseEvent.dwMousePosition;
			//�����ǰ�¼�������¼�
			if (mouseRecord.EventType == MOUSE_EVENT)
			{
				//����������
				if (mouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					printf("���������� x: %d y: %d\n", pos.X, pos.Y);
				}
				//��������Ҽ�
				if (mouseRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
				{
					printf("����Ҽ����� x: %d y: %d\n", pos.X, pos.Y);
				}
				//�����˫�����˳�ѭ��
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
		if(i == 1)//���س���ʼ���� 
		{
			;
		}
		else if(i == 2)//������Ϸ��ʼ���� 
		{
			while(1)
			{
				int j;
				clear();
				j = gameView(&user);
				if(j == 0)//���س���ʼ���� 
				{
					CWFile(&user);
					break;
				}
			}
		}
		else if(i ==0)//�������� 
		{
			CWFile(&user);
			break;
		}
		else
		{
			printf("main.c have something error!\n");
		}
	}
	//�رվ��
	CloseHandle(hOut);
	CloseHandle(hIn);
	//system("pause");
	return 0;
}
