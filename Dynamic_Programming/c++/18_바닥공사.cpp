// 이것이 취업을 위한 코딩테스트다
// 1

#include <iostream>
using namespace std;

int n;
int d[1001];

int main(void)
{
	cin >> n;

	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 1] + d[i - 2] * 2) % 796796;

	cout << d[n] << '\n';
	return 0;
}