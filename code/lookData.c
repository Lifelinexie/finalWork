#include "head.h"
void lookData(USER *user)
{
	printf("玩家一:\n");
	printf("分数:%d\n",user->playerOne.score);
	printf("段位:业余%d段\n\n",user->playerOne.score / 100);
	printf("玩家二:\n");
	printf("分数:%d\n",user->playerTwo.score);
	printf("段位:业余%d段\n\n",user->playerTwo.score / 100);
}
