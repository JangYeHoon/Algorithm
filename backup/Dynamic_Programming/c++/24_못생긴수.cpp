// 이것이 취업을 위한 코딩테스트다
// 1

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1001];

int main() {
	cin >> n;

	dp[0] = 1;
	int idx2 = 0, idx3 = 0, idx5 = 0;
	int num2 = 2, num3 = 3, num5 = 5;
	for (int i = 1; i < n; i++) {
		dp[i] = min({ num2, num3, num5 });
		if (dp[i] == num2)
			num2 = dp[++idx2] * 2;
		if (dp[i] == num3)
			num3 = dp[++idx3] * 3;
		if (dp[i] == num5)
			num5 = dp[++idx5] * 5;
	}
	cout << dp[n - 1];
}