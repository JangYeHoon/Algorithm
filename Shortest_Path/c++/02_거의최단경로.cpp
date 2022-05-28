// fast campus 강의
// https://www.acmicpc.net/problem/5719
// 2

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, S, D;
bool drop_node[501][501];
int d[501];
vector<pair<int, int>> adj[501];
vector<pair<int, int>> reverse_adj[501];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S });
	d[S] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist > d[now])
			continue;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int next_dist = dist + adj[now][i].second;
			if (next_dist < d[next] && !drop_node[now][next]) {
				d[next] = next_dist;
				pq.push({ -next_dist, next });
			}
		}
	}
}

void bfs() {
	queue<int> q;
	q.push(D);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == S)
			continue;
		for (int i = 0; i < reverse_adj[now].size(); i++) {
			int prev = reverse_adj[now][i].first;
			int prev_dist = reverse_adj[now][i].second;
			if (d[now] == prev_dist + d[prev] && !drop_node[prev][now]) {
				drop_node[prev][now] = true;
				q.push(prev);
			}
		}
	}
}

int main() {
	while (1) {
		cin >> N >> M;
		if (N == 0)
			break;
		cin >> S >> D;
		for (int i = 0; i <= N; i++) {
			adj[i].clear();
			reverse_adj[i].clear();
		}
		for (int i = 0; i < M; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			adj[u].push_back({ v, p });
			reverse_adj[v].push_back({ u, p });
		}

		memset(drop_node, false, sizeof(drop_node));
		fill(d, d + 501, 1e9);
		dijkstra();

		bfs();

		fill(d, d + 501, 1e9);
		dijkstra();

		if (d[D] == 1e9)
			cout << -1 << '\n';
		else
			cout << d[D] << '\n';
	}
}