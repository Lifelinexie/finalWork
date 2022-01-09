#include "head.h"
#include "commonGame.h"
#include "time.h"
#include "clear.h"
int judgeWin(USER *user)
{
	int chessCount = 0;//棋盘的个数，判断是否平局 
	int whiteChess = 1;//黑棋连起来的棋子数 
	int blackChess = 1;//白棋连起来的棋子数 
	//横方向上判断 
	for (int j=0;j < BOARD_MAX;j++)
	{
		for(int k=0;k < BOARD_MAX - 1;k++)
		{
			if(user->Board[j][k] == user->Board[j][k+1] && user->Board[j][k] == 1)
			{
				blackChess++;
				if(blackChess == 5)
				{
					return 1;	
				}
			}
			else
			{
				blackChess = 1;
			}
			if(user->Board[j][k] == user->Board[j][k+1] && user->Board[j][k] == 2)
			{
				whiteChess++;
				if(whiteChess == 5)
				{
					return 2;	
				}				
			}
			else
			{
				whiteChess = 1;
			}
		}
	}
	//初始化为1,消除上一次判断的影响 
	whiteChess = 1;
	blackChess = 1;
	//竖方向的判断 
	for (int k=0;k < BOARD_MAX;k++)
	{
		for(int j=0;j < BOARD_MAX - 1;j++)
		{
			if(user->Board[j][k] == user->Board[j+1][k] && user->Board[j][k] == 1)
			{
				blackChess++;
				if(blackChess == 5)
				{
					return 1;	
				}
			}
			else
			{
				blackChess = 1;
			}
			if(user->Board[j][k] == user->Board[j+1][k] && user->Board[j][k] == 2)
			{
				whiteChess++;
				if(whiteChess == 5)
				{
					return 2;	
				}				
			}
			else
			{
				whiteChess = 1;
			}
		}
	}
	//初始化为1,消除上一次判断的影响 
	whiteChess = 1;
	blackChess = 1;
	//斜着方向的判断，分上下判断和两种方向 
	for (int j=0;j < BOARD_MAX;j++)//从(0,0)开始到(0,14)开始 
	{
		for(int k=0;k < BOARD_MAX - j - 1;k++)
		{
			if(user->Board[k][j+k] == user->Board[k+1][j+k+1] && user->Board[k][j+k] == 1)
			{
				blackChess++;
				if(blackChess == 5)
				{
					return 1;	
				}
			}
			else
			{
				blackChess = 1;
			}
			if(user->Board[k][j+k] == user->Board[k+1][j+k+1] && user->Board[k][j+k] == 2)
			{
				whiteChess++;
				if(whiteChess == 5)
				{
					return 2;	
				}				
			}
			else
			{
				whiteChess = 1;
			}
		}
	}
	//初始化为1,消除上一次判断的影响 
	whiteChess = 1;
	blackChess = 1;
	for (int j=1;j < BOARD_MAX;j++)//从(1,0)开始到(14,0)开始 
	{
		for(int k=0;k < BOARD_MAX - j - 1;k++)
		{
			if(user->Board[j+k][k] == user->Board[j+k+1][k+1] && user->Board[j+k][k] == 1)
			{
				blackChess++;
				if(blackChess == 5)
				{
					return 1;	
				}
			}
			else
			{
				blackChess = 1;
			}
			if(user->Board[j+k][k] == user->Board[j+k+1][k+1] && user->Board[j+k][k] == 2)
			{
				whiteChess++;
				if(whiteChess == 5)
				{
					return 2;	
				}				
			}
			else
			{
				whiteChess = 1;
			}
		}
	}
	for (int j=0;j < BOARD_MAX;j++)//从(14,0)开始到(14,14)开始 
	{
		for(int k=BOARD_MAX - 1;k > 0;k--)
		{
			if(user->Board[k][BOARD_MAX-k+j-1] == user->Board[k-1][BOARD_MAX-k+j] && user->Board[k][BOARD_MAX-k+j-1] == 1)
			{
				blackChess++;
				if(blackChess == 5)
				{
					return 1;	
				}
			}
			else
			{
				blackChess = 1;
			}
			if(user->Board[k][BOARD_MAX-k+j-1] == user->Board[k-1][BOARD_MAX-k+j] && user->Board[k][BOARD_MAX-k+j-1] == 2)
			{
				whiteChess++;
				if(whiteChess == 5)
				{
					return 2;	
				}				
			}
			else
			{
				whiteChess = 1;
			}
		}
	}
	//初始化为1,消除上一次判断的影响 
	whiteChess = 1;
	blackChess = 1;
	for (int j=BOARD_MAX-1;j > 0;j--)//从(13,0)开始到(0,0)开始 
	{
		for(int k=0;k < j + 1;k++)
		{
			if(user->Board[j-k-1][k] == user->Board[j-k-2][k+1] && user->Board[j+k][k] == 1)
			{
				blackChess++;
				if(blackChess == 5)
				{
					return 1;	
				}
			}
			else
			{
				blackChess = 1;
			}
			if(user->Board[j-k-1][k] == user->Board[j-k-2][k+1] && user->Board[j-k-1][k] == 2)
			{
				whiteChess++;
				if(whiteChess == 5)
				{
					return 2;	
				}				
			}
			else
			{
				whiteChess = 1;
			}
		}
	}
	for(int j=0;j < BOARD_MAX;j++)
	{
		for(int k=0;k < BOARD_MAX;k++)
		{
			if(user->Board[j][k] == 0)
			{
				chessCount++;
			}
		}
	}
	if(chessCount == 0)
	{
		return 3;
	}
	return 0;
}

