// 이것이 취업을 위한 코딩테스트다
// https://www.acmicpc.net/problem/18353
// 1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr;
int dp[2001];

int main() {
	cin >> n;
	fill(dp, dp + n, 1);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	reverse(arr.begin(), arr.end());

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << n - *max_element(dp, dp + n);
}