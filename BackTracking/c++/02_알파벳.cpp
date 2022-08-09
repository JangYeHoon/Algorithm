// fast campus 강의
// https://www.acmicpc.net/problem/1987
// 1

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

		if (0 <= nx && nx < R && 0 <= ny && ny < C) {
			if (!alphabet[((int)matrix[nx][ny]) - 65]) {
				alphabet[((int)matrix[nx][ny]) - 65]++;
				dfs(nx, ny, step + 1);
				alphabet[((int)matrix[nx][ny]) - 65]--;
			}
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> matrix[i][j];
	}

	alphabet[((int)matrix[0][0]) - 65]++;
	dfs(0, 0, 1);

	cout << result;
}