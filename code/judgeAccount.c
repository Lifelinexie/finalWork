#include "head.h"
#include "judgeAccount.h"
int judgeAccount(char ch[])
{
	char fileName[LEN];
	
	sscanf("d:\\JSGame\\data\\","%s",fileName);
	strcat(fileName,ch);
	strcat(fileName,".txt");
	int res;
	
  	if(access(fileName,0) == 0)
  	{
  		res = 0;
	}
  	else
  	{
  		res = 1;	
	}
  	return res;
}
