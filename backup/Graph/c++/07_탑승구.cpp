// 이것이 취업을 위한 코딩테스트다
// 1

#include <iostream>

using namespace std;

int G, P;
int parent[100001];

int find_parent(int x) {
	if (x == parent[x])
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
	cin >> G;

	for (int i = 0; i <= G; i++)
		parent[i] = i;

	cin >> P;
	int result = 0;
	for (int i = 0; i < P; i++) {
		int x;
		cin >> x;
		int root_node = find_parent(x);
		if (root_node == 0)
			break;
		union_parent(root_node, root_node - 1);
		result++;
	}
	cout << result << '\n';
}