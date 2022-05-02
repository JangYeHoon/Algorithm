// fast campus 강의
// https://www.acmicpc.net/problem/2110
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> house;

int main() {
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		house.push_back(tmp);
	}
	sort(house.begin(), house.end());

	int start = 0;
	int end = house[N - 1];
	while(start <= end) {
		int cnt = 1;
		int pre_idx = 0;
		int mid = (start + end) / 2;
		for (int i = 1; i < N; i++) {
			if (house[i] - house[pre_idx] >= mid) {
				pre_idx = i;
				cnt += 1;
			}
		}
		if (cnt >= C)
			start = mid + 1;
		else
			end = mid - 1;
	}

	cout << end;
}