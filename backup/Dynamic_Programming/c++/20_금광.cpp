// 이것이 취업을 위한 코딩테스트다
// 1

#include <iostream>
#include <algorithm>

using namespace std;

int T, n, m;
int dp[21][21];

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> dp[i][j];
		}

		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				int left_up;
				int left_down;
				if (i == 0)
					left_up = 0;
				else
					left_up = dp[i - 1][j - 1];
				if (i == n - 1)
					left_down = 0;
				else
					left_down = dp[i + 1][j - 1];
				int left = dp[i][j - 1];
				dp[i][j] = dp[i][j] + max({ left_up, left_down, left });
			}
		}

		int result = 0;
		for (int i = 0; i < n; i++)
			result = max(result, dp[i][m - 1]);
		cout << result << '\n';
	}
}