// 이것이 취업을 위한 코딩테스트다
// https://www.acmicpc.net/problem/1715
// 1

#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		pq.push(x);
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