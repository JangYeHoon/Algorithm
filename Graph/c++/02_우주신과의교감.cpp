// fast campus 강의
// https://www.acmicpc.net/problem/1774
// 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int parent[1001];
vector<pair<int, int>> locations;
vector<pair<double, pair<int, int>>> edges;

double getDistance(pair<int, int> p1, pair<int, int> p2) {
	long long a = p1.first - p2.first;
	long long b = p1.second - p2.second;
	return sqrt((a * a) + (b * b));
}

int getParent(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool compareParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return true;
	else
		return false;
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
			edges.push_back({ getDistance(locations[i], locations[j]), {i + 1, j + 1} });
	}

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	sort(edges.begin(), edges.end());

	double result = 0;
	for (int i = 0; i < edges.size(); i++) {
		double cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (!compareParent(a, b)) {
			unionParent(a, b);
			result += cost;
		}
	}

	printf("%0.2f", result);
}