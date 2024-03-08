// 이것이 취업을 위한 코딩테스트다
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int parent[200001];
vector<pair<int, pair<int, int>>> graph;

int find_parent(int x) {
	if (parent[x] == x)
		return x;
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
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		graph.push_back({ cost, {a, b} });
	}

	sort(graph.begin(), graph.end());

	int active_node = 0;
	int all_node = 0;
	for (int i = 0; i < graph.size(); i++) {
		int cost = graph[i].first;
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		all_node += cost;
		if (find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			active_node += cost;
		}
	}

	cout << all_node - active_node;
}