#include "head.h"
void lookData(USER *user)
{
	printf("���һ:\n");
	printf("����:%d\n",user->playerOne.score);
	printf("��λ:ҵ��%d��\n\n",user->playerOne.score / 100);
	printf("��Ҷ�:\n");
	printf("����:%d\n",user->playerTwo.score);
	printf("��λ:ҵ��%d��\n\n",user->playerTwo.score / 100);
}
