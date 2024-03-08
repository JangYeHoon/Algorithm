// 이것이 취업을 위한 코딩테스트다
// https://www.acmicpc.net/problem/14501
// 1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> term;
vector<int> price;
int dp[1001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		price.push_back(p);
		term.push_back(t);
	}

	int result = 0;
	for (int i = n - 1; i >= 0; i--) {
		int t = term[i] + i;
		if (t <= n) {
			dp[i] = max(dp[t] + price[i], result);
			result = dp[i];
		}
		else {
			dp[i] = result;
		}
	}
	cout << result;
}