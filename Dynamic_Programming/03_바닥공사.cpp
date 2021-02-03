// 바닥 공사(1*2, 2*1, 2*2의 타일로 2*n의 바닥을 채우는 경우의 수)
// 입력 : 가로 길이(N)
// 출력 : 바닥을 채우는 경우의 수를 796,796으로 나눈 나머지
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