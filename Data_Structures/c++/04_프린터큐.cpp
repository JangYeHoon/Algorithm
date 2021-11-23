// fast campus 강의
// https://www.acmicpc.net/problem/1966
// 1

#include <iostream>
#include <queue>

using namespace std;

int N, M;

int main()
{
	int test_case = 0;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		cin >> N >> M;
		int result = 0;

		for (int j = 0; j < N; j++) {
			int priority;
			cin >> priority;
			q.push({ priority, j });
			pq.push(priority);
		}

		while (true) {
			int priority = q.front().first;
			int idx = q.front().second;
			q.pop();

			if (priority == pq.top()) {
				result++;
				pq.pop();
				if (idx == M) {
					cout << result << '\n';
					break;
				}
			}
			else {
				q.push({ priority, idx });
			}
		}
	}
}