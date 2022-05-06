// fast campus 강의
// https://www.acmicpc.net/problem/1927
// 1

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> result;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty())
				result.push_back(0);
			else {
				result.push_back(pq.top());
				pq.pop();
			}
		}
		else pq.push(x);
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';
}