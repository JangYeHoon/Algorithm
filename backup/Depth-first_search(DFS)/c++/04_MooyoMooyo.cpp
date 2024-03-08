// fast campus 강의
// https://www.acmicpc.net/problem/16768
// 2

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int matrix[105][15];
bool visited[105][15], visited2[105][15];
int N, K;
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

int dfs(int x, int y, int cnt)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= 10)
			continue;
		if (!visited[nx][ny] && matrix[x][y] == matrix[nx][ny])
			cnt = dfs(nx, ny, cnt + 1);
	}
	return cnt;
}

void dfs(int x, int y)
{
	visited2[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= 10)
			continue;
		if (!visited2[nx][ny] && matrix[x][y] == matrix[nx][ny])
			dfs(nx, ny);
	}
	matrix[x][y] = 0;
}

void down()
{
	for (int y = 0; y < 10; y++) {
		vector<int> tmp_list;
		for (int x = 0; x < N; x++)
			if (matrix[x][y])
				tmp_list.push_back(matrix[x][y]);
		for (int x = 0; x < N - tmp_list.size(); x++)
			matrix[x][y] = 0;
		for (int x = 0; x < tmp_list.size(); x++)
			matrix[N - tmp_list.size() + x][y] = tmp_list[x];
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 10; j++)
			scanf("%1d", &matrix[i][j]);

	while (1) {
		bool chk = false;
		memset(visited, false, sizeof(visited));
		memset(visited2, false, sizeof(visited2));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 10; j++) {
				if (!visited[i][j] && matrix[i][j]) {
					int cnt = dfs(i, j, 1);
					if (cnt >= K) {
						chk = true;
						dfs(i, j);
					}
				}
			}
		}
		if (!chk)
			break;
		down();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cout << matrix[i][j];
		}
		cout << '\n';
	}
}