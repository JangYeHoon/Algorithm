// fast campus 강의
// https://www.acmicpc.net/problem/1715
// 2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	int result = 0;
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		result += a + b;
		pq.push(a + b);
	}
	cout << result;
}