#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int n, m, answer;
int dist[10001];
bool select[10001];
vector<pair<int, int>> cost[10001];

void Prim()
{
	// 임의의 노드 선택하여 선택된 노드와 연결된 간선들 업데이트
	dist[1] = 0;
	select[1] = true;
	for (int i = 0; i < cost[1].size(); i++)
	{
		int next = cost[1][i].first;
		int distance = cost[1][i].second;
		dist[next] = distance;
	}

	for (int i = 1; i <= n - 1; i++)
	{
		int min_cost = INF;
		int min_idx = -1;
		// 전체 노드 중 간선의 길이가 가장 짧은 노드 선택
		for (int j = 1; j <= n; j++)
		{
			if (select[j] == true) continue;
			if (min_cost > dist[j])
			{
				min_cost = dist[j];
				min_idx = j;
			}
		}

		select[min_idx] = true;
		answer = answer + min_cost;

		// 선택된 노드와 연결된 간선들 업데이트
		for (int j = 0; j < cost[min_idx].size(); j++)
		{
			int next = cost[min_idx][j].first;
			int distance = cost[min_idx][j].second;
			if (select[next] == true) continue;
			if (dist[next] > distance) dist[next] = distance;
		}
	}
}