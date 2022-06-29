// fast campus 강의
// https://www.acmicpc.net/problem/2655
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct block_info {
	int index;
	int area;
	int height;
	int weight;
};

int N, max_height;
int d[101];
vector<int> result;

bool compare(block_info &a, block_info &b) {
	return a.weight < b.weight;
}

int main() {
	cin >> N;
	
	vector<block_info> arr(N + 1);
	arr[0] = { 0 };
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].area >> arr[i].height>> arr[i].weight;
		arr[i].index = i;
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j].area < arr[i].area)
				d[i] = max(d[i], d[j] + arr[i].height);
		}
		max_height = max(max_height, d[i]);
	}

	int idx = N;
	while (idx) {
		if (max_height == d[idx]) {
			result.push_back(arr[idx].index);
			max_height -= arr[idx].height;
		}
		idx--;
	}

	cout << result.size() << '\n';

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << '\n';
	}
}