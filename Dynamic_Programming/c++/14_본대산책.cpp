// fast campus 강의
// https://www.acmicpc.net/problem/12849
// 2

#include <iostream>

using namespace std;

int D;
long long dp[8] = { 1 };
long long arr[8];

void solve() {
	arr[0] = dp[1] + dp[2];
	arr[1] = dp[0] + dp[2] + dp[3];
	arr[2] = dp[0] + dp[1] + dp[3] + dp[4];
	arr[3] = dp[1] + dp[2] + dp[4] + dp[5];
	arr[4] = dp[2] + dp[3] + dp[5] + dp[7];
	arr[5] = dp[3] + dp[4] + dp[6];
	arr[6] = dp[5] + dp[7];
	arr[7] = dp[4] + dp[6];

	for (int i = 0; i < 8; i++)
		dp[i] = arr[i] % 1000000007;
}

int main() {
	cin >> D;

	for (int i = 0; i < D; i++)
		solve();

	cout << dp[0];
}