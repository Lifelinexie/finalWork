#ifndef DATA_H
#define DATA_H 
//该头文件存放的是游戏中的一些结构体等数据
#define BOARD_MAX 15 //棋盘的最大规格15 * 15
#define MAGIC_MAX 8//法术的最大种类8
#define MAX 2 //法术数据的最大数量 
#define ACCOUNT_MAX 10 //账号的最大长度
#define PASSWORD_MAX 12 //密码的最大长度
//法术结构体 
typedef struct  Magic{
	//magic数组一维下标表示法术的种类，第一个储存的值表示法术等级，第二个储存的值表示法术效果 
	int magicNum[MAGIC_MAX][MAX];
}MGC;

//声明玩家结构体定义玩家一和玩家二 

typedef struct Player{
	
	int skillPoints;//技能点 
	int score;//分数 
	int magicChoice;//选择的法术 -1代表还未选择法术 
	MGC magic;//法术结构体 
	
}PYR;
//玩家结构体 
typedef struct User{
	
	char account[ACCOUNT_MAX];//账号 
	char passWord[PASSWORD_MAX];//密码 
	int Board[BOARD_MAX][BOARD_MAX];//棋盘二维数组,0代表棋盘，1代表黑子，二代表白子
	PYR playerOne;//玩家一 
	PYR playerTwo;//玩家二 

}USER; 

MGC userMagic;//定义法术结构体 
PYR PlayerOne;//定义玩家一结构体
PYR PlayerTow;//定义玩家二结构体
	
#endif 
