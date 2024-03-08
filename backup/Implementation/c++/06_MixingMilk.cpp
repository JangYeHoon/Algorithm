// fast campus 강의
// https://www.acmicpc.net/problem/16769
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int c[3] = { 0, };
	int m[3] = { 0, };
	for (int i = 0; i < 3; i++)
		cin >> c[i] >> m[i];

	for (int i = 1; i <= 100; i++) {
		int p = (i - 1) % 3, q = i % 3;
		int tmp = m[q];
		m[q] = min(c[q], m[p] + m[q]);
		m[p] = max(m[p] + tmp - c[q], 0);
	}

	for (int i = 0; i < 3; i++)
		cout << m[i] << '\n';
}