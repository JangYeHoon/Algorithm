// fast campus 강의
// https://www.acmicpc.net/problem/2655
// 2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int dp[102];

struct block {
	int idx;
	int area;
	int height;
	int weight;
};

bool compare(block a, block b) {
	return a.weight < b.weight;
}

int main() {
	cin >> N;
	
	vector<block> arr(N + 1);
	arr[0] = { 0 };

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].area >> arr[i].height >> arr[i].weight;
		arr[i].idx = i;
	}

	sort(arr.begin(), arr.end(), compare);

	int max_height = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i].area > arr[j].area)
				dp[i] = max(dp[i], dp[j] + arr[i].height);
		}
		max_height = max(max_height, dp[i]);
	}

	vector<int> result;
	int idx = N;
	while (idx != 0) {
		if (max_height == dp[idx]) {
			result.push_back(arr[idx].idx);
			max_height -= arr[idx].height;
		}
		idx--;
	}
	cout << result.size() << '\n';
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << '\n';
}