#include "head.h"

int programViewHandle(USER *user)
{
	int choice;
	while(1)
	{
		if(scanf("%d",&choice) == 1)
		{
			if(choice > 0 && choice < 6)
			{
				clear();
				switch(choice)
				{
					case 1:
						return about();
						break;
					case 2:
						return help();
						break;
					case 3:
						return registe(user);
						break;
					case 4:
						return login(user);
						break;
					case 5:
						printf("���Ѿ��˳��ó���\n");
						return 0;
						break;
					default:
						printf("programViewHandle.c have something error!\n");	
				}
				break;
			}
			else
			{
				printf("����������ݷ�Χ��������������(1~5)\n");
			}
		}
		else
		{
			printf("����������ݸ�ʽ��������������\n");
			fflush(stdin);
		}
	}
}
