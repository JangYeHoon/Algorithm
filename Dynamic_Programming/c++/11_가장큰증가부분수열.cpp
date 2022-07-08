// fast campus 강의
// https://www.acmicpc.net/problem/11055
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001];
int arr[1001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}

	cout << *max_element(dp, dp + N);

}