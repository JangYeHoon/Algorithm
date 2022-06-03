// fast campus 강의
// https://www.acmicpc.net/problem/1774
// 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int parent[1001];
vector<pair<int, int>> locations;
vector<pair<double, pair<int, int>>> edges;

double get_distance(pair<int, int> p1, pair<int, int> p2) {
	long long x = p1.first - p2.first;
	long long y = p1.second - p2.second;
	return sqrt((x * x) + (y * y));
}

int find_parent(int a) {
	if (parent[a] == a)
		return a;
	else
		return parent[a] = find_parent(parent[a]);
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
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		locations.push_back({ x, y });
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++)
			edges.push_back({ get_distance(locations[i], locations[j]), {i + 1, j + 1} });
	}
	sort(edges.begin(), edges.end());

	for (int i = 1; i < N + 1; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		union_parent(a, b);
	}

	double result = 0;
	for (int i = 0; i < edges.size(); i++) {
		double cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			result += cost;
		}
	}

	printf("%0.2f", result);
}