// 이것이 취업을 위한 코딩테스트다 217p
// https://www.acmicpc.net/problem/1463
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int d[1000001];

int main() {
	cin >> N;

	for (int i = 2; i <= N; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)
			d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1);
	}

	cout << d[N];
}