// fast campus 강의
// https://www.acmicpc.net/problem/1966
// 2

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		int N, M;
		cin >> N >> M;
		queue<pair<int, int>> q;  // idx, priority
		priority_queue<int> pq;
		for (int i = 0; i < N; i++) {
			int priority;
			cin >> priority;
			q.push({ i, priority });
			pq.push(priority);
		}

		int result = 1;
		while (1) {
			int idx = q.front().first;
			int priority = q.front().second;
			q.pop();

			if (pq.top() == priority) {
				pq.pop();
				if (idx == M)
					break;
				result += 1;
			}
			else {
				q.push({ idx, priority });
			}
		}

		cout << result << '\n';
	}
}