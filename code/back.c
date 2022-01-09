#include "head.h"

int back()
{
	char ch;
	while(1)
	{
		scanf("%c",&ch);
		if(ch == 'B' || ch == 'b')
		{
			clear();
			return 1;
		}
		else{
			printf("请按要求输入\n");
			fflush(stdin);
		}
	}	
} 
