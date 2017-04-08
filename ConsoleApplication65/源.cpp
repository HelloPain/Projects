#include <iostream>
#include <algorithm>
using namespace std;
int R;
int C;
int roomns[60][60];//�洢����ķ�����Ϣ
int roomn = 0;//roomn������
int roomnarea = 0;
int maxS = 0;
int tag[60][60];//����Ƿ���ʹ�
void dfs(int i,int j)
{
	if (tag[i][j])
		return;
	else
	{
		tag[i][j] = 1; roomnarea++;
		if ((roomns[i][j] & 1)==0)dfs(i, j - 1);//����û��ǽ
		if ((roomns[i][j] & 2)==0)dfs(i -1, j);
		if ((roomns[i][j] & 4)==0)dfs(i, j + 1);
		if ((roomns[i][j] & 8)==0)dfs(i + 1, j);
	}
}
int main()
{
	memset(tag, 0, sizeof(tag));
	cin >> R; cin >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> roomns[i][j];
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (!tag[i][j])
			{
				roomn++; roomnarea = 0;
				dfs(i, j);
				maxS = max(roomnarea, maxS);
			}
		}
	}
	cout << roomn << endl << maxS << endl;
	system("pause");
	return 0;
}