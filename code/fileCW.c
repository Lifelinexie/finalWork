#include "head.h"
#include "fileCW.h"
int CWFile(USER *user)
{
	FILE *file;
	char fileName[LEN];
	char fileConten[LEN];
	
	sscanf("d:\\JSGame\\data\\","%s",fileName);
	strcat(fileName,user->account);
	strcat(fileName,".txt");
	
	file = fopen(fileName,"w");
	if(file == NULL)
	{
		fclose(file);
	}else{
		//���ݵ�д�� 
		//д���˺����� 
		fprintf(file,"%s\n%s\n",user->account,user->passWord);
		//д�����һ��������� 
		fprintf(file,"%d\n%d\n%d\n",user->playerOne.magic,user->playerOne.magicChoice,user->playerOne.score);
		for(int i=0;i < MAGIC_MAX;i++)
		{
			for(int j=0;j < MAX;j++)
			{
				fprintf(file,"%d ",user->playerOne.magic.magicNum[i][j]);
			}
			fprintf(file,"%c",'\n');
		}
		//д����Ҷ���������� 
		fprintf(file,"%d\n%d\n%d\n",user->playerTwo.magic,user->playerTwo.magicChoice,user->playerTwo.score);
		for(int i=0;i < MAGIC_MAX;i++)
		{
			for(int j=0;j < MAX;j++)
			{
				fprintf(file,"%d ",user->playerOne.magic.magicNum[i][j]);
			}
			fprintf(file,"%c",'\n');
		}
		fclose(file);
		return 1;
	}
	return 0;
}
