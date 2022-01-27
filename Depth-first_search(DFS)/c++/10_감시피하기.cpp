// 이것이 취업을 위한 코딩테스트다 351p
// https://www.acmicpc.net/problem/18428
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char matrix[7][7];
int n;
vector<pair<int, int>> teacher;
vector<pair<int, int>> spaces;

bool watch(int x, int y, int d)
{
	if (d == 0)
	{
		while (y >= 0)
		{
			if (matrix[x][y] == 'S')
				return true;
			if (matrix[x][y] == 'O')
				return false;
			y -= 1;
		}
	}
	if (d == 1)
	{
		while (y < n)
		{
			if (matrix[x][y] == 'S')
				return true;
			if (matrix[x][y] == 'O')
				return false;
			y += 1;
		}
	}
	if (d == 2)
	{
		while (x >= 0)
		{
			if (matrix[x][y] == 'S')
				return true;
			if (matrix[x][y] == 'O')
				return false;
			x -= 1;
		}
	}
	if (d == 3)
	{
		while (x < n)
		{
			if (matrix[x][y] == 'S')
				return true;
			if (matrix[x][y] == 'O')
				return false;
			x += 1;
		}
	}
	return false;
}

bool check_f()
{
	for (int i = 0; i < teacher.size(); i++)
	{
		int x = teacher[i].first;
		int y = teacher[i].second;
		for (int i = 0; i < 4; i++)
			if (watch(x, y, i))
				return true;
	}
	return false;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			matrix[i][j] = c;
			if (c == 'T')
				teacher.push_back({ i, j });
			if (c == 'X')
				spaces.push_back({ i, j });
		}
	}

	vector<bool> check(spaces.size());
	fill(check.end() - 3, check.end(), true);
	bool result = false;
	do{
		for (int i = 0; i < spaces.size(); i++)
		{
			if (check[i])
			{
				int x = spaces[i].first;
				int y = spaces[i].second;
				matrix[x][y] = 'O';
			}
		}

		if (!check_f())
		{
			result = true;
			break;
		}

		for (int i = 0; i < spaces.size(); i++)
		{
			if (check[i])
			{
				int x = spaces[i].first;
				int y = spaces[i].second;
				matrix[x][y] = 'X';
			}
		}
	} while (next_permutation(check.begin(), check.end()));
	if (result)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}