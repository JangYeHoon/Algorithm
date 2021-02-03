// 특정 거리의 도시 찾기
// 입력 : N(도시의 개수), M(도로의 개수), K(거리 정보), X(출발도시의 번호)
//		 M개의 줄에 걸쳐 A -> B로 가는 입력
// 출력 : 최단거리가 K인 도시 출력, 없으면 -1
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k, x;
vector<int> matrix[300001];
vector<int> d(300001, -1);

void bfs(int start)
{
	d[start] = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < matrix[now].size(); i++)
		{
			int next = matrix[now][i];
			if (d[next] == -1)
			{
				d[next] = d[now] + 1;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		matrix[a].push_back(b);
	}

	bfs(x);

	bool check = false;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == k)
		{
			cout << i << '\n';
			check = true;
		}
	}
	if (check == false)
		cout << -1 << '\n';
	return true;
}