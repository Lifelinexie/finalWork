#include "head.h"
#include "fileRead.h"
int readFile(USER *user)
{
	FILE *file;
	char fileName[LEN];
	char ch;
	
	sscanf("d:\\JSGame\\data\\","%s",fileName);
	strcat(fileName,user->account);
	strcat(fileName,".txt");
	
	file = fopen(fileName,"r");
	if(file == NULL)
	{
		fclose(file);	
	}else{
		//��ʽ����ȡ�ļ����ݵ��ṹ���� 
		//���ݵĶ�ȡ 
		//��ȡ�˺����� 
		fscanf(file,"%s\n%s\n",user->account,user->passWord);
		//��ȡ���һ��������� 
		fscanf(file,"%d\n%d\n%d\n",&user->playerOne.magic,&user->playerOne.magicChoice,&user->playerOne.score);
		for(int i=0;i < MAGIC_MAX;i++)
		{
			for(int j=0;j < MAX;j++)
			{
				fscanf(file,"%d ",&user->playerOne.magic.magicNum[i][j]);
			}
			fscanf(file,"%c",&ch);
		}
		//��ȡ��Ҷ���������� 
		fscanf(file,"%d\n%d\n%d\n",&user->playerTwo.magic,&user->playerTwo.magicChoice,&user->playerTwo.score);
		for(int i=0;i < MAGIC_MAX;i++)
		{
			for(int j=0;j < MAX;j++)
			{
				fscanf(file,"%d ",&user->playerOne.magic.magicNum[i][j]);
			}
			fscanf(file,"%c",&ch);
		}
		fclose(file);
		return 1;
	}
	return 0;
}
