// fast campus 강의
// https://www.acmicpc.net/problem/2747
// 2

#include <iostream>

using namespace std;

int n;
int d[46];

// 반복 풀이
int main() {
	cin >> N;
	d[0] = 0;
	d[1] = 1;

	for (int i = 2; i <= N; i++)
		d[i] = d[i - 1] + d[i - 2];

	cout << d[N];
}

// 재귀
int fibo(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}