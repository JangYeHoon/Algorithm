// fast campus 강의
// https://www.acmicpc.net/problem/1927
// 2

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> N;
	vector<int> result;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (pq.empty())
				result.push_back(0);
			else {
				result.push_back(pq.top());
				pq.pop();
			}
		}
		else pq.push(tmp);
	}

	for (auto x : result)
		cout << x << '\n';
}