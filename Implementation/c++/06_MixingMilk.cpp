// fast campus 강의
// https://www.acmicpc.net/problem/16769
// 1

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long bucket[4] = { 0, };
	long milk[4] = { 0, };

	for (int i = 0; i < 3; i++) {
		int c, m;
		cin >> c >> m;
		bucket[i] = c;
		milk[i] = m;
	}

	for (int i = 0; i < 100; i++) {
		int p = i % 3;
		int q = (i + 1) % 3;

		long tmp = milk[p] + milk[q];
		milk[q] = min(bucket[q], tmp);
		milk[p] = tmp - milk[q];
	}

	for (int i = 0; i < 3; i++)
		cout << milk[i] << '\n';
}