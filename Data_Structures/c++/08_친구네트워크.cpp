// fast campus 강의
// https://www.acmicpc.net/problem/4195
// 1

#include <iostream>
#include <map>

using namespace std;

int test_case;
int parent[200001];
int number[200001];
char f1[21], f2[21];

int findParent(int x)
{
	if (parent[x] == x)
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
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		map<string, int> data;
		int f;
		int cnt = 1;    // map의 중복 제거를 위한 값

		cin >> f;
		for (int i = 1; i <= 2 * f; i++) {
			parent[i] = i;
			number[i] = 1;
		}

		for (int i = 0; i < f; i++) {
			scanf("%s %s", &f1, &f2);

			if (data.count(f1) == 0)
				data[f1] = cnt++;
			if (data.count(f2) == 0)
				data[f2] = cnt++;

			unionParent(data[f1], data[f2]);		// 두 친구가 같은 부모를 가진 연결된 친구인지 확인
			cout << number[findParent(data[f1])] << '\n';
		}
	}
}