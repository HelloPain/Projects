#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
int ways[40][30] = { 0 };
int w[22] = { 0 };
int f(int wei,int k)//w�������ǰk����Ʒ
{
	if (wei <= 0)
		return 1;
	if (k <= 0)
		return 0;
	return f(wei,k-1)+f(wei-w[k],k-1);//ѡ��k����Ʒ���߲�ѡ
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
			ways[i][k] = ways[i][k- 1];//����������û�зŵ�k����Ʒʱ�ķ���
			if (i - w[k] >= 0)//�������������k����Ʒ���Ǵ���0,��ȥ��k����Ʒ
			{
				ways[i][k] += ways[i-w[k]][k - 1];
			}
		}
	}*/
	cout << f(40, N) << endl;

	system("pause");
    return 0;
}

