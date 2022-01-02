// fast campus 강의
// https://www.acmicpc.net/problem/2606
// 2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> virus[101];
bool visited[101] = { false, };
int N, M, result;

void bfs()
{
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (!visited[x]) {
			visited[x] = true;
			result++;

			for (auto next : virus[x])
				if (!visited[next])
					q.push(next);
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int p, q;
		scanf("%d %d", &p, &q);

		virus[p].push_back(q);
		virus[q].push_back(p);
	}

	bfs();
	cout << result - 1;
}