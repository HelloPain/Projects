#include <iostream>
#include <algorithm>
using namespace std;
char s[100] = { '\0' };//记得把第一个置为空，不然好麻烦
int stoi(int begin, int end)//将字符串里面从begin到end的字符转换为int
{
	int result = 0;
	for (; begin <= end; begin++)
	{
		result = result * 10 + s[begin] - '0';
	}
	return result;
}
int minsum(int add, int end)//the number of add and the position of end
{
	if (add > 0)
	{
		int min = 1 << 12;
		for (int i = end - 1; i >= end - add; i--)//加号放在第i个数字后面
		{
			int x = stoi(i + 1, end);
			int y = minsum(add - 1, i);
			min = (x + y) < min ? (x + y) : min;
		}

		return min;
	}
	return stoi(1, end);
}
int main()
{
	cin >>( s + 1);
	cout << minsum(2,strlen(s+1));
	system("pause");
	return 0;
}