void mouseResponse(int i,USER *user)
{
	//定义句柄变量
	HANDLE hOut = NULL;
	HANDLE hIn = NULL;
	//定义输入事件结构体
	INPUT_RECORD mouseRecord;
	//用于存储读取记录
	DWORD res;
	//用于存储鼠标当前位置
	COORD pos;
	//获取标准输出句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//获取标准输入句柄
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	
	while (1)
	{
		//读取输入事件
		ReadConsoleInput(hIn, &mouseRecord, 1, &res);
		//获取鼠标当前位置
		pos = mouseRecord.Event.MouseEvent.dwMousePosition;
		//如果当前事件是鼠标事件
		if (mouseRecord.EventType == MOUSE_EVENT)
		{
			//单击鼠标左键
			if (mouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				int j;								
				//judgeData()判断数据是否合理,如果合理break退出循环,否则重新输入。				
				j = judgeData(pos.Y,pos.X,i,user);
				if(j == 1)  
				{
					//实现覆盖输出棋盘 
					pos.X = 0,pos.Y = 0;
					SetConsoleCursorPosition(hOut, pos);
					//实现隐藏光标 
					CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // 第二个值为0表示隐藏光标
					SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
					break;
				}
				else if(j == 0)
				{
					printf("                                          ");					
					//实现覆盖提示语句 
					pos.X = 0,pos.Y = 18;
					SetConsoleCursorPosition(hOut, pos);
					//实现隐藏光标 
					CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // 第二个值为0表示隐藏光标
					SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

				}
			}
		}
	}
	//关闭句柄
//	CloseHandle(hOut);
//	CloseHandle(hIn);
//	getchar();
}

int judgePlayer(int i)
{
	int m;
	srand((unsigned)time(NULL));
	int p = rand()%2;
	if(i == 1)
	{
		if(p == 0)
		{
			printf("由玩家二执黑棋先下\n");//m为1
			m = 1; 
		}
		else if(p == 1)
		{
			printf("由玩家一执黑棋先下\n");//默认情况m为0 
			m = 0;
		}		
	}

	if(i % 2 == 1)
	{
		if(i == 1)
		{
			printf("现在是○棋落子\n");			
		}
		else
		{
			printf("\n现在是○棋落子\n");	
		}
	}
	else if(i % 2 == 0)
	{
		if(i == 1)
		{
			printf("现在是●棋落子\n");			
		}
		else
		{
			printf("\n现在是●棋落子\n");	
		}
	}
	return m;
}

int judgeData(int a,int b,int i,USER *user)
{
	
	if ((a >= 0 && a < BOARD_MAX) && (b >= 0 && b < BOARD_MAX * 2))
	{
		if(user->Board[a][b/2] != 0)
		{
			printf("该位置已有棋子,请在空白棋盘处下棋\n");
			return 0; 
		}
		else
		{
			printf("                                     ");//清除错误提示 
			changeBoard(a,b/2,i,user);//将横纵坐标和代表黑白棋的 i 传入 棋盘数组修改函数 
			return 1;
		}
	}
	else
	{
		printf("下棋错误,请在棋盘内下棋\n");
		return 0;
	}	
}

void changeBoard(int m,int n,int i,USER *user)
{
	if(i % 2 == 1)
	{
		user->Board[m][n] = 1;
	}
	else if(i % 2 == 0)
	{
		user->Board[m][n] = 2;
	}
	else
	{
		printf("commonGame.c->changeBoard have something error !\n"); 
	}
	
}

