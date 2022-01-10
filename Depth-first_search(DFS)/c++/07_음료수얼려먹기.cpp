// 음료수 얼려 먹기
// 입력 : 얼음틀 세로 N, 가로 M ( 1 <= N, M <= 1000)
//		  N+1번째 줄까지 얼음 틀의 형태, 0이 구멍, 1이 막힌 부분
// 출력 : 한 번에 만들 수 있는 아이스크림 개수

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