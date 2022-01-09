#include "head.h"
#include "judgeAccount.h"
#include "fileCW.h"
#include "back.h"
int registe(USER *user)
{
	char ch[ACCOUNT_MAX * 2];
	char pw[PASSWORD_MAX * 2];
	printf("欢迎体验此游戏，请注册一个账号:\n");
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
			if(judgeAccount(ch))
			{
				if(CWFile(user) == 1)
				{
					printf("你好:");
					for(int i=0;i < strlen(ch);i++)
					{
						printf("%c",ch[i]);
					}
					printf("\n");
					break;	
				}
				else
				{
					printf("创建用户失败请返回查看帮助->注册登录注意\n");
					printf("返回上一级请输入b/B\n");
					if(back())
					{
						return 1;
					}
				}
			}
			else
			{
				printf("该账户已存在,请重新注册\n");
			}
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
			strncpy(user->passWord,pw,PASSWORD_MAX - 1);
			break;
		}
		else
		{
			printf("register.c password have something error! \n");
			break;
		}
	}
	printf("恭喜你注册成功，赶紧来一把吧!\n");
	CWFile(user);
	return 2;
} 
