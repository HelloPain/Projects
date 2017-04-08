#include <stdio.h>
#include <stdlib.h>

int main()
{
	char info[30]; char *p;
	scanf("%[^\n]", info);
	for (p = info; (*p)>'9' || (*p)<'1'; p++);
	printf("%f",atof(p));
	system("pause");
	return 0;
}