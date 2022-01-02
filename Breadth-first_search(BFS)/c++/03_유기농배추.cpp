// fast campus 강의
// https://www.acmicpc.net/problem/1012
// 2

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int matrix[51][51];
bool visited[51][51];
int M, N, K;
int mx[4] = { 1, 0, -1, 0 };
int my[4] = { 0, 1, 0, -1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();

		if (!visited[pos.first][pos.second]) {
			visited[pos.first][pos.second] = true;

			for (int i = 0; i < 4; i++) {
				int nx = pos.first + mx[i];
				int ny = pos.second + my[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;

				if (matrix[nx][ny] == 1 && !visited[nx][ny])
					q.push({ nx, ny });
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;
		memset(matrix, 0, sizeof(matrix));
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			matrix[y][x] = 1;
		}

		int result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (matrix[i][j] == 1 && !visited[i][j]) {
					bfs(i, j);
					result++;
				}
			}
		}

		cout << result << '\n';
	}
}