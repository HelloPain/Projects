#include <stdio.h>  
#include <stdlib.h>
int arr[22], n;

int getAns(int sum, int k)
{
	if (sum == 0) return 1;
	if (k == 0) return 0;
	return getAns(sum, k - 1) + getAns(sum - arr[k], k - 1);
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", arr + i);
	printf("%d\n", getAns(40, n));
	system("pause");
	return 0;
}
