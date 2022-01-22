// 이것이 취업을 위한 코딩테스트다 149p
// 
// 2

#include <iostream>
using namespace std;

int ice[1000][1000];
int n, m;

bool dfs(int x, int y)
{
	if (x <= -1 || x >= n || y <= -1 || y >= m)
		return false;

	if (ice[x][y] == 0)
	{
		ice[x][y] = 1;
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &ice[i][j]);
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dfs)
				result++;
		}
	}

	cout << result << '\n';
	return 0;
}