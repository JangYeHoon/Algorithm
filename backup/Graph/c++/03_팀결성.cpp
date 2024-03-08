// 이것이 취업을 위한 코딩테스트다 298p
// 2

#include <iostream>

using namespace std;

int N, M;
int parent[100001];

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
		int oper, a, b;
		cin >> oper >> a >> b;
		if (oper == 0)
			union_parent(a, b);
		else {
			if (find_parent(a) == find_parent(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}