// 이것이 취업을 위한 코딩테스트다
// https://www.acmicpc.net/problem/16234
// 1

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, L, R;
int matrix[50][50];
int union_chk[50][50];
int mx[4] = { 1, 0, -1, 0 };
int my[4] = { 0, 1, 0, -1 };

void bfs(int x, int y, int index) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	vector<pair<int, int>> united;
	united.push_back({ x, y });
	union_chk[x][y] = index;
	int person_sum = matrix[x][y];
	int united_cnt = 1;

	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = px + mx[i];
			int ny = py + my[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;

			if (union_chk[nx][ny] == -1) {
				int diff_cnt = abs(matrix[px][py] - matrix[nx][ny]);
				if (L <= diff_cnt && diff_cnt <= R) {
					union_chk[nx][ny] = index;
					person_sum += matrix[nx][ny];
					united_cnt++;
					q.push({ nx, ny });
					united.push_back({ nx, ny });
				}
			}
		}
	}

	for (int i = 0; i < united.size(); i++) {
		int x = united[i].first;
		int y = united[i].second;
		matrix[x][y] = person_sum / united_cnt;
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];
	}

	int result = 0;
	while (true) {
		int index = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				union_chk[i][j] = -1;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (union_chk[i][j] == -1) {
					bfs(i, j, index);
					index++;
				}
			}
		}
		if (index == N * N)
			break;
		result++;
	}

	cout << result;
}