void chooseChessBoard(int x,int y)
{
	if(x == 0 && y != 0 && y != BOARD_MAX - 1)
	{
		printf("┬");
	}else if(x == 0 && y == 0)
	{
		printf("┌");
	}else if(x == 0 && y == BOARD_MAX - 1)
	{
		printf("┐%d",x + 1);
	}else if(y != 0 && x != 0 && x != BOARD_MAX - 1 && y != BOARD_MAX - 1)
	{
		printf("┼");
	}else if(y == 0 && x != 0 && x != BOARD_MAX - 1)
	{
		printf("├");
	}else if(y == BOARD_MAX - 1 && x != 0 && x != BOARD_MAX - 1)
	{
		printf("┤%d",x + 1);
	}else if(y == 0 && x == BOARD_MAX - 1)
	{
		printf("└");
	}else if(x == BOARD_MAX - 1 && y != 0 && y != BOARD_MAX - 1)
	{
		printf("┴");
	}else if(x == BOARD_MAX - 1 && y == BOARD_MAX - 1)
	{
		printf("┘%d",x + 1);
	}
}

int printBoard(int m,USER *user)
{
	int i,j,k;
	
	for(i=0;i < BOARD_MAX;i++)
	{
		for(j=0;j < BOARD_MAX;j++)
		{
			switch(user->Board[i][j])
			{
				case 0:
					chooseChessBoard(i,j);
					break;
				case 1:
					printf("○");
					break;
				case 2:
					printf("●");
					break;
				default:
					;	
					break;
			}
		}
		printf("\n");
	}
	for(k = 0;k < BOARD_MAX;k++)
	{
		printf("%-2d",k + 1);
	}
	printf("\n");
	return judgePlayer(m);
}

int gameOverView(int i,int m,USER *user)
{
	int choice; 
	printf("\t游戏结束,胜者获得100分,败者获得50分,平局都获得50分\n");
	if(i == 1)
	{
		if(m == 0)
		{
			printf("\t恭喜玩家一执黑棋获得胜利\n");
			user->playerOne.score += 100;
			user->playerTwo.score += 50;
		}
		else if(m == 1)
		{
			printf("\t恭喜玩家二执黑棋获得胜利\n");
			user->playerOne.score += 50;
			user->playerTwo.score += 100;
		}
	}
	else if(i == 2)
	{
		if(m == 0)
		{
			printf("\t恭喜玩家二执白棋获得胜利\n");
			user->playerOne.score += 50;
			user->playerTwo.score += 100;		
		}
		else if(m == 1)
		{
			printf("\t\t恭喜玩家一执白棋获得胜利\n");
			user->playerOne.score += 100;
			user->playerTwo.score += 50;
		}
	}
	else if(i == 3)
	{
		printf("\t二位真是卧龙凤雏,你们打成了平局\n");
		user->playerOne.score += 50;
		user->playerTwo.score += 50;
	}
	
	color(2);
	printf("\t*******************************************\n");
	printf("\t********************五子棋*****************\n");
	printf("\t*******************************************\n");	
	printf("\t*******************************************\n");
	color(11);	
	printf("\t****************一:返回游戏界面************\n");
	printf("\t*******************************************\n");
	printf("\t***************** 二:复盘  ****************\n");
	printf("\t*******************************************\n");
	printf("\t**************** 三:再来一局 **************\n");
	printf("\t*******************************************\n"); 
	color(2); 
	printf("\t*******************************************\n");
	printf("\t*******************************************\n");	
	printf("\t*******************************************\n");
	color(16);
	while(1)
	{
		if(scanf("%d",&choice) == 1)
		{
			if(choice > 0 && choice < 4)
			{
				if(choice != 2)
				{
					for(int m=0;m < BOARD_MAX;m++)
					{
						for(int n=0;n < BOARD_MAX;n++)
						{
							user->Board[m][n] = 0;
						}
					}
				}
				return choice;
			}
			else
			{
				printf("请输入正确的数据范围\n");
			}
		}
		else
		{
			printf("请输入正确的数据格式\n");
		}
		fflush(stdin);
	}
}

int commonGame(USER *user)
{ 
	int i;//判断胜负情况 
	int m;//m为0表示玩家一执黑棋，1表示玩家二执黑棋 
	int choice;//返回用户的判断 
	int chessPiece = 1;//奇数表示黑子下，偶数表示白字下 
	while(1)
	{
		choice = 0;
		m = printBoard(chessPiece,user);
		//判断胜负 
		i = judgeWin(user);
		if(i != 0)
		{
			printf("游戏结束\n");
			clear();
			choice = gameOverView(i,m,user);
			if(choice == 1)//返回游戏开始界面 
			{
				return 1;
			}
		}		
		if(choice == 3)//再来一局 
		{
			chessPiece = 1;
			clear();
		}
		else if(choice == 0)
		{
			mouseResponse(chessPiece,user);
			chessPiece += 1;	
		}
		else if(choice == 2)
		{
			;
		}

	}
	
}
