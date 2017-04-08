#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a = 1; int *pa = 0;
	pa = &a;
	(*pa)++;
	printf("%d", *pa);
	system("pause");
	return 0;
}