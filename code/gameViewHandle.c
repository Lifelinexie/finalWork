#include "head.h"

int gameViewHandle(USER *user)
{
	int choice;
	
	while(1)
	{
		if(scanf("%d",&choice) == 1)
		{
			if(choice > 0 && choice < 7)
			{
				clear();
				switch(choice)
				{
					case 1:
						return commonGame(user);//��ͨ�� 
					case 2:
						//�鿴��Ϣ
						lookData(user); 
						return 1;
					case 3:
						printf("�������ܴ�����\n");//ǩ��
						return 1;
					case 4:
						printf("�������ܴ�����\n");//��ֵ
						return 1;
					case 5:
						return 0;//�˳���Ϸ 
				}
			}
			else
			{
				printf("����������ݷ�Χ��������������(1~6)\n");
			}
		}
		else
		{
			printf("����������ݸ�ʽ��������������\n");
			fflush(stdin);
		}
	}
}
