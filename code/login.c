#include "head.h" 
int login(USER *user)
{
	char ch[ACCOUNT_MAX * 2];
	char pw[PASSWORD_MAX * 2];
	char m;
	printf("��ӭ�ٴ��������Ϸ��������¼:\n");
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
			if(readFile(user) == 1)
			{
				printf("��ӭ����:");
				for(int i=0;i < strlen(ch);i++)
				{
					printf("%c",ch[i]);
				}
				printf("\n");
				break;
			} 
			else
			{
				printf("�˺Ų����ڣ�����������(c/C)�򷵻���һҳ��ע��һ���˺�(b/B)\n");
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
						printf("�����������˺�\n");
						fflush(stdin);
						break;
					}
					else
					{
						printf("��������ȷ�ַ�\n");
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
			//�ṹ���е�password��pw�Ƚ�"
			if(strcmp(user->passWord,pw) == 0)
			{
				printf("����������ȷ!\n");
				strncpy(user->passWord,pw,PASSWORD_MAX - 1);
				break;	
			} 
			else
			{
				printf("�˺������������������(c/C)�򷵻���һҳ��(b/B)\n");
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
						printf("��������������\n");
						fflush(stdin);
						break;
					}
					else
					{
						printf("��������ȷ�ַ�\n");
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
	printf("��ϲ���¼�ɹ����Ͻ���һ�Ѱ�!\n");
	return 2;
}
