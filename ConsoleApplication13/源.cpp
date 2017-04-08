#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[3] = { 1,2,3 };
	cout << max_element(a, a + 3);
	system("pause");
	return 0;
}
