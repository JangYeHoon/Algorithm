// 이것이 취업을 위한 코딩테스트다
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int d[1001];

int main() {
	cin >> N;

	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= N; i++)
		d[i] = (d[i - 1] + d[i - 2] * 2) % 796796;

	cout << d[N];
}