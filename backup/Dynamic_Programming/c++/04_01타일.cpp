// fast campus 강의
// https://www.acmicpc.net/problem/1904
// 2

#include <iostream>

using namespace std;

int N;
long long d[1000001];

int main() {
	cin >> N;
	
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= N; i++)
		d[i] = (d[i - 1] + d[i - 2]) % 15746;

	cout << d[N];
}