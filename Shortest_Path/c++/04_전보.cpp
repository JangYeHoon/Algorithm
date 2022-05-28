// 이것이 취업을 위한 코딩테스트다 262p
// 2

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, C;
int d[30001];
vector<pair<int, int>> adj[30001];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, C });
	d[C] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist > d[now])
			continue;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int next_dist = dist + adj[now][i].second;
			if (next_dist < d[next]) {
				d[next] = next_dist;
				pq.push({ -next_dist, next });
			}
		}
	}
}

int main() {
	cin >> N >> M >> C;
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({ y, z });
	}

	fill(d, d + 30001, 1e9);
	dijkstra();

	int count = 0;
	int max_dist = 0;
	for (int i = 1; i <= N; i++) {
		if (d[i] != 1e9) {
			count += 1;
			max_dist = max(max_dist, d[i]);
		}
	}

	cout << count - 1 << ' ' << max_dist;
}