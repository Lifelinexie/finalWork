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
						return commonGame(user);//普通版 
					case 2:
						//查看信息
						lookData(user); 
						return 1;
					case 3:
						printf("后续功能待完善\n");//签到
						return 1;
					case 4:
						printf("后续功能待完善\n");//充值
						return 1;
					case 5:
						return 0;//退出游戏 
				}
			}
			else
			{
				printf("你输入的数据范围有误，请重新输入(1~6)\n");
			}
		}
		else
		{
			printf("你输入的数据格式有误，请重新输入\n");
			fflush(stdin);
		}
	}
}
