// fast campus 강의
// https://www.acmicpc.net/problem/9251
// 2

#include <iostream>
#include <algorithm>

using namespace std;

string x, y;
int dp[1001][1001];

int main() {
	cin >> x >> y;

	for (int i = 1; i <= x.size(); i++) {
		for (int j = 1; j <= y.size(); j++) {
			if (x[i - 1] == y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[x.size()][y.size()];
}