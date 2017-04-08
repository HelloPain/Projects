#include <stdio.h>
#include <stdlib.h>

int main()
{
	char info[50]; char *p = info;
	scanf("%[^\n]", info);
	if (*p != '-1')
	{
		for (; (*p) != ' '; p++);
		p++; 
		printf("%d", atoi(p));
	}

	system("pause");
	return 0;
}