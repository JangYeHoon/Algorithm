// 이것이 취업을 위한 코딩테스트다 300p
// https://www.acmicpc.net/problem/1647
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int parent[100001];
vector<pair<int, pair<int, int>>> edges;

int find_parent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N + 1; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edges.push_back({ cost, {a, b} });
	}
	sort(edges.begin(), edges.end());

	int result = 0, max_dist = 0;
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			result += cost;
			max_dist = max(max_dist, cost);
		}
	}
	cout << result - max_dist;
}