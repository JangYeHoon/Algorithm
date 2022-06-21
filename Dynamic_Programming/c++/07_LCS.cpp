// fast campus 강의
// https://www.acmicpc.net/problem/9251
// 1

#include <iostream>
#include <algorithm>

using namespace std;

string s1, s2;
int dp[1001][1001];

int main() {
    cin >> s1 >> s2;

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[s1.length()][s2.length()];
}