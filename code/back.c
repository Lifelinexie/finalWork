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
			printf("�밴Ҫ������\n");
			fflush(stdin);
		}
	}	
} 
