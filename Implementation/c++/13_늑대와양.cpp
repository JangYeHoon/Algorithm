// fast campus 강의
// https://www.acmicpc.net/problem/16956
// 0

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
char matrix[501][501];
vector<pair<int, int>> wolf;
vector<pair<int, int>> space;
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

bool bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	bool visited[501][501] = { false, };
	visited[x][y] = true;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int px = p.first, py = p.second;
		for (int i = 0; i < 4; i++) {
			int nx = px + mx[i];
			int ny = py + my[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= R || matrix[nx][ny] == 'D')
				continue;
			if (matrix[nx][ny] == 'S')
				return true;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	return false;
}

bool wolf_chk()
{
	for (int i = 0; i < wolf.size(); i++) {
		if (bfs(wolf[i].first, wolf[i].second))
			return false;
	}
	return true;
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &matrix[i][j]);
			if (matrix[i][j] == '\n')
				scanf("%c", &matrix[i][j]);

			if (matrix[i][j] == '.')
				space.push_back({ i, j });
			else if (matrix[i][j] == 'W')
				wolf.push_back({ i, j });
		}
	}

	vector<bool> space_chk(space.size());
	bool result_chk = false;
	for (int i = 1; i < space.size(); i++) {
		fill(space_chk.end() - i, space_chk.end(), true);
		do {
			for (int j = 0; j < space.size(); j++) {
				if (space_chk[j]) {
					matrix[space[j].first][space[j].second] = 'D';
				}
			}
			if (wolf_chk()) {
				result_chk = true;
				break;
			}
			for (int j = 0; j < space.size(); j++) {
				if (space_chk[j])
					matrix[space[j].first][space[j].second] = '.';
			}
		} while (next_permutation(space_chk.begin(), space_chk.end()));
		if (result_chk)
			break;
	}
	if (result_chk) {
		cout << "1\n";
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				cout << matrix[i][j];
			cout << '\n';
		}
	}
	else cout << "0";
}