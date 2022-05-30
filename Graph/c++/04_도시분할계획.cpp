// 도시 분할 계획
// 입력 : 집의 개수(N), 길의 개수(M)
//		  집(A)와 집(B)의 유지비(C)
// 출력 : 남은 유지비 합의 최솟값
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
int parent[100001];
vector<pair<int, pair<int, int>>> edges;
int result = 0;

int findParent(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	cin >> v >> e;
	
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c, { a, b } });
	}

	sort(edges.begin(), edges.end());

	int max = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (findParent(a) != findParent(b))
		{
			unionParent(a, b);
			result += cost;
			if (max < cost)
				max = cost;
		}
	}
	result -= max;
	cout << result << '\n';
}