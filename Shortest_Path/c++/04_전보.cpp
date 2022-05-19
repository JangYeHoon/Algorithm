// 전보
// 입력 : 도시의 개수(N), 통로의 개수(M), 메시지를 보내고자하는 도시(C)
//		 M개의 X,Y,Z(특정 도시 X에서 특정 도시 Y로 이어지는 통로이며 전달 시간 Z)
// 출력 : 메시지를 받는 도시의 개수와 걸리는 시간
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

int n, m, c;
vector<pair<int, int>> graph[30001];
int d[30001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;
		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first])
			{
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main()
{
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({ y, z });
	}

	fill(d, d + 30001, INF);

	dijkstra(c);

	int count = 0, time = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] != INF)
		{
			count++;
			time = max(time, d[i]);
		}
	}

	cout << count-1 << ' ' << time << '\n';
	return 0;
}