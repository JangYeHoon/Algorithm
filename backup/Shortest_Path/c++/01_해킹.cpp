// fast campus 강의
// https://www.acmicpc.net/problem/10282
// 2

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, M, C;
int d[100001];

void dijkstra(vector<vector<pair<int, int>>> adj, int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (d[x] < cost)
			continue;
		for (int i = 0; i < adj[x].size(); i++) {
			int next = adj[x][i].first;
			int dist = cost + adj[x][i].second;
			if (dist < d[next]) {
				d[next] = dist;
				pq.push({ -dist, next });
			}
		}
	}
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M >> C;
		vector<vector<pair<int, int>>> arr(N + 1);
		fill(d, d + 100001, 1e9);
		for (int i = 0; i < M; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			arr[b].push_back({ a, s });
		}
		dijkstra(arr, C);

		int cost = 0, max_dist = 0;
		for (int i = 1; i <= N; i++) {
			if (d[i] != 1e9) {
				cost++;
				max_dist = max(max_dist, d[i]);
			}
		}
		cout << cost << ' ' << max_dist << '\n';
	}
}