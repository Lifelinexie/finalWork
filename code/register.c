#include "head.h"
#include "judgeAccount.h"
#include "fileCW.h"
#include "back.h"
int registe(USER *user)
{
	char ch[ACCOUNT_MAX * 2];
	char pw[PASSWORD_MAX * 2];
	printf("��ӭ�������Ϸ����ע��һ���˺�:\n");
	printf("�˺�(Ӣ��or���֣�����С��10):\n");
	while(1)
	{
		scanf("%s",ch);
		if(strlen(ch) > ACCOUNT_MAX - 1)
		{
			printf("��������˺ų�����%d,���������롣\n",strlen(ch));
		}
		else if(strlen(ch) > 0 && strlen(ch) < 10 )
		{
			strncpy(user->account,ch,ACCOUNT_MAX - 1);
			if(judgeAccount(ch))
			{
				if(CWFile(user) == 1)
				{
					printf("���:");
					for(int i=0;i < strlen(ch);i++)
					{
						printf("%c",ch[i]);
					}
					printf("\n");
					break;	
				}
				else
				{
					printf("�����û�ʧ���뷵�ز鿴����->ע���¼ע��\n");
					printf("������һ��������b/B\n");
					if(back())
					{
						return 1;
					}
				}
			}
			else
			{
				printf("���˻��Ѵ���,������ע��\n");
			}
		}
	}
	printf("����������(����С��12):\n");
	while(1)
	{
		scanf("%s",pw);
		if(strlen(pw) > PASSWORD_MAX - 1)
		{
			printf("����������볤����%d,���������롣\n",strlen(pw));
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
	printf("��ϲ��ע��ɹ����Ͻ���һ�Ѱ�!\n");
	CWFile(user);
	return 2;
} 
