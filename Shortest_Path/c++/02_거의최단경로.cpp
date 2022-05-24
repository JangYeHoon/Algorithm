#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M, S, D;
int d[502];
bool drop_node[502][502];
vector<pair<int, int>> adj[502];
vector<pair<int, int>> reverse_adj[502];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S });
	d[S] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (d[now] < dist)
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
		for (int i = 0; i < reverse_adj[now].size(); i++) {
			int prev = reverse_adj[now][i].first;
			int dist = reverse_adj[now][i].second;
			if (d[now] == d[prev] + dist && !drop_node[prev][now]) {
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
		for (int i = 0; i < N + 1; i++) {
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
		fill(d, d + 502, 1e9);
		dijkstra();

		bfs();

		fill(d, d + 502, 1e9);
		dijkstra();

		if (d[D] != 1e9)
			cout << d[D] << '\n';
		else
			cout << -1 << '\n';
	}
}