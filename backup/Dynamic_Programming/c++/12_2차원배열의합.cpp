// fast campus 강의
// https://www.acmicpc.net/problem/2167
// 2

#include <iostream>

using namespace std;

int N, M, K;
int dp[301][301];

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int x;
			cin >> x;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + x - dp[i - 1][j - 1];
		}
	}

	cin >> K;
	for (int k= 0; k < K; k++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << dp[x][y] + dp[i - 1][j - 1] - dp[i - 1][y] - dp[x][j - 1] << '\n';
	}
}