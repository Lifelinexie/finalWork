#ifndef GAMEVIEWHANDLE_H 
#define GAMEVIEWHANDLE_H   

//函数功能:对用户鼠标的响应 
void mouseResponse(int i,USER *user);
//函数功能:根据鼠标事件修改棋盘数组中的值,传入鼠标的位置和判断棋子颜色的i 
void changeBoard(int m,int n,int i,USER *user);
//函数功能:根据棋盘位置选择棋盘形状,传入鼠标的位置
void chooseChessBoard(int x,int y);
//函数功能:根据棋盘数组的值打印棋盘和棋子,根据传入断棋子颜色的m，显示黑棋下棋还是白棋下
//返回0表示玩家一执黑棋，1玩家二执黑棋 
int printBoard(int m,USER *user);
//函数功能:判断鼠标事件的数据是否合理,传入鼠标的位置和判断棋子颜色的i ,返回 0或1 
int judgeData(int a,int b,int i,USER *user);
 //传入判断棋子颜色的i ,让玩家随机执黑棋或白棋 
int judgePlayer(int i);
//判断胜负的函数，返回0,1,2,3分别表示无胜负，黑赢，白赢，平局 
int judgeWin(USER *user);
//游戏结束界面，显示输赢，加分，和选择再来一局或者回到游戏开始界面
//i等于1黑棋赢，2白棋赢，3平局，m为0表示玩家一执黑棋，1表示玩家二执黑棋 
int gameOverView(int i,int m,USER *user); 
//函数功能:是普通版下棋过程的主函数,返回1或2
int commonGame(USER *user);

//黑子●
//白子○
//上边框棋盘┬
//上左角棋盘┌
//上右角棋盘┐
//左边框棋盘├
//下左角棋盘└
//下边框棋盘┴
//下右角棋盘┘
//右边框棋盘┤  
//中间棋盘┼ 
//棋盘规格15 * 15 
 
//其中 8代表背景颜色，E代表字体颜色
//附颜色表：
//黑色 = 0
//蓝色 = 1
//绿色 = 2
//湖蓝色 = 3
//红色 = 4
//紫色 = 5
//黄色 = 6
//白色 = 7
//灰色 = 8
//淡蓝色=9
//淡绿色=A
//淡红色=C
//淡紫色=D
//淡黄色=E
//亮白色=F
#endif 
