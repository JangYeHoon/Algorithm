// 이것이 취업을 위한 코딩테스트다 351p
// https://www.acmicpc.net/problem/18428
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char matrix[7][7];
int N;
vector<pair<int, int>> space;
vector<pair<int, int>> teacher;
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

bool dfs(int x, int y, int idx)
{
	if (matrix[x][y] == 'S')
		return true;
	else if (matrix[x][y] == 'O')
		return false;
	int nx = x + mx[idx];
	int ny = y + my[idx];
	if (nx >= 0 && nx < N && ny >= 0 && ny < N)
		return dfs(nx, ny, idx);
	else
		return false;
}

bool teacher_check()
{
	for (int i = 0; i < teacher.size(); i++)
		for (int j = 0; j < 4; j++)
			if (dfs(teacher[i].first, teacher[i].second, j))
				return false;
	return true;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 'T')
				teacher.push_back({ i, j });
			else if (matrix[i][j] == 'X')
				space.push_back({ i, j });
		}
	}

	vector<bool> space_chk(space.size());
	fill(space_chk.end() - 3, space_chk.end(), true);

	bool result_chk = false;
	do {
		for (int i = 0; i < space.size(); i++)
			if (space_chk[i])
				matrix[space[i].first][space[i].second] = 'O';
		if (teacher_check()) {
			result_chk = true;
			cout << "YES";
			break;
		}
		for (int i = 0; i < space.size(); i++)
			if (space_chk[i])
				matrix[space[i].first][space[i].second] = 'X';
	} while (next_permutation(space_chk.begin(), space_chk.end()));
	if (!result_chk)
		cout << "NO";
}