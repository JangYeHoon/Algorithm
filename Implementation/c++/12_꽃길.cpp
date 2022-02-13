// fast campus 강의
// https://www.acmicpc.net/problem/14620
// 1

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, matrix[11][11];
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

int flower_chk(vector<int> pos)
{
	int ret = 0;
	set<int> s;

	for (auto p : pos) {
		int x = p / N, y = p % N;
		ret += matrix[x][y];
		s.insert(p);

		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i], ny = y + my[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				return 4000;
			ret += matrix[nx][ny];
			s.insert(nx * N + ny);
		}
	}

	if (s.size() != 15)
		return 4000;
	return ret;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	int result = 4000;
	for (int i = 0; i < N * N; i++) {
		for (int j = i + 1; j < N * N; j++) {
			for (int k = j + 1; k < N * N; k++) {
				vector<int> pos = { i, j, k };
				result = min(flower_chk(pos), result);
			}
		}
	}
	cout << result;
}