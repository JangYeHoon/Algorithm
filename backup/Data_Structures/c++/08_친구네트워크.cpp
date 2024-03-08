// fast campus 강의
// https://www.acmicpc.net/problem/4195
// 2

#include <iostream>
#include <map>

using namespace std;

int parent[200001];
int number[200001];

int findParent(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y)
{
	x = findParent(x);
	y = findParent(y);

	if (x != y) {
		parent[y] = x;
		number[x] += number[y];
	}
}

int main()
{
	int tc, F;
	char f1[21], f2[21];
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		cin >> F;
		map<string, int> m;
		int count = 1;

		for (int i = 1; i <= 2 * F; i++) {
			parent[i] = i;
			number[i] = 1;
		}

		for (int i = 0; i < F; i++) {
			scanf("%s %s", &f1, &f2);

			if (!m.count(f1))
				m[f1] = count++;
			if (!m.count(f2))
				m[f2] = count++;

			unionParent(m[f1], m[f2]);
			cout << number[findParent(m[f1])] << '\n';
		}
	}
}