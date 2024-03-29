// fast campus 강의
// https://www.acmicpc.net/problem/1495
// 2

#include <iostream>
#include <vector>

using namespace std;

int N, S, M;
vector<int> arr;
int dp[51][1001];

int main() {
	cin >> N >> S >> M;
	dp[0][S] = 1;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j] == 0)
				continue;
			if (j - arr[i - 1] >= 0)
				dp[i][j - arr[i - 1]] = 1;
			if (j + arr[i - 1] <= M)
				dp[i][j + arr[i - 1]] = 1;
		}
	}

	int result = -1;
	for (int i = M; i > -1; i--) {
		if (dp[N][i] == 1) {
			result = i;
			break;
		}
	}
	cout << result;
}