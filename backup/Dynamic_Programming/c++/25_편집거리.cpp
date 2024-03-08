// 이것이 취업을 위한 코딩테스트다
// https://www.acmicpc.net/problem/15483
// 1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string s1;
string s2;

int edit_dist(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++)
		dp[i][0] = i;
	for (int j = 1; j <= m; j++)
		dp[0][j] = j;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
		}
	}

	return dp[n][m];
}

int main() {
	cin >> s1 >> s2;

	cout << edit_dist(s1, s2) << '\n';
}