// 이것이 취업을 위한 코딩테스트다
// 1

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 1e9

using namespace std;

int test_case, n;
int graph[125][125], d[125][125];
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };

int main() {
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> graph[i][j];
		}

		for (int i = 0; i < n; i++)
			fill(graph[i], graph[i] + 125, INF);

		int px = 0, py = 0;
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ -graph[px][py], {0, 0} });
		d[px][py] = graph[px][py];

		while (!pq.empty()) {
			int dist = -pq.top().first;
			int px = pq.top().second.first;
			int py = pq.top().second.second;
			pq.pop();

			if (d[px][py] < dist)
				continue;

			for (int i = 0; i < 4; i++) {
				int nx = px + mx[i];
				int ny = py + my[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;

				int cost = dist + graph[nx][ny];
				if (cost < d[nx][ny]) {
					d[nx][ny] = cost;
					pq.push({ -cost, {nx, ny} });
				}
			}
		}

		cout << d[n - 1][n - 1] << '\n';
	}
}