#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
int ways[40][30] = { 0 };
int w[22] = { 0 };
int f(int wei,int k)//w个体积，前k个物品
{
	if (wei <= 0)
		return 1;
	if (k <= 0)
		return 0;
	return f(wei,k-1)+f(wei-w[k],k-1);//选第k号物品或者不选
}
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> w[i]; 
	}
	
	/*for (int j = 0; j < 40; j++)
		ways[j][0] = 0;
	for (int i = 1; i < 40; i++)
	{
		for (int k= 1; k < N; k++)
		{
			ways[i][k] = ways[i][k- 1];//先让他等于没有放第k个物品时的方法
			if (i - w[k] >= 0)//如果质量减掉第k个物品还是大于0,就去第k个物品
			{
				ways[i][k] += ways[i-w[k]][k - 1];
			}
		}
	}*/
	cout << f(40, N) << endl;

	system("pause");
    return 0;
}

