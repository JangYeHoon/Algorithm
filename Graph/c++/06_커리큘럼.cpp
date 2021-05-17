// 커리큘럼
// 입력 : 강의의 수(N)
//		  강의 시간, 선수 강의 번호, 각 줄은 -1로 끝남
// 출력 : N개의 강의를 수강하기까지 걸리는 최소 시간
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int v, e;
int indegree[501];
int time[501];
vector<int> graph[501];

void topologySort()
{
	vector<int> result(501);
	for (int i = 1; i <= v; i++)
		result[i] = time[i];
	queue<int> q;

	for (int i = 1; i <= v; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++)
		{
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + time[graph[now][i]]);
			indegree[graph[now][i]] -= 1;
			if (indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);
		}
	}

	for (int i = 1; i <= v; i++)
		cout << result[i] << ' ';
}

int main()
{
	cin >> v;

	for (int i = 1; i <= v; i++)
	{
		int a, b;
		cin >> a;
		time[i] = a;
		while (1)
		{
			cin >> b;
			if (b == -1)
				break;
			graph[b].push_back(i);
			indegree[i] += 1;
		}
	}

	topologySort();
}