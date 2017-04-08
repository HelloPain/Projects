#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("%-20s%-10s%-10s%-10s\n", "记录号（商品ID）", "商品名", "数量", "价格");
	printf("%-20s%-10d%-10d%-10.2f\n", "lamp", 7, 7, 10.0);
	system("pause");
	return 0;
}