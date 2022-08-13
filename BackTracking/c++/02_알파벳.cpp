// fast campus 강의
// https://www.acmicpc.net/problem/1987
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int R, C, result;
char matrix[21][21];
int alphabet[26];
int mx[4] = { 1, 0, -1, 0 };
int my[4] = { 0, 1, 0, -1 };

void dfs(int x, int y, int step) {
	result = max(result, step);

	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			continue;

		if (!alphabet[matrix[nx][ny] - 65]) {
			alphabet[matrix[nx][ny] - 65] = 1;
			dfs(nx, ny, step + 1);
			alphabet[matrix[nx][ny] - 65] = 0;
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> matrix[i][j];
	}

	alphabet[matrix[0][0] - 65] = 1;
	dfs(0, 0, 1);
	cout << result;
}