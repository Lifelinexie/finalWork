#include "head.h"

int creteDiretory(char* filepath)
{
    int res;
  	//filepathΪ����·��
  	//����ļ��в�����
  	//�����ļ���
    // ���� 0 ��ʾ�����ɹ���-1 ��ʾʧ��
  	if(_access(filepath,0)!=0)
  	{
  		res = mkdir(filepath);
	}
  	else
  	{
  		res = 1;	
	}
  	return res;
}
void diretoryOperate()
{
	int flag = creteDiretory("d:\\JsGame");
    int m;
    if(flag==-1)
        printf("�����ļ���ʧ��,��鿴����\n");
    else if(flag==0)
    {
    	m = creteDiretory("d:\\JSGame\\data");
    	if(m == 1)
    	{
    		; 
		}
	}
    else if(flag==1)
    {
    	//printf("�ļ����Ѵ���,��鿴����\n");
	}
}
