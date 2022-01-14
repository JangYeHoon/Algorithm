// 이것이 취업을 위한 코딩테스트다 339p
// https://www.acmicpc.net/problem/18352
// 2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> matrix[300001];
vector<int> dist(300001, -1);
int N, M, K, X;

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	dist[x] = 0;

	while (!q.empty()) {
		int px = q.front();
		q.pop();

		for (int i = 0; i < matrix[px].size(); i++) {
			int nx = matrix[px][i];
			if (dist[nx] == -1) {
				q.push(nx);
				dist[nx] = dist[px] + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		matrix[x].push_back(y);
	}

	bfs(X);

	bool chk = false;
	for (int i = 0; i < N + 1; i++) {
		if (dist[i] == K) {
			printf("%d\n", i);
			chk = true;
		}
	}
	if (!chk)
		printf("-1\n");
}