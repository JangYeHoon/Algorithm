// fast campus 강의
// https://www.acmicpc.net/problem/1987
// 0

#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int R, C, result;
char matrix[21][21];
int mx[4] = { 1, 0, -1, 0 };
int my[4] = { 0, 1, 0, -1 };

void process() {
	set<pair<char, pair<int, int>>> s;
	queue<pair<int, pair<int, int>>> q;
	q.push({ 1, { 0, 0 } });
	s.insert({ matrix[0][0], {0, 0} });

	while(!q.empty()) {
		int px = q.front().second.first;
		int py = q.front().second.second;
		int step = q.front().first;
		q.pop();
		result = max(result, step);

		for (int i = 0; i < 4; i++) {
			int nx = px + mx[i];
			int ny = py + my[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;

			pair<set<pair<char, pair<int, int>>>::iterator, bool> check = s.insert({ matrix[nx][ny], {nx, ny} });
			if (check.second) {
				q.push({ step + 1, {nx, ny} });
			}
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c = cin.get();
			if (c == '\n')
				c = cin.get();
			matrix[i][j] = c;
		}
	}

	process();

	cout << result;
}