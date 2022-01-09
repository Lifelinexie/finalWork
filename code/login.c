#include "head.h" 
int login(USER *user)
{
	char ch[ACCOUNT_MAX * 2];
	char pw[PASSWORD_MAX * 2];
	char m;
	printf("欢迎再次体验此游戏，请您登录:\n");
	printf("账号(英文or数字，长度小于10):\n");
	while(1)
	{

		scanf("%s",ch);
		if(strlen(ch) > ACCOUNT_MAX - 1)
		{
			printf("您输入的账号长度是%d,请重新输入。\n",strlen(ch));
		}
		else if(strlen(ch) > 0 && strlen(ch) < 10 )
		{
			strncpy(user->account,ch,ACCOUNT_MAX - 1);
			if(readFile(user) == 1)
			{
				printf("欢迎回来:");
				for(int i=0;i < strlen(ch);i++)
				{
					printf("%c",ch[i]);
				}
				printf("\n");
				break;
			} 
			else
			{
				printf("账号不存在，请重新输入(c/C)或返回上一页面注册一个账号(b/B)\n");
				while(1)
				{
					scanf("%c",&m);
					if(m == 'B' || m == 'b')
					{
						
						clear();
						return 1;
					}
					else if(m == 'C' || m == 'c')
					{
						printf("请重新输入账号\n");
						fflush(stdin);
						break;
					}
					else
					{
						printf("请输入正确字符\n");
					}	
				}			
			}
		}
		else
		{
			printf("longin.c account have something error! \n");
			break;
		}
	}
	printf("请输入密码(长度小于12):\n");
	while(1)
	{
		scanf("%s",pw);
		if(strlen(pw) > PASSWORD_MAX - 1)
		{
			printf("您输入的密码长度是%d,请重新输入。\n",strlen(pw));
		}
		else if(strlen(pw) > 0 && strlen(pw) < 12 )
		{
			//结构体中的password与pw比较"
			if(strcmp(user->passWord,pw) == 0)
			{
				printf("密码输入正确!\n");
				strncpy(user->passWord,pw,PASSWORD_MAX - 1);
				break;	
			} 
			else
			{
				printf("账号输入错误，请重新输入(c/C)或返回上一页面(b/B)\n");
				while(1)
				{
					scanf("%c",&m);
					if(m == 'B' || m == 'b')
					{
						clear();
						return 1;
					}
					else if(m == 'C' || m == 'c')
					{
						printf("请重新输入密码\n");
						fflush(stdin);
						break;
					}
					else
					{
						printf("请输入正确字符\n");
					}	
				}	
			} 
		}
		else
		{
			printf("login.c password have something error! \n");
			break;
		}
	}
	printf("恭喜你登录成功，赶紧来一把吧!\n");
	return 2;
}
