#ifndef DATA_H
#define DATA_H 
//��ͷ�ļ���ŵ�����Ϸ�е�һЩ�ṹ�������
#define BOARD_MAX 15 //���̵������15 * 15
#define MAGIC_MAX 8//�������������8
#define MAX 2 //�������ݵ�������� 
#define ACCOUNT_MAX 10 //�˺ŵ���󳤶�
#define PASSWORD_MAX 12 //�������󳤶�
//�����ṹ�� 
typedef struct  Magic{
	//magic����һά�±��ʾ���������࣬��һ�������ֵ��ʾ�����ȼ����ڶ��������ֵ��ʾ����Ч�� 
	int magicNum[MAGIC_MAX][MAX];
}MGC;

//������ҽṹ�嶨�����һ����Ҷ� 

typedef struct Player{
	
	int skillPoints;//���ܵ� 
	int score;//���� 
	int magicChoice;//ѡ��ķ��� -1����δѡ���� 
	MGC magic;//�����ṹ�� 
	
}PYR;
//��ҽṹ�� 
typedef struct User{
	
	char account[ACCOUNT_MAX];//�˺� 
	char passWord[PASSWORD_MAX];//���� 
	int Board[BOARD_MAX][BOARD_MAX];//���̶�ά����,0�������̣�1������ӣ����������
	PYR playerOne;//���һ 
	PYR playerTwo;//��Ҷ� 

}USER; 

MGC userMagic;//���巨���ṹ�� 
PYR PlayerOne;//�������һ�ṹ��
PYR PlayerTow;//������Ҷ��ṹ��
	
#endif 
