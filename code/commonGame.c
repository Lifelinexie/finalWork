#include "head.h"
#include "commonGame.h"
#include "time.h"
#include "clear.h"
int judgeWin(USER *user)
{
	int chessCount = 0;//���̵ĸ������ж��Ƿ�ƽ�� 
	int whiteChess = 1;//������������������ 
	int blackChess = 1;//������������������ 
	//�᷽�����ж� 
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
	//��ʼ��Ϊ1,������һ���жϵ�Ӱ�� 
	whiteChess = 1;
	blackChess = 1;
	//��������ж� 
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
	//��ʼ��Ϊ1,������һ���жϵ�Ӱ�� 
	whiteChess = 1;
	blackChess = 1;
	//б�ŷ�����жϣ��������жϺ����ַ��� 
	for (int j=0;j < BOARD_MAX;j++)//��(0,0)��ʼ��(0,14)��ʼ 
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
	//��ʼ��Ϊ1,������һ���жϵ�Ӱ�� 
	whiteChess = 1;
	blackChess = 1;
	for (int j=1;j < BOARD_MAX;j++)//��(1,0)��ʼ��(14,0)��ʼ 
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
	for (int j=0;j < BOARD_MAX;j++)//��(14,0)��ʼ��(14,14)��ʼ 
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
	//��ʼ��Ϊ1,������һ���жϵ�Ӱ�� 
	whiteChess = 1;
	blackChess = 1;
	for (int j=BOARD_MAX-1;j > 0;j--)//��(13,0)��ʼ��(0,0)��ʼ 
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
	//����������
	HANDLE hOut = NULL;
	HANDLE hIn = NULL;
	//���������¼��ṹ��
	INPUT_RECORD mouseRecord;
	//���ڴ洢��ȡ��¼
	DWORD res;
	//���ڴ洢��굱ǰλ��
	COORD pos;
	//��ȡ��׼������
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//��ȡ��׼������
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	
	while (1)
	{
		//��ȡ�����¼�
		ReadConsoleInput(hIn, &mouseRecord, 1, &res);
		//��ȡ��굱ǰλ��
		pos = mouseRecord.Event.MouseEvent.dwMousePosition;
		//�����ǰ�¼�������¼�
		if (mouseRecord.EventType == MOUSE_EVENT)
		{
			//����������
			if (mouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				int j;								
				//judgeData()�ж������Ƿ����,�������break�˳�ѭ��,�����������롣				
				j = judgeData(pos.Y,pos.X,i,user);
				if(j == 1)  
				{
					//ʵ�ָ���������� 
					pos.X = 0,pos.Y = 0;
					SetConsoleCursorPosition(hOut, pos);
					//ʵ�����ع�� 
					CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // �ڶ���ֵΪ0��ʾ���ع��
					SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
					break;
				}
				else if(j == 0)
				{
					printf("                                          ");					
					//ʵ�ָ�����ʾ��� 
					pos.X = 0,pos.Y = 18;
					SetConsoleCursorPosition(hOut, pos);
					//ʵ�����ع�� 
					CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // �ڶ���ֵΪ0��ʾ���ع��
					SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

				}
			}
		}
	}
	//�رվ��
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
			printf("����Ҷ�ִ��������\n");//mΪ1
			m = 1; 
		}
		else if(p == 1)
		{
			printf("�����һִ��������\n");//Ĭ�����mΪ0 
			m = 0;
		}		
	}

	if(i % 2 == 1)
	{
		if(i == 1)
		{
			printf("�����ǡ�������\n");			
		}
		else
		{
			printf("\n�����ǡ�������\n");	
		}
	}
	else if(i % 2 == 0)
	{
		if(i == 1)
		{
			printf("�����ǡ�������\n");			
		}
		else
		{
			printf("\n�����ǡ�������\n");	
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
			printf("��λ����������,���ڿհ����̴�����\n");
			return 0; 
		}
		else
		{
			printf("                                     ");//���������ʾ 
			changeBoard(a,b/2,i,user);//����������ʹ���ڰ���� i ���� ���������޸ĺ��� 
			return 1;
		}
	}
	else
	{
		printf("�������,��������������\n");
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
		printf("��");
	}else if(x == 0 && y == 0)
	{
		printf("��");
	}else if(x == 0 && y == BOARD_MAX - 1)
	{
		printf("��%d",x + 1);
	}else if(y != 0 && x != 0 && x != BOARD_MAX - 1 && y != BOARD_MAX - 1)
	{
		printf("��");
	}else if(y == 0 && x != 0 && x != BOARD_MAX - 1)
	{
		printf("��");
	}else if(y == BOARD_MAX - 1 && x != 0 && x != BOARD_MAX - 1)
	{
		printf("��%d",x + 1);
	}else if(y == 0 && x == BOARD_MAX - 1)
	{
		printf("��");
	}else if(x == BOARD_MAX - 1 && y != 0 && y != BOARD_MAX - 1)
	{
		printf("��");
	}else if(x == BOARD_MAX - 1 && y == BOARD_MAX - 1)
	{
		printf("��%d",x + 1);
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
					printf("��");
					break;
				case 2:
					printf("��");
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
	printf("\t��Ϸ����,ʤ�߻��100��,���߻��50��,ƽ�ֶ����50��\n");
	if(i == 1)
	{
		if(m == 0)
		{
			printf("\t��ϲ���һִ������ʤ��\n");
			user->playerOne.score += 100;
			user->playerTwo.score += 50;
		}
		else if(m == 1)
		{
			printf("\t��ϲ��Ҷ�ִ������ʤ��\n");
			user->playerOne.score += 50;
			user->playerTwo.score += 100;
		}
	}
	else if(i == 2)
	{
		if(m == 0)
		{
			printf("\t��ϲ��Ҷ�ִ������ʤ��\n");
			user->playerOne.score += 50;
			user->playerTwo.score += 100;		
		}
		else if(m == 1)
		{
			printf("\t\t��ϲ���һִ������ʤ��\n");
			user->playerOne.score += 100;
			user->playerTwo.score += 50;
		}
	}
	else if(i == 3)
	{
		printf("\t��λ�����������,���Ǵ����ƽ��\n");
		user->playerOne.score += 50;
		user->playerTwo.score += 50;
	}
	
	color(2);
	printf("\t*******************************************\n");
	printf("\t********************������*****************\n");
	printf("\t*******************************************\n");	
	printf("\t*******************************************\n");
	color(11);	
	printf("\t****************һ:������Ϸ����************\n");
	printf("\t*******************************************\n");
	printf("\t***************** ��:����  ****************\n");
	printf("\t*******************************************\n");
	printf("\t**************** ��:����һ�� **************\n");
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
				printf("��������ȷ�����ݷ�Χ\n");
			}
		}
		else
		{
			printf("��������ȷ�����ݸ�ʽ\n");
		}
		fflush(stdin);
	}
}

int commonGame(USER *user)
{ 
	int i;//�ж�ʤ����� 
	int m;//mΪ0��ʾ���һִ���壬1��ʾ��Ҷ�ִ���� 
	int choice;//�����û����ж� 
	int chessPiece = 1;//������ʾ�����£�ż����ʾ������ 
	while(1)
	{
		choice = 0;
		m = printBoard(chessPiece,user);
		//�ж�ʤ�� 
		i = judgeWin(user);
		if(i != 0)
		{
			printf("��Ϸ����\n");
			clear();
			choice = gameOverView(i,m,user);
			if(choice == 1)//������Ϸ��ʼ���� 
			{
				return 1;
			}
		}		
		if(choice == 3)//����һ�� 
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
