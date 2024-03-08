#include <iostream>
#include <queue>

using namespace std;

#define INF 987654321

int n, m, answer;
int dist[10001];
bool visit[10001];
vector<pair<int, int>> cost[10001];

void Prim_Using_Heap()
{
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < cost[1].size(); i++)
	{
		int next = cost[1][i].first;
		int distance = cost[1][i].second;

		pq.push(make_pair(-distance, next));
	}

	visit[1] = true;
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visit[cur] == false)
		{
			visit[cur] = true;
			answer = answer + distance;
			for (int i = 0; i < cost[cur].size(); i++)
			{
				int cur_distance = cost[cur][i].second;
				int next = cost[cur][i].first;
				if (visit[next] == false)
					pq.push(make_pair(-cur_distance, next));
			}
		}
	}
}