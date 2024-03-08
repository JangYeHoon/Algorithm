// 이것이 취업을 위한 코딩테스트다
// https://www.acmicpc.net/problem/2887
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int parent[100001];

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
	cin >> n;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	vector<pair<int, int>> x;
	vector<pair<int, int>> y;
	vector<pair<int, int>> z;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a, i });
		y.push_back({ b, i });
		z.push_back({ c, i });
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	vector<pair<int, pair<int, int> > > edges;
	for (int i = 0; i < n - 1; i++) {
		edges.push_back({ x[i + 1].first - x[i].first, {x[i].second, x[i + 1].second} });
		edges.push_back({ y[i + 1].first - y[i].first, {y[i].second, y[i + 1].second} });
		edges.push_back({ z[i + 1].first - z[i].first, {z[i].second, z[i + 1].second} });
	}
	sort(edges.begin(), edges.end());

	int result = 0;
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			result += cost;
		}
	}
	cout << result << '\n';
}