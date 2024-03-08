// 이것이 취업을 위한 코딩테스트다 327p
// https://www.acmicpc.net/problem/3190
// 2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, L;
int matrix[101][101];
vector<pair<int, char>> direction_vector;

int turn(int direction, char c)
{
	if (c == 'L') direction = (direction == 0) ? 3 : direction - 1;
	else direction = (direction + 1) % 4;
	return direction;
}

int solution()
{
	int second = 0, x = 1, y = 1, direction = 0, direction_idx = 0;
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	matrix[x][y] = 2;
	int mx[4] = { 0, 1, 0, -1 };
	int my[4] = { 1, 0, -1, 0 };

	while (1) {
		int nx = x + mx[direction];
		int ny = y + my[direction];
		if (nx > 0 && nx <= N && ny > 0 && ny <= N && matrix[nx][ny] != 2) {
			if (matrix[nx][ny] == 0) {
				pair<int, int> p = q.front();
				q.pop();
				matrix[p.first][p.second] = 0;
			}
			q.push({ nx, ny });
			matrix[nx][ny] = 2;
			x = nx;
			y = ny;
		}
		else {
			second++;
			break;
		}
		second++;
		if (direction_idx < L && direction_vector[direction_idx].first == second) {
			direction = turn(direction, direction_vector[direction_idx].second);
			direction_idx++;
		}
	}

	return second;
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		matrix[x][y] = 1;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int x;
		char c;
		cin >> x >> c;
		direction_vector.push_back({ x, c });
	}

	cout << solution();
}