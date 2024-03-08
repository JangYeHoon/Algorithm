// fast campus 강의
// https://www.acmicpc.net/problem/11053
// 2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> arr;
int dp[1001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
		dp[i] = 1;
	}

	int result = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		result = max(result, dp[i]);
	}
	
	cout << result;
}