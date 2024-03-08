// 이것이 취업을 위한 코딩테스트다
// 1

#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[501];

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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1)
				union_parent(i + 1, j + 1);
		}
	}

	vector<int> plan;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		plan.push_back(x);
	}

	bool result = true;
	for (int i = 0; i < m - 1; i++) {
		if (find_parent(plan[i]) != find_parent(plan[i + 1]))
			result = false;
	}

	if (result)
		cout << "YES\n";
	else
		cout << "NO\n";
}