// fast campus 강의
// https://www.acmicpc.net/problem/12865
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int dp[101][100001];

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		int weight, value;
		cin >> weight >> value;
		for (int j = 0; j <= K; j++) {
			if (j < weight)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
		}
	}

	cout << dp[N][K];
}