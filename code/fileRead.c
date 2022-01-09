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
		//格式化读取文件内容到结构体中 
		//数据的读取 
		//读取账号密码 
		fscanf(file,"%s\n%s\n",user->account,user->passWord);
		//读取玩家一的相关数据 
		fscanf(file,"%d\n%d\n%d\n",&user->playerOne.magic,&user->playerOne.magicChoice,&user->playerOne.score);
		for(int i=0;i < MAGIC_MAX;i++)
		{
			for(int j=0;j < MAX;j++)
			{
				fscanf(file,"%d ",&user->playerOne.magic.magicNum[i][j]);
			}
			fscanf(file,"%c",&ch);
		}
		//读取玩家二的相关数据 
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
