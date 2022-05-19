// fast campus 강의
// https://www.acmicpc.net/problem/10282
// 1

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, start;
vector<pair<int, int>> adj[10001];
int d[10001];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist)
			continue;

		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int nextDist = dist + adj[now][i].second;
			if (d[next] > nextDist) {
				d[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> m >> start;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		fill(d, d + 10001, 1e9);
		for (int i = 0; i < m; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			adj[b].push_back({ a, s });
		}
		dijkstra();
		int cnt = 0;
		int maxDist = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] != 1e9) {
				cnt++;
				maxDist = max(maxDist, d[i]);
			}
		}
		cout << cnt << ' ' << maxDist << '\n';
	}
}