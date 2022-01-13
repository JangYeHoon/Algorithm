// fast campus 강의
// https://www.acmicpc.net/problem/16768
// 1

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int SIZE = 10;
int matrix[105][12];
bool visited[105][12], visited2[105][12];
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };
int N, K;

int dfs(int x, int y, int count)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx <= 0 || nx > N || ny <= 0 || ny > SIZE)
			continue;
		if (!visited[nx][ny] && matrix[nx][ny] == matrix[x][y])
			count = dfs(nx, ny, count + 1);
	}
	return count;
}

void dfs(int x, int y)
{
	visited2[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx <= 0 || nx > N || ny <= 0 || ny > SIZE)
			continue;
		if (!visited2[nx][ny] && matrix[nx][ny] == matrix[x][y])
			dfs(nx, ny);
	}
	matrix[x][y] = 0;
}

void down() {
	for (int y = 1; y <= SIZE; y++) {
		vector<int> tmp;
		for (int x = 1; x <= N; x++)
			if (matrix[x][y])
				tmp.push_back(matrix[x][y]);
		for (int x = 1; x <= N - tmp.size(); x++)
			matrix[x][y] = 0;
		for (int x = 0; x < tmp.size(); x++)
			matrix[N - tmp.size() + x + 1][y] = tmp[x];
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= SIZE; j++)
			scanf("%1d", &matrix[i][j]);

	while (1) {
		bool chk = true;
		memset(visited, false, sizeof(visited));
		memset(visited2, false, sizeof(visited2));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= SIZE; j++) {
				if (matrix[i][j] != 0 && !visited[i][j]) {
					int cnt = dfs(i, j, 1);
					if (cnt >= K) {
						dfs(i, j);
						chk = false;
					}
				}
			}
		}
		if (chk)
			break;
		down();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= SIZE; j++)
			printf("%d", matrix[i][j]);
		printf("\n");
	}
}