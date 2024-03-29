// fast campus 강의
// https://www.acmicpc.net/problem/1915
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, result;
int dp[1001][1001];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			scanf("%1d", &x);
			if (x) {
				dp[i][j] = min({ dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1] }) + 1;
				result = max(result, dp[i][j]);
			}
		}
	}

	cout << result * result;
}