// 이것이 취업을 위한 코딩테스트다
// https://www.acmicpc.net/problem/1932
// 1

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[501][501];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int left;
			int right;
			if (j == 0)
				left = 0;
			else
				left = dp[i - 1][j - 1];
			if (i == j)
				right = 0;
			else
				right = dp[i - 1][j];
			dp[i][j] = dp[i][j] + max(left, right);
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
		result = max(result, dp[n - 1][i]);
	cout << result;
}