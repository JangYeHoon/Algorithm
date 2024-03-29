// fast capus 강의
// https://www.acmicpc.net/problem/1932
// 2

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[501][501];

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			int x;
			cin >> x;
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + x;
		}
	}

	cout << *max_element(dp[N] + 1, dp[N] + N + 1);
}