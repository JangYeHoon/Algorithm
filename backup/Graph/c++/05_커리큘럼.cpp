// 이것이 취업을 위한 코딩테스트다
// 2

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int lec_time[501];
int indegree[501];
vector<int> graph[501];

void topology_sort() {
	int result[501];
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		result[i] = lec_time[i];
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			result[next] = max(result[next], result[now] + lec_time[next]);
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << result[i] << '\n';
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a;
		lec_time[i] = a;
		while (1) {
			cin >> b;
			if (b == -1) break;
			indegree[i]++;
			graph[b].push_back(i);
		}
	}

	topology_sort();
}