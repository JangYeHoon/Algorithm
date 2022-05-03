// fast campus 강의
// https://www.acmicpc.net/problem/1939
// 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, M, A, B, C, start_node, end_node;
bool visited[10001];

bool bfs(int w, vector<vector<pair<int, int>>> weight) {
	queue<int> q;
	q.push(start_node);
	visited[start_node] = true;

	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int i = 0; i < weight[a].size(); i++) {
			int b = weight[a][i].first;
			int c = weight[a][i].second;
			if (!visited[b] && c >= w) {
				visited[b] = true;
				q.push(b);
			}
		}
	}

	return visited[end_node];
}

int main() {
	cin >> N >> M;

	vector<vector<pair<int, int>>> weight(N + 1);
	int start = 987654321, end = 0;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		weight[A].push_back({ B, C });
		weight[B].push_back({ A, C });
		start = min(start, C);
		end = max(end, C);
	}

	cin >> start_node >> end_node;
	int result = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		memset(visited, false, sizeof(visited));
		if (bfs(mid, weight)) {
			start = mid + 1;
			result = mid;
		}
		else {
			end = mid - 1;
		}
	}

	cout << result;